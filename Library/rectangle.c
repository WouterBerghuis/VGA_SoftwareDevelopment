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

RECTANGLE_ERROR_CODES API_Check_Rectangle_Position(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height){
	// Check X coordinates
	if(x_coor < 0)
		return ERROR_POSITION_X_COOR;
	if((x_coor + width) > VGA_DISPLAY_X)
		return ERROR_POSITION_X_COOR;

	// Check Y coordinates
	if(y_coor < 0)
		return ERROR_POSITION_Y_COOR;
	if((y_coor + height) > VGA_DISPLAY_Y)
		return ERROR_POSITION_Y_COOR;

	return CORRECT_RECTANGLE_POSITION;
}

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

