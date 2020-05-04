/**
  ******************************************************************************
  * @file	  			ellipse.h
  *
  * @author 			Wouter Berghuis
  * @date 				1 mei 2020
  * @brief        		This file contains all the needed defines for the
  * 					ellipse drawing functions.
  ******************************************************************************
**/

#ifndef __ELLIPSE_H
#define __ELLIPSE_H

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "VGA_Core.h"
#include "line.h"

/**
  * @brief Error codes for the rectangle drawing functions
  */
typedef enum{
	DRAW_ELLIPSE_SUCCESS = 0, 			/**< No error occurred during drawing of ellipse								*/
	DRAW_ELLIPSE_FAILED,				/**< Error occurred during drawing of ellipse 									*/
	ERROR_ELLIPSE_POSITION_X_COOR,		/**< Error horizontal line position, placed to far left or right		 		*/
	ERROR_ELLIPSE_POSITION_Y_COOR,		/**< Error vertical line position, placed to far top or bottom 					*/
	CORRECT_ELLIPSE_POSITION,			/**< Position off the ellipse is correct, fits on the screen					*/
	CALCULATE_POINT_ON_ELLIPSE_SUCCESS, /**< No error occurred during calculation of the individual point on ellipse	*/
	ERROR_PLACEMENT_INDIVIDUAL_LINE,	/**< Error occurred during placement of a filling line							*/
	ELLIPSE_LINE_PLACEMENT_SUCCESS		/**< No error occurred during placement of a filling line						*/
}ELLIPSE_ERROR_CODES;

#define FILLING_LINE_OFFSET	 1
#define FILLING_LINE_SIZE	 1

/**
  *@brief This In-Line function will square a received number
  */
#define __Square_Number(number) (number * number)

/**
  * @brief Draw ellipse functions
  */
ELLIPSE_ERROR_CODES API_Draw_Ellipse				(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height, uint8_t color);
ELLIPSE_ERROR_CODES API_Check_Ellipse_Position		(uint16_t x_coor, uint16_t y_coor, uint16_t width, uint16_t height);
ELLIPSE_ERROR_CODES API_Calculate_Point_On_Ellipse	(uint16_t x_coor_center, uint16_t y_coor_center, float width, float height, uint16_t x_coor_ellipse, uint16_t *y_coor_ellipse);
ELLIPSE_ERROR_CODES API_Draw_Ellipse_Line			(uint16_t x_coor, uint16_t x_coor_center, uint16_t y_coor_one, uint16_t y_coor_two, uint8_t color);
bool				API_Check_Jump_in_Y_Coor		(uint16_t new_y_coor, uint16_t old_y_coor);

#endif // __ELLIPSE_H
