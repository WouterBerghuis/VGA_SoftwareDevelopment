/**
  ******************************************************************************
  * @file	  			bitmap.c
  *
  * @author 			Wouter Berghuis
  * @date 				21 April 2020
  * @brief        		This file contains all API function responsible for
  * 					drawing the different bitmaps. This file uses different
  * 					files, its header file (bitmap.h) and the different saved
  * 					bitmaps files. These are all saved the folder ~/Library/bitmaps
  ******************************************************************************
**/

#include "bitmap.h"

BITMAP_ERROR_CODES API_Draw_Bitmap(uint16_t x_coor, uint16_t y_coor, uint8_t bitmap_nr)
{
	uint16_t bitmap_w;
	uint16_t bitmap_h;
	const uint8_t *Pbitmap;
	uint32_t bitmap_size;
	BITMAP_ERROR_CODES error;

	switch(bitmap_nr){
	case(0):	//HAPPY SMILEY
		bitmap_w 	= SMILEY_HAPPY_WIDTH;
		bitmap_h 	= SMILEY_HAPPY_HEIGHT;
		bitmap_size = SMILEY_HAPPY_WIDTH * SMILEY_HAPPY_HEIGHT;
		Pbitmap 	= smiley_happy;
		break;

	case(1): 	//ANGRY SMILEY
		bitmap_w 	= SMILEY_ANGRY_WIDTH;
		bitmap_h 	= SMILEY_ANGRY_HEIGHT;
		bitmap_size = SMILEY_ANGRY_WIDTH * SMILEY_ANGRY_HEIGHT;
		Pbitmap 	= smiley_angry;
		break;

	case(2):	//ARROW UP
		bitmap_w 	= ARROW_UP_WIDTH;
		bitmap_h 	= ARROW_UP_HEIGHT;
		bitmap_size = ARROW_UP_WIDTH * ARROW_UP_HEIGHT;
		Pbitmap 	= arrow_up;

		break;

	case(3):	//ARROW DOWN
		bitmap_w 	= ARROW_DOWN_WIDTH;
		bitmap_h 	= ARROW_DOWN_HEIGHT;
		bitmap_size = ARROW_DOWN_WIDTH * ARROW_DOWN_HEIGHT;
		Pbitmap 	= arrow_down;
		break;

	case(4):	//ARROW RIGHT
		bitmap_w 	= ARROW_RIGHT_WIDTH;
		bitmap_h 	= ARROW_RIGHT_HEIGHT;
		bitmap_size = ARROW_RIGHT_WIDTH * ARROW_RIGHT_HEIGHT;
		Pbitmap 	= arrow_right;
		break;

	case(5):	//ARROW LEFT
		bitmap_w 	= ARROW_LEFT_WIDTH;
		bitmap_h 	= ARROW_LEFT_HEIGHT;
		bitmap_size = ARROW_LEFT_WIDTH * ARROW_LEFT_HEIGHT;
		Pbitmap 	= arrow_left;
		break;

	default:
		return ERROR_BITMAP_NUMBER_UNAVAILABLE;
	}

	error = API_Check_Bitmap_Position(x_coor, y_coor, bitmap_w, bitmap_h);
	if(error != CORRECT_BITMAP_PLACEMENT)
		return error;

	error = API_Write_Bitmap_to_VGA(x_coor, y_coor, bitmap_w, bitmap_h, bitmap_size, Pbitmap);
	if(error == RAM_FILLED_WITH_BITMAP)
		return DRAW_BITMAP_SUCCESS;
	else
		return DRAW_BITMAP_FAILED;
}

BITMAP_ERROR_CODES API_Check_Bitmap_Position(uint16_t x_coor, uint16_t y_coor, uint16_t bitmap_w, uint16_t bitmap_h)
{
	if((x_coor + bitmap_w) > VGA_DISPLAY_X)
		return EROR_BITMAP_PLACEMENT_RIGHT;

	if(x_coor < 0)
		return ERROR_BITMAP_PLACEMENT_LEFT;

	if((y_coor + bitmap_h) > VGA_DISPLAY_Y)
		return ERROR_BITMAP_PLACEMENT_BOT;

	if(y_coor < 0)
		return ERROR_BITMAP_PLACEMENT_TOP;

	return CORRECT_BITMAP_PLACEMENT;
}

BITMAP_ERROR_CODES API_Write_Bitmap_to_VGA(uint16_t x_coor, uint16_t y_coor, uint16_t bitmap_w, uint16_t bitmap_h, uint32_t bitmap_size, const uint8_t *Pbitmap)
{
	for(uint16_t i = y_coor; i < (bitmap_h + y_coor); i++){
		for(uint16_t j = x_coor; j < (bitmap_w + x_coor); j++){
			UB_VGA_SetPixel(j, i, *Pbitmap++);
		}
	}
	return RAM_FILLED_WITH_BITMAP;
}
