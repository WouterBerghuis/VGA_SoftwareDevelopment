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
#include "command_check.h"
#include <stdio.h>
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
	LINE_ERROR_CODES error;

	error = API_Check_LineCoords(x_coor1, y_coor1, x_coor2, y_coor2);
	if(error != CORRECT_LINE_PLACEMENT)
		return error;

	error = API_Write_Line_to_VGA(x_coor1, y_coor1, x_coor2, y_coor2, kleur, dikte);
	return error;
}

/**
  * @brief	This function is used for checking the coordinates of the sent data
  *
  * @param	x_coor1 This is the first x-coordinate for the line,  (uint16_t)
  * @param  y_coor1 This is the first y-coordinate for the line,  (uint16_t)
  * @param	x_coor2 This is the second x-coordinate for the line, (uint16_t)
  * @param  y_coor2 This is the second y-coordinate for the line, (uint16_t)
  * @retval	LINE_ERROR_CODES
  *
  * @see LINE_ERROR_CODES
  */

LINE_ERROR_CODES API_Check_LineCoords(uint16_t x_coor1, uint16_t y_coor1, uint16_t x_coor2, uint16_t y_coor2)
{
	if(VGA_DISPLAY_X < x_coor1 && x_coor1 < 0)
		return ERROR_LINE_PLACEMENT_XCOOR1;

	if(VGA_DISPLAY_X < y_coor1 && y_coor1 < 0)
		return ERROR_LINE_PLACEMENT_XCOOR2;

	if(VGA_DISPLAY_Y < x_coor2 && x_coor2 < 0)
		return ERROR_LINE_PLACEMENT_YCOOR1;

	if(VGA_DISPLAY_Y < y_coor2 && y_coor2 < 0)
		return ERROR_LINE_PLACEMENT_YCOOR2;
	return CORRECT_LINE_PLACEMENT;
}

/**
  * @brief	This function is used for writing the line on the VGA
  *
  * @param	x_coor1 This is the first x-coordinate for the line,  (uint16_t)
  * @param  y_coor1 This is the first y-coordinate for the line,  (uint16_t)
  * @param	x_coor2 This is the second x-coordinate for the line, (uint16_t)
  * @param  y_coor2 This is the second y-coordinate for the line, (uint16_t)
  * @param  kleur 	This is the color of the line 		, (char)
  * @param  dikte   This is the width of the line		, (uint16_t)
  * @retval	LINE_ERROR_CODES
  *
  * @see LINE_ERROR_CODES
  */

LINE_ERROR_CODES API_Write_Line_to_VGA(uint16_t x_coor1, uint16_t y_coor1, uint16_t x_coor2, uint16_t y_coor2, char kleur[MAX_COMMANDWORD_SIZE], uint16_t dikte)
{
	LINE_ERROR_CODES error;
	uint16_t i,j;
	float slope;				//hellingsgraad van de lijn
	float y_temp;
	float dy = y_coor2 - y_coor1;
	float dx = x_coor2 - x_coor1;
	slope = dy/dx;

	if(x_coor1 < x_coor2){
		for(i = x_coor1; i < x_coor2; i++){
		y_temp = slope * i + y_coor1;
		j = Round_Float_to_Int(y_temp);
		API_SetPixel(i, j, *kleur);
		}

	}
	else
		for(i = x_coor1; i > x_coor2; i--){
			y_temp = slope * i + y_coor2;
			j = Round_Float_to_Int(y_temp);
			API_SetPixel(i, j, *kleur);
			}
	return error;
}

int Round_Float_to_Int(float num)
{
    return num < 0 ? num - 0.5 : num + 0.5;
}
