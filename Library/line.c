/**
  ******************************************************************************
  * @file	  			line.c
  *
  * @author 			Stijn Keller
  * @date 				26 April 2020
  * @brief        		This file contains the API-function for drawing a line
  *
  ******************************************************************************
**/

#include "line.h"

/**
  * @brief	This function is used for drawing a line on the VGA screen.
  *
  * A line will be drawn between 2 given coordinates, the width and the color
  * The coordinates will be checked if they fit on the screen.
  *
  *
  * @param	x_coor1 This the x-coordinate for the line, (uint16_t)
  * @param  y_coor1 This the y-coordinate for the line, (uint16_t)
  * @param	x_coor2 This the 2nd x-coordinate for the line, (uint16_t)
  * @param  y_coor2 This the 2nd y-coordinate for the line, (uint16_t)
  * @param  kleur 	This is the color of the line 		, (char)
  * @param  dikte   This is the width of the line		, (uint16_t)
  * @retval	LINE_ERROR_CODES
  *
  * @see LINE_ERROR_CODES
  */
LINE_ERROR_CODES API_Draw_Line(uint16_t x_coor1, uint16_t y_coor1, uint16_t x_coor2, uint16_t y_coor2, uint8_t kleur, uint16_t dikte)
{
	LINE_ERROR_CODES error_line;

	error_line = API_Check_LineCoords(x_coor1, y_coor1, x_coor2, y_coor2);
	if(error_line != CORRECT_LINE_PLACEMENT)
		return error_line;

	error_line = API_Write_Line(x_coor1, y_coor1, x_coor2, y_coor2, kleur, dikte);
	return error_line;
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
  * Firstly the width is checked if it is even or uneven. This is checked because that has effect on the placement of the line.
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
LINE_ERROR_CODES API_Write_Line(uint16_t x_coor1, uint16_t y_coor1, uint16_t x_coor2, uint16_t y_coor2, uint8_t kleur, uint16_t dikte)
{
	LINE_ERROR_CODES error;
	int sdx,sdy;
	float offset;
	float slope; 								//richtingscoëfficient van de lijn
	float dxabs, dyabs;
	float dy = y_coor2 - y_coor1;
	float dx = x_coor2 - x_coor1;
	sdx = sgn(dx);
	sdy = sgn(dy);
	dxabs = abs(dx);
	dyabs = abs(dy);

	float Even = Even_or_Uneven(dikte);

	if(Even == 1)
	{
		offset = 0.5;
			if(dxabs >= dyabs){								//More horizontal than vertical
				slope = dy/dx;
				error = API_Write_Line_to_VGA_Horizontal(slope, dx, dy, offset, dikte, sdx, x_coor1, y_coor1, kleur);
			}
			if (dyabs >= dxabs){							// More vertical than horizontal
				slope = dx/dy;
				error = API_Write_Line_to_VGA_Vertical(slope, dxabs, dy, offset, dikte, sdy, x_coor1, y_coor1, kleur);
			}
	}
	else if(Even == 0)
	{
		offset = 0;
			if(dxabs >= dyabs){								//More horizontal than vertical
				slope = dy/dx;
				dikte = dikte + 1;
				error = API_Write_Line_to_VGA_Horizontal(slope, dx, dy, offset, dikte, sdx, x_coor1, y_coor1, kleur);
			}
			if(dyabs >= dxabs){								// More vertical than horizontal
				slope = dx/dy;
				error = API_Write_Line_to_VGA_Vertical(slope, dxabs, dy, offset, dikte, sdy, x_coor1, y_coor1, kleur);
			}
	}
	return error;
}

/**
  * @brief	This function is used for drawing a line on the VGA-screen that is more horizontal than vertical.
  *
  * Because
  *
  * The width of the line is created by reusing the formula of the line and shifting it by 1 pixel per extra width
  *
  * @param	sloap  This is the sloap of the line, (float)
  * @param  dx  This is the difference between x_coor1 and x_coor2, (float)
  * @param	dy  This is the difference between y_coor1 and y_coor2, (float)
  * @param  offset  This is the offset which is used for creating the width of the line, (float)
  * @param  width  This is the width of the line, (uint16_t)
  * @param  sdx  This is the signed value of dx (1 or -1), (int)
  * @param  x_coor1  This is the x-coordinate of the first coordinate, (uint16_t)
  * @param  y_coor1 This is the y-coordinate of the first coordinate, (uint16_t)
  * @param  Colour  This is the colour of the line, (uint8_t)
  *
  * @retval	LINE_ERROR_CODES
  *
  * @see LINE_ERROR_CODES
  */
LINE_ERROR_CODES API_Write_Line_to_VGA_Horizontal(float slope, float dx, float dy, float offset, uint16_t width, int sdx, uint16_t x_coor1, uint16_t y_coor1, uint8_t Colour){
	float x_temp, y_temp;
	int i,k;
	uint16_t x,y;
	for(i = 0; i != dx; i+=sdx){						//More horizontal than vertical
		for(k = 0; k < width/2; k++)
		{
			x_temp = i + x_coor1;
			y_temp = slope * i + y_coor1 + offset + k;
		    x = Round_Float_to_Int(x_temp);
			y = Round_Float_to_Int(y_temp);
			API_SetPixel(x, y, Colour);

			x_temp = i + x_coor1;
			y_temp = slope * i + y_coor1 - offset - k;
			x = Round_Float_to_Int(x_temp);
			y = Round_Float_to_Int(y_temp);
			API_SetPixel(x, y, Colour);
		}
	}
	return LINE_ON_VGA_SUCCESS;
}

/**
  * @brief	This function is used for drawing a line on the VGA-screen that is more vertical than horizontal.
  *
  * Because
  *
  * The width of the line is created by reusing the formula of the line and shifting it by 1 pixel per extra width
  *
  * @param	sloap  This is the sloap of the line, (float)
  * @param  dxabs  This is the absolute difference between x_coor1 and x_coor2, (float)
  * @param	dy  This is the difference between y_coor1 and y_coor2, (float)
  * @param  offset  This is the offset which is used for creating the width of the line, (float)
  * @param  width  This is the width of the line, (uint16_t)
  * @param  sdy  This is the signed value of dy (1 or -1), (int)
  * @param  x_coor1  This is the x-coordinate of the first coordinate, (uint16_t)
  * @param  y_coor1 This is the y-coordinate of the first coordinate, (uint16_t)
  * @param  Colour  This is the colour of the line, (uint8_t)
  *
  * @retval	LINE_ERROR_CODES
  *
  * @see LINE_ERROR_CODES
  */
LINE_ERROR_CODES API_Write_Line_to_VGA_Vertical(float slope, float dxabs, float dy, float offset, uint16_t width, int sdy, uint16_t x_coor1, uint16_t y_coor1, uint8_t Colour){
	float x_temp, y_temp;
	int i,k;
	uint16_t x,y;
	for(i = 0; i != dy; i+=sdy){
		for(k = 0; k <= (width-1)/2; k++)
		{
			y_temp = i + y_coor1 ;
			x_temp = slope * i + x_coor1 + offset + k;
			x = Round_Float_to_Int(x_temp);
			y = Round_Float_to_Int(y_temp);
			API_SetPixel(x, y, Colour);

			y_temp = i + y_coor1 ;
			x_temp = slope * i + x_coor1 - offset - k;
			x = Round_Float_to_Int(x_temp);
			y = Round_Float_to_Int(y_temp);
			API_SetPixel(x, y, Colour);
		}
	}
	return LINE_ON_VGA_SUCCESS;
}

/**
  * @brief	This function is used for rounding a float to an integer
  *
  * @param	The float that will be rounded up  (float)
  * @retval int
  */
int Round_Float_to_Int(float num)
{
    return num < 0 ? num - 0.5 : num + 0.5;
}

/**
  * @brief	This function is used to check if a value is divisible by 2
  *
  * @param	The variable that will be checked  (uint16_t)
  * @retval int
  */
int Even_or_Uneven(uint16_t data)
{
	int var;
	if(data % 2 == 0)
	{
		var = 1;
	}
	else
	{
		var = 0;
	}
	return var;
}

/**
  * @brief	This function is used to check if a variable is bigger or smaller than 0
  *
  * @param	The variable that will be checked  (int)
  * @retval int
  */
int sgn(int v)
{
	if (v < 0) return -1;
	if (v > 0) return 1;
	return 0;
}
