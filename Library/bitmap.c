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
	uint8_t *Pbitmap;
	uint32_t bitmap_size;
	BITMAP_ERROR_CODES error;

	switch(bitmap_nr){
	case(0):	//HAPPY SMILEY
		bitmap_w 	= SMILEY_HAPPY_WIDTH;
		bitmap_h 	= SMILEY_HAPPY_HEIGHT;
		bitmap_size = SMILEY_HAPPY_WIDTH * SMILEY_HAPPY_HEIGHT;
		Pbitmap 	= smiley_happy;

		error = API_Check_Bitmap_Position(x_coor, y_coor, bitmap_w, bitmap_h);
		if(error != CORRECT_BITMAP_PLACEMENT)
			return error;

		error = API_Write_Bitmap_to_VGA(x_coor, y_coor, bitmap_w, bitmap_h, bitmap_size, Pbitmap);
		break;

	case(1): 	//ANGRY SMILEY
		bitmap_w 	= SMILEY_ANGRY_WIDTH;
		bitmap_h 	= SMILEY_ANGRY_HEIGHT;
		bitmap_size = SMILEY_ANGRY_WIDTH * SMILEY_ANGRY_HEIGHT;
		Pbitmap 	= smiley_angry;

		error = API_Check_Bitmap_Position(x_coor, y_coor, bitmap_w, bitmap_h);
		if(error != CORRECT_BITMAP_PLACEMENT)
			return error;

		error = API_Write_Bitmap_to_VGA(x_coor, y_coor, bitmap_w, bitmap_h, bitmap_size, Pbitmap);
		break;

	default:
		return ERROR_BITMAP_NUMBER_UNAVAILABLE;
	}
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

BITMAP_ERROR_CODES API_Write_Bitmap_to_VGA(uint16_t x_coor, uint16_t y_coor, uint16_t bitmap_w, uint16_t bitmap_h, uint32_t bitmap_size, uint8_t *Pbitmap)
{
	for(uint16_t i = y_coor; i < (bitmap_h + y_coor); i++){
		for(uint16_t j = x_coor; j < (bitmap_w + x_coor); j++){
			UB_VGA_SetPixel(j, i, *Pbitmap++);
		}
	}
}
