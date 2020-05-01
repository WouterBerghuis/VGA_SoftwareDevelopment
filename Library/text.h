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

#define ITALIC_SHIFT_ONE_OFFSET		1
#define ITALIC_SHIFT_TWO_OFFSET		2

/*
 * @brief Enumeration for the different fontsizes
 */
enum{
	FONTSIZE_SMALL = 0,
	FONTSIZE_BIG
};

/*
 * @brief Enumeration for the different fontstyles
 */
enum{
	FONTSTYLE_NORMAL = 0,
	FONTSTYLE_ITALIC,
	FONTSTYLE_BOLD
};

/*
 * @brief 	Returnvalues for the different text functions. These are used for
 * 			errorhandling.
 *
 */
typedef enum{
	DRAW_TEXT_SUCCESS = 0,			/**< No errors occurred during text drawing 					*/
	ERROR_TEXT_FAILED,				/**< Error occured during text drawing 							*/
	ERROR_FONT_NOT_AVAILABLE,		/**< Received font is not available 							*/
	ERROR_FONTSIZE_NOT_AVAILABLE,	/**< Received fontsize is not available 						*/
	ERROR_TEXT_TOO_LONG,			/**< Received string doesn't fit on the screen 					*/
	CORRECT_TEXT_LENGTH,			/**< Received string does fit on the screen						*/
	ERROR_WRITE_CHARACTER,			/**< Error occurred during writing character to VGA RAM 		*/
	WRITE_CHARACTER_SUCCESS,		/**< No errors occurred during writing character to VGA RAM		*/
	SET_BIG_CHARACTER_SUCCES,		/**< Setting big character bitmap succesfull					*/
	SET_ITALIC_CHARACTER_SUCCES,	/**< Setting italic character bitmap succesfull					*/
	SET_BOLD_CHARACTER_SUCCES		/**< Setting bold character bitmap succesfull					*/
}TEXT_ERROR_CODES;

/*
 * FUNCTIONS
 */
TEXT_ERROR_CODES API_Draw_Text							(uint16_t x_coor, uint16_t y_coor   , uint8_t  color, char *text, char *fontname, uint8_t fontsize, uint8_t fontstyle);
TEXT_ERROR_CODES API_Check_Text_Length					(uint16_t x_coor, size_t text_length, uint8_t max_character_width);
TEXT_ERROR_CODES API_Write_Character_to_VGA				(uint16_t x_coor, uint16_t y_coor, uint16_t character_w, uint16_t character_h, uint8_t color, const uint8_t *characterBitmap);
TEXT_ERROR_CODES API_Set_Big_Character_Bitmap			(uint16_t big_character_w, uint16_t big_character_h, const uint8_t *currentCharacter, uint8_t *characterBitmap);
TEXT_ERROR_CODES API_Set_Italic_Character_Bitmap		(uint16_t italic__character_w, uint16_t italic_character_h, uint8_t *currentCharacter, uint8_t *characterBitmap);
TEXT_ERROR_CODES API_Set_Bold_Character_Bitmap			(uint16_t bold_character_w, uint16_t bold_character_h, const uint8_t *currentCharacter, uint8_t *characterBitmap);

#endif //__TEXT_H
