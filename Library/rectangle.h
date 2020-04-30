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

typedef enum{
	DRAW_RECTANGLE_SUCCESS = 0,
	DRAW_RECTANGLE_FAILED,
	ERROR_POSITION_X_COOR,
	ERROR_POSITION_Y_COOR,
	CORRECT_RECTANGLE_POSITION
}RECTANGLE_ERROR_CODES;

RECTANGLE_ERROR_CODES API_Draw_Rectangle			(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height, uint8_t color, uint8_t filled);
RECTANGLE_ERROR_CODES API_Check_Rectangle_Position	(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height);

#endif //__RECTANGLE_H
