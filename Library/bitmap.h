/**
  ******************************************************************************
  * @file	  			bitmap.h
  *
  * @author 			Wouter Berghuis
  * @date 				21 April 2020
  * @brief        		This file is the headerfile of bitmap.c
  ******************************************************************************
**/

#ifndef __BITMAP_H
#define __BITMAP_H

/*
 * DEFINES
 */
#define TRANSPARENT_PIXEL 	256

/*
 * LIBRARY AND HEADER-FILES INCLUDES
 */
#include "stm32_ub_vga_screen.h"
#include "smiley_happy.h"
#include "smiley_angry.h"
#include "arrows.h"

/*
 * ENUMERATIONS
 */
typedef enum{
	DRAW_BITMAP_SUCCESS = 0,			//No errors occurred during bitmap placement
	DRAW_BITMAP_FAILED,					//Error occurred during drawing of the bitmap
	ERROR_BITMAP_NUMBER_UNAVAILABLE,	//Received bitmap number doesn't exist
	CORRECT_BITMAP_PLACEMENT,			//Received position of the bitmap is available, fits on the screen
	EROR_BITMAP_PLACEMENT_RIGHT,		//Received position of bitmap unavailable, too far right for the screen
	ERROR_BITMAP_PLACEMENT_LEFT,		//Received position of bitmap unavailable, too far left for the screen
	ERROR_BITMAP_PLACEMENT_TOP,			//Received position of bitmap unavailable, too high for the screen
	ERROR_BITMAP_PLACEMENT_BOT,			//Received position of bitmap unavailable, to0 low for  on the screen
	RAM_FILLED_WITH_BITMAP				//RAM is successfully filled with the received bitmap
}BITMAP_ERROR_CODES;

/*
 * FUNCTIONS
 */
BITMAP_ERROR_CODES API_Draw_Bitmap			(uint16_t x_coor, uint16_t y_coor, uint8_t bitmap_nr);
BITMAP_ERROR_CODES API_Check_Bitmap_Position(uint16_t x_coor, uint16_t y_coor, uint16_t bitmap_w, uint16_t bitmap_h);
BITMAP_ERROR_CODES API_Write_Bitmap_to_VGA	(uint16_t x_coor, uint16_t y_coor, uint16_t bitmap_w, uint16_t bitmap_h, uint32_t bitmap_size, const uint8_t *Pbitmap);

#endif //__BITMAP_H
