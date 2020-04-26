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
	DRAW_BITMAP_SUCCESS = 0,			/**< No errors occurred during bitmap placement 							*/
	DRAW_BITMAP_FAILED,					/**< Error occurred during drawing of the bitmap 							*/
	ERROR_BITMAP_NUMBER_UNAVAILABLE,	/**< Received bitmap number doesn't exist 									*/
	CORRECT_BITMAP_PLACEMENT,			/**< Received position of the bitmap is available, fits on the screen 		*/
	EROR_BITMAP_PLACEMENT_RIGHT,		/**< Received position of bitmap unavailable, too far right for the screen 	*/
	ERROR_BITMAP_PLACEMENT_LEFT,		/**< Received position of bitmap unavailable, too far left for the screen	*/
	ERROR_BITMAP_PLACEMENT_TOP,			/**< Received position of bitmap unavailable, too high for the screen 		*/
	ERROR_BITMAP_PLACEMENT_BOT,			/**< Received position of bitmap unavailable, to0 low for  on the screen 	*/
	RAM_FILLED_WITH_BITMAP				/**< RAM is successfully filled with the received bitmap 					*/
}LINE_ERROR_CODES;

/*
 * FUNCTIONS
 */
LINE_ERROR_CODES API_Draw_Line(uint16_t x_coor1, uint16_t y_coor1, uint16_t x_coor2, uint16_t y_coor2, char kleur[MAX_COMMANDWORD_SIZE], uint16_t dikte);

#endif /* LINE_H_ */
