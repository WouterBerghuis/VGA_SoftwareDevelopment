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
	error = API_Check_Rectangle_Position(x_coor, y_coor, width, height)
	if(error != CORRECT_RECTANGLE_POSITION)
		return error;





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
