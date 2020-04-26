/**
  ******************************************************************************
  * @file	  			line.c
  *
  * @author 			Stijn Keller
  * @date 				26 April 2020
  * @brief        		This file contains the API-function to draw a line
  *
  ******************************************************************************
**/

#include "line.h"

/**
  * @brief	This function is used for drawing a line on the VGA screen.
  *
  * @param	x_coor1 This the x-coordinate for the bitmap, (uint16_t)
  * @param  y_coor1 This the y-coordinate for the bitmap, (uint16_t)
  * @param	x_coor2 This the x-coordinate for the bitmap, (uint16_t)
  * @param  y_coor2 This the y-coordinate for the bitmap, (uint16_t)
  * @param  kleur 	This is the color of the line 		, (char)
  * @param  dikte   This is the width of the line		, (uint16_t)
  * @retval	LINE_ERROR_CODES
  *
  * @see LINE_ERROR_CODES
  */

LINE_ERROR_CODES API_Draw_Line(uint16_t x_coor1, uint16_t y_coor1, uint16_t x_coor2, uint16_t y_coor2, char kleur[MAX_COMMANDWORD_SIZE], uint16_t dikte)
{

}
