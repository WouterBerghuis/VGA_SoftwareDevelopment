/**
  ******************************************************************************
  * @file	  			text.h
  *
  * @author 			Wouter Berghuis
  * @date 				24 april 2020
  * @brief        		This file contains all the needed defines for the
  * 					text-drawing functions.
  ******************************************************************************
**/

#ifndef __TEXT_H
#define __TEXT_H

#include <stdint.h>
#include <string.h>
#include "VGA_core.h"
#include "minecraft.h"
#include "bitmap.h"

#define MAX_SMALL_CHARACTER_WIDTH 	7
#define MAX_BIG_CHARACTER_WIDTH 	14
#define ASCII_OFFSET				32

#define FONTSIZE_SMALL				0
#define FONTSIZE_BIG				1

typedef enum{
	DRAW_TEXT_SUCCESS				= 0,
	ERROR_TEXT_FAILED,
	ERROR_FONT_NOT_AVAILABLE,
	ERROR_FONTSIZE_NOT_AVAILABLE,
	ERROR_TEXT_TOO_LONG,
	CORRECT_TEXT_LENGTH,
	ERROR_WRITE_CHARACTER,
	WRITE_CHARACTER_SUCCESS
}TEXT_ERROR_CODES;


TEXT_ERROR_CODES API_Draw_Text							(uint16_t x_coor, uint16_t y_coor   , uint8_t  color, char *text, char *fontname, uint8_t fontsize, uint8_t fontstyle);
TEXT_ERROR_CODES API_Check_Text_Length					(uint16_t x_coor, size_t text_length, uint8_t  fontsize);
TEXT_ERROR_CODES API_Write_Small_Character_to_VGA		(uint16_t x_coor, uint16_t y_coor   , uint16_t character_w, uint16_t character_h, uint8_t color, const uint8_t *Pbitmap);
TEXT_ERROR_CODES API_Write_Big_Character_to_VGA			(uint16_t x_coor, uint16_t y_coor   , uint16_t character_w, uint16_t character_h, uint8_t color, const uint8_t *Pbitmap);
TEXT_ERROR_CODES API_Write_Small_Italic_Character_to_VGA(uint16_t x_coor, uint16_t y_coor, uint16_t character_w, uint16_t character_h, uint8_t color, const uint8_t *Pbitmap);

#endif //__TEXT_H
