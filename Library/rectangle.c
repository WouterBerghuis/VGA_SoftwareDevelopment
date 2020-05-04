/**
  ******************************************************************************
  * @file	  			rectangle.c
  *
  * @author 			Wouter Berghuis
  * @date 				30 April 2020
  * @brief        		This file contains all API function responsible for drawing a
  * 					rectangle on the screen.
  *
  ******************************************************************************
  **/

#include "rectangle.h"

/**
  * @brief	This function is used for drawing a rectangle on the VGA screen.
  *
  * Drawing the rectangle on the screen consist of the following steps:
  * 1. Check the received coordinates of the rectangle.
  * 	 Does the rectangle fit on the screen or is the size too big
  * 	 for the chosen position.
  *	2. Write the rectangle pixel data to the VGA RAM
  *	     This is done with the use of the API_Draw_Line function
  *	3. Fill the inside of the rectangle if @param filled is equal to one
  *		 This is done by setting the pixels within the rectangle corners
  *		 to @param color.
  *
  * @param	x_coor This is the x-coordinate for the rectangle, (uint16_t)
  * @param  y_coor This is the y-coordinate for the rectangle, (uint16_t)
  * @param  width  This is the width of the rectangle, (uint16_t)
  * @param  height This is the height of the rectangle, (uint16_t)
  * @param  color  This is the color with which the rectangle is drawn, (uint8_t)
  * @param  filled 0 = Not filled | 1 = Filled, if filled the inside of the
  * 				rectangle will be filled with @param color, (uint8_t)
  *
  * @retval	RECTANGLE_ERROR_CODES
  *
  * @see RECTANGLE_ERROR_CODES
  */
RECTANGLE_ERROR_CODES API_Draw_Rectangle(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height, uint8_t color,
										 uint8_t filled){
	RECTANGLE_ERROR_CODES error = 0;
	error = API_Check_Rectangle_Position(x_coor, y_coor, width, height);
	if(error != CORRECT_RECTANGLE_POSITION)
		return error;

	error = API_Write_Rectangle_to_VGA(x_coor, y_coor, width, height, color);
	if(error != DRAW_RECTANGLE_SUCCESS)
		return error;

	if(filled){
		error = API_Fill_Rectangle(x_coor, y_coor, width, height, color);
		if(error != FILL_RECTANGLE_SUCCESS)
			return error;
	}

	return DRAW_RECTANGLE_SUCCESS;
}

/**
  * @brief	This function is used to check if the received rectangle fits on the screen
  *
  * The check consist of checking each corner of the rectangle with the resolution of the VGA screen.
  * If the rectangle does not fit on the screen the function returns an error code.
  *
  * @param	x_coor This is the x-coordinate for the rectangle, (uint16_t)
  * @param  y_coor This is the y-coordinate for the rectangle, (uint16_t)
  * @param  width  This is the width of the rectangle, (uint16_t)
  * @param  height This is the height of the rectangle, (uint16_t)
  *
  * @retval	RECTANGLE_ERROR_CODES
  *
  * @see RECTANGLE_ERROR_CODES
  */
RECTANGLE_ERROR_CODES API_Check_Rectangle_Position(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height){
	// Check X coordinates
	if(x_coor < 0)							// Rectangle is placed too far to the left
		return ERROR_POSITION_X_COOR;
	if((x_coor + width) > VGA_DISPLAY_X)	// Rectangle is placed too far to the right
		return ERROR_POSITION_X_COOR;

	// Check Y coordinates
	if(y_coor < 0)							// Rectangle is placed too far top
		return ERROR_POSITION_Y_COOR;
	if((y_coor + height) > VGA_DISPLAY_Y)	// Rectangle is placed too far bottom
		return ERROR_POSITION_Y_COOR;

	return CORRECT_RECTANGLE_POSITION;
}

/**
  * @brief	This function writes the rectangle pixel data to the VGA RAM
  *
  * To write the pixel data to the VGA RAM the function is using the API_Draw_Line function.
  * Using this function the four different lines of the rectangle can be drawn.
  *
  * @attention A weird bug which is solved with a hack. The right vertical line misses one pixel. To fix this
  * the line is extended with one pixel.
  *
  * @param	x_coor This is the x-coordinate for the rectangle, (uint16_t)
  * @param  y_coor This is the y-coordinate for the rectangle, (uint16_t)
  * @param  width  This is the width of the rectangle, (uint16_t)
  * @param  height This is the height of the rectangle, (uint16_t)
  * @param  color  This is the color with which the rectangle is drawn, (uint8_t)
  *
  * @retval	RECTANGLE_ERROR_CODES
  *
  * @see RECTANGLE_ERROR_CODES
  */
RECTANGLE_ERROR_CODES API_Write_Rectangle_to_VGA(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height, uint8_t color){
	LINE_ERROR_CODES error;

	// Draw top line
	error = API_Draw_Line(x_coor, y_coor, (x_coor + width), y_coor, color, RECTANGLE_WEIGHT);
	if(error)
		return ERROR_LINE_PLACEMENT;

	// Draw bottom line
	error = API_Draw_Line(x_coor, (y_coor + height), (x_coor + width), (y_coor + height), color, RECTANGLE_WEIGHT);
	if(error)
		return ERROR_LINE_PLACEMENT;

	// Draw Left line
	error = API_Draw_Line(x_coor, y_coor, x_coor, (y_coor + height), color, RECTANGLE_WEIGHT);
	if(error)
		return ERROR_LINE_PLACEMENT;

	// Draw right line
	// Weird bug: Line on the right side must be one pixel longer
	error = API_Draw_Line((x_coor + width), y_coor, (x_coor + width), (y_coor + height + RECTANGLE_LINE_OFFSET_BUG), color, RECTANGLE_WEIGHT);
	if(error)
		return ERROR_LINE_PLACEMENT;

	return DRAW_RECTANGLE_SUCCESS;
}

/**
  * @brief	This function fills the inside of the rectangle with one color
  *
  * Filling the rectangle is done by looping over the individual pixels within the rectangle area.
  * Each individual pixel is set to the @param color.
  *
  *
  * @param	x_coor This is the x-coordinate for the rectangle, (uint16_t)
  * @param  y_coor This is the y-coordinate for the rectangle, (uint16_t)
  * @param  width  This is the width of the rectangle, (uint16_t)
  * @param  height This is the height of the rectangle, (uint16_t)
  * @param  color  This is the color with which the rectangle is drawn, (uint8_t)
  *
  * @retval	RECTANGLE_ERROR_CODES
  *
  * @see RECTANGLE_ERROR_CODES
  */
RECTANGLE_ERROR_CODES API_Fill_Rectangle(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height, uint8_t color){
	VGA_INIT_ERROR_CODES error = 0;
	for(uint16_t i = y_coor; i < (height + y_coor); i++){
		for(uint16_t j = x_coor; j < (width + x_coor); j++){
			error = API_SetPixel(j, i, color);
			if(error != VGA_SETPIXEL_SUCCESS)
				return ERROR_FILL_RECTANGLE;
		}
	}
	return FILL_RECTANGLE_SUCCESS;
}
