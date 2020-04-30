/**
  ******************************************************************************
  * @file	  			rectangle.h
  *
  * @author 			Wouter Berghuis
  * @date 				30 april 2020
  * @brief        		This file contains all the needed defines for the
  * 					rectangle drawing functions.
  ******************************************************************************
**/

#ifndef __RECTANGLE_H
#define __RECTANGLE_H

#include <stdio.h>
#include "line.h"

#define RECTANGLE_WEIGHT 			1
#define RECTANGLE_LINE_OFFSET_BUG 	1 /**< While drawing the most right line of the rectangle a bug shows up, to fix this the line should be one pixel longr */

typedef enum{
	DRAW_RECTANGLE_SUCCESS = 0,
	DRAW_RECTANGLE_FAILED,
	ERROR_POSITION_X_COOR,
	ERROR_POSITION_Y_COOR,
	CORRECT_RECTANGLE_POSITION,
	ERROR_LINE_PLACEMENT,
	ERROR_FILL_RECTANGLE,
	FILL_RECTANGLE_SUCCESS
}RECTANGLE_ERROR_CODES;

RECTANGLE_ERROR_CODES API_Draw_Rectangle			(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height, uint8_t color, uint8_t filled);
RECTANGLE_ERROR_CODES API_Check_Rectangle_Position	(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height);
RECTANGLE_ERROR_CODES API_Write_Rectangle_to_VGA	(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height, uint8_t color);
RECTANGLE_ERROR_CODES API_Fill_Rectangle			(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height, uint8_t color);

#endif //__RECTANGLE_H
