/**
  ******************************************************************************
  * @file	  			cube.h
  *
  * @author 			Wouter Berghuis
  * @date 				5 Mei 2020
  * @brief        		This file contains all the needed defines for the
  * 					cube drawing functions.
  ******************************************************************************
**/

#ifndef __CUBE_H
#define __CUBE_H

#include <stdio.h>
#include "rectangle.h"
#include "line.h"
#include "VGA_core.h"

#define NO_FILL 		0

/**
  * @brief Error codes for the cube drawing functions
  */
typedef enum{
	DRAW_CUBE_SUCCESS = 0,
	DRAW_CUBE_FAILED,
	ERROR_CUBE_PLACEMENT_X_AXIS,
	ERROR_CUBE_PLACEMENT_Y_AXIS,
	CORRECT_CUBE_PLACEMENT,
	ERROR_DRAW_SINGLE_RECTANGLE,
	ERROR_DRAW_CONNECTING_LINE
}CUBE_ERROR_CODES;

CUBE_ERROR_CODES API_Draw_Cube			(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height, uint16_t depth, uint8_t color);
CUBE_ERROR_CODES API_Write_Cube_to_VGA	(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height, uint16_t depth, uint8_t color);
CUBE_ERROR_CODES API_Check_Cube_Position(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height, uint16_t depth);

#endif //__CUBE_H
