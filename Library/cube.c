/**
  ******************************************************************************
  * @file	  			cube.c
  *
  * @author 			Wouter Berghuis
  * @date 				5 Mei 2020
  * @brief        		This file contains the API-function for drawing a
  * 					cube on the screen
  *
  ******************************************************************************
**/

#include "cube.h"

/**
  * @brief	This function draws a cube on the VGA screen
  *
  * Drawing a cube on the VGA screen consist of the following steps:
  * 1. Check the position of the cube
  * 	If it doesn't fit on the screen an error message is returned
  * 2. Write the cube data to the VGA screen
  * 	2.1 Draw the two rectangles (front and back)
  * 	2.2 Draw the four lines to connect the 2 rectangles
  *
  * @param	x_coor This is the x-coordinate of the cube, this will be the top-left of the front rectangle,  (uint16_t)
  * @param  y_coor This is the y-coordinate of the cube, this will be the top-left of the front rectangle, 	(uint16_t)
  * @param	width  This is width of the cube, 																(uint16_t)
  * @param  height This is height of the cube, 																(uint16_t)
  * @param  depth  This is depth of the cube, 																(uint16_t)
  * @param  color  The color of the cube, 																	(uint8_t)
  *
  * @retval	CUBE_ERROR_CODES
  *
  * @see CUBE_ERROR_CODES
  */
CUBE_ERROR_CODES API_Draw_Cube(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height, uint16_t depth, uint8_t color){

	CUBE_ERROR_CODES error = 0;
	error = API_Check_Cube_Position(x_coor, y_coor, width, height, depth);
	if(error != CORRECT_CUBE_PLACEMENT)
		return error;

	error = API_Write_Cube_to_VGA(x_coor, y_coor, width, height, depth, color);
	if(error != DRAW_CUBE_SUCCESS)
		return error;

	return DRAW_CUBE_SUCCESS;
}

/**
  * @brief	This function checks if the cube fits on the VGA-screen
  *
  * The check consist of the following four different small checks:
  * 1. Cube placed off screen to the left
  * 2. Cube placed off screen to the right
  * 3. Cube placed too high
  * 4. Cube placed too low
  *
  * @param	x_coor This is the x-coordinate of the cube, this will be the top-left of the front rectangle,  (uint16_t)
  * @param  y_coor This is the y-coordinate of the cube, this will be the top-left of the front rectangle, 	(uint16_t)
  * @param	width  This is width of the cube, 																(uint16_t)
  * @param  height This is height of the cube, 																(uint16_t)
  * @param  depth  This is depth of the cube, 																(uint16_t)																(uint8_t)
  *
  * @retval	CUBE_ERROR_CODES
  *
  * @see CUBE_ERROR_CODES
  */
CUBE_ERROR_CODES API_Check_Cube_Position(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height, uint16_t depth){
	if(x_coor < 0 || x_coor + width + depth > VGA_DISPLAY_X)
		return ERROR_CUBE_PLACEMENT_X_AXIS;

	if((y_coor - depth) < 0 || y_coor + height > VGA_DISPLAY_Y)
		return ERROR_CUBE_PLACEMENT_Y_AXIS;

	return CORRECT_CUBE_PLACEMENT;
}

/**
  * @brief	This function writes the cube pixel-data to the VGA RAM
  *
  * For this process the function uses the following two API function:
  * - API_Draw_Line(), For the front and back rectangles.
  * - API_Draw_Rectangle(), For the four connecting lines.
  *
  * @param	x_coor This is the x-coordinate of the cube, this will be the top-left of the front rectangle,  (uint16_t)
  * @param  y_coor This is the y-coordinate of the cube, this will be the top-left of the front rectangle, 	(uint16_t)
  * @param	width  This is width of the cube, 																(uint16_t)
  * @param  height This is height of the cube, 																(uint16_t)
  * @param  depth  This is depth of the cube, 																(uint16_t)
  * @param  color  The color of the cube, 																	(uint8_t)
  *
  * @retval	CUBE_ERROR_CODES
  *
  * @see CUBE_ERROR_CODES
  */
CUBE_ERROR_CODES API_Write_Cube_to_VGA(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height, uint16_t depth, uint8_t color){

	RECTANGLE_ERROR_CODES Rectangel_errors = 0;
	LINE_ERROR_CODES	  Line_errors	   = 0;

	// Draw the back and front rectangle
	Rectangel_errors = API_Draw_Rectangle(x_coor, y_coor, width, height, color, NO_FILL);
	Rectangel_errors = API_Draw_Rectangle((x_coor + depth), (y_coor - depth), width, height, color, NO_FILL);
	if(Rectangel_errors != DRAW_RECTANGLE_SUCCESS)
		return ERROR_DRAW_SINGLE_RECTANGLE;

	// Draw connecting lines
	Line_errors |= API_Draw_Line( x_coor,          y_coor,          (x_coor + depth),         (y_coor - depth),          color, LINE_THICKNESS);
	Line_errors |= API_Draw_Line((x_coor + width), y_coor,          (x_coor + width + depth), (y_coor - depth),          color, LINE_THICKNESS);
	Line_errors |= API_Draw_Line( x_coor,         (y_coor + height),(x_coor + depth),         (y_coor - depth + height), color, LINE_THICKNESS);
	Line_errors |= API_Draw_Line((x_coor + width),(y_coor + height),(x_coor + width + depth), (y_coor - depth + height), color, LINE_THICKNESS);
	if(Line_errors != CORRECT_LINE_PLACEMENT)
		return ERROR_DRAW_CONNECTING_LINE;

	return DRAW_CUBE_SUCCESS;
}
