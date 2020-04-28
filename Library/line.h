/**
  ******************************************************************************
  * @file	  			line.h
  *
  * @author 			Stijn Keller
  * @date 				26 April 2020
  * @brief        		This file contains all API function responsible for drawing the different bitmaps.
  *
  ******************************************************************************
**/

#ifndef LINE_H_
#define LINE_H_

#include "VGA_core.h"

/*
 * @brief 	Returnvalues for the different line functions. These can be used for
 * 			errorhandling.
 *
 */
typedef enum{
	CORRECT_LINE_PLACEMENT= 0,			/**< No errors occurred during bitmap placement 							*/
	ERROR_LINE_PLACEMENT_XCOOR1,		/**< Received position of bitmap unavailable, too far right for the screen 	*/
	ERROR_LINE_PLACEMENT_YCOOR1,		/**< Received position of bitmap unavailable, too far left for the screen	*/
	ERROR_LINE_PLACEMENT_XCOOR2,			/**< Received position of bitmap unavailable, too high for the screen 		*/
	ERROR_LINE_PLACEMENT_YCOOR2,			/**< Received position of bitmap unavailable, to0 low for  on the screen 	*/
}LINE_ERROR_CODES;

/*
 * FUNCTIONS
 */
LINE_ERROR_CODES API_Draw_Line(uint16_t x_coor1, uint16_t y_coor1, uint16_t x_coor2, uint16_t y_coor2, char kleur[MAX_COMMANDWORD_SIZE], uint16_t dikte);
LINE_ERROR_CODES API_Check_LineCoords(uint16_t x_coor1, uint16_t y_coor1, uint16_t x_coor2, uint16_t y_coor2);
LINE_ERROR_CODES API_Write_Line_to_VGA(uint16_t x_coor1, uint16_t y_coor1, uint16_t x_coor2, uint16_t y_coor2, char kleur[MAX_COMMANDWORD_SIZE], uint16_t dikte);
int Round_Float_to_Int(float num);
int Even_or_Uneven(uint16_t data);
int sgn(int v);
#endif /* LINE_H_ */
