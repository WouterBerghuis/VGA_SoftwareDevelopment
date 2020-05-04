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

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "line.h"

/**
  * @brief Defines used for in the different rectangle drawing functions
  */
#define RECTANGLE_WEIGHT 			1
#define RECTANGLE_LINE_OFFSET_BUG 	1 	/**< While drawing the most right line of the rectangle a bug shows up, to fix this the line should be one pixel longer */

/**
  * @brief Error codes for the rectangle drawing functions
  */
typedef enum{
	DRAW_RECTANGLE_SUCCESS = 0, 		/**< No error occurred during drawing of rectangle 					*/
	DRAW_RECTANGLE_FAILED,				/**< Error occurred during drawing of rectangle 					*/
	ERROR_POSITION_X_COOR,				/**< Error horizontal line position, placed to far left or right 	*/
	ERROR_POSITION_Y_COOR,				/**< Error vertical line position, placed to far top or bottom 		*/
	CORRECT_RECTANGLE_POSITION,			/**< Position off the rectangle is correct, fits on the screen		*/
	ERROR_LINE_PLACEMENT,				/**< Error occurred during placing individual line					*/
	ERROR_FILL_RECTANGLE,				/**< Error occurred during filling the rectangle					*/
	FILL_RECTANGLE_SUCCESS				/**< No error occurred during placing individual line					*/
}RECTANGLE_ERROR_CODES;

/**
  * @brief Draw rectangle functions
  */
RECTANGLE_ERROR_CODES API_Draw_Rectangle			(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height, uint8_t color, uint8_t filled);
RECTANGLE_ERROR_CODES API_Check_Rectangle_Position	(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height);
RECTANGLE_ERROR_CODES API_Write_Rectangle_to_VGA	(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height, uint8_t color);
RECTANGLE_ERROR_CODES API_Fill_Rectangle			(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height, uint8_t color);

#endif //__RECTANGLE_H
