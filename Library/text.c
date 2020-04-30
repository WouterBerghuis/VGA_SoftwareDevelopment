/**
  ******************************************************************************
  * @file	  			bitmap.c
  *
  * @author 			Wouter Berghuis
  * @date 				24 April 2020
  * @brief        		This file contains all API function responsible for drawing text on the screen
  *
  ******************************************************************************
  **/

#include "text.h"

/**
  * @brief	This function draws a received string on the VGA screen
  *
  * The drawing of the text consist of multiple steps. These steps are:
  * 1. Check if received font is available
  * 2.
  *
  * @param	x_coor This is the x-coordinate for the start of the string, (uint16_t)
  * @param  y_coor This is the y-coordinate for the start of the string, (uint16_t)
  * @param  color, The color of the text, (uint16_t)
  * @param  text, The string of character (char *)
  * @param  fontname, Fontname which should be used for printing (char *)
  * @param  fontsize, 0 = small | 1 = big
  * @param  fontstyle, 0 = normal | 1 = Italic | 2 = Bold
  *
  * @retval	TEXT_ERROR_CODES
  *
  * @see TEXT_ERROR_CODES
  */
TEXT_ERROR_CODES API_Draw_Text(uint16_t x_coor, uint16_t y_coor, uint8_t color, char *text, char *fontname,
					 	 	 	uint8_t fontsize, uint8_t fontstyle){

	TEXT_ERROR_CODES error;
	uint16_t x_coor_cursor = x_coor;
	uint16_t y_coor_cursor = y_coor;
	size_t text_length = strlen(text);
	const uint8_t *currentCharacter;

	if(strcmp(fontname, "Minecraft") != 0)
		return ERROR_FONT_NOT_AVAILABLE;

	error = API_Check_Text_Length(x_coor, text_length, fontsize);
	if(error != CORRECT_TEXT_LENGTH)
		return error;

	for(uint32_t i = 0; i < text_length; i++){
		uint8_t characterNumber  = *text;
		characterNumber 		-= ASCII_OFFSET;
		currentCharacter 		 = &Minecraft_Font[characterNumber][0];

		if(fontsize == FONTSIZE_SMALL && fontstyle == FONTSTYLE_NORMAL){
			error = API_Write_Character_to_VGA(x_coor_cursor, y_coor_cursor, MINECRAFT_SMALL_CHARACTERS_WIDTH, MINECRAFT_SMALL_CHARACTERS_HEIGHT, color, currentCharacter);
			x_coor_cursor += MINECRAFT_SMALL_CHARACTERS_WIDTH;
		}

		else if(fontsize == FONTSIZE_SMALL && fontstyle == FONTSTYLE_ITALIC){
			uint8_t characterBitmap_italic[MINECRAFT_SMALL_ITALIC_CHARACTERS_WIDTH * MINECRAFT_SMALL_ITALIC_CHARACTERS_HEIGHT];

			API_Set_Italic_Character_Bitmap(MINECRAFT_SMALL_ITALIC_CHARACTERS_WIDTH, MINECRAFT_SMALL_ITALIC_CHARACTERS_HEIGHT, (uint8_t *)currentCharacter, characterBitmap_italic);
			error = API_Write_Character_to_VGA(x_coor_cursor, y_coor_cursor, MINECRAFT_SMALL_ITALIC_CHARACTERS_WIDTH, MINECRAFT_SMALL_ITALIC_CHARACTERS_HEIGHT, color, characterBitmap_italic);
			x_coor_cursor += MINECRAFT_SMALL_ITALIC_CHARACTERS_WIDTH;
		}

		else if(fontsize == FONTSIZE_SMALL && fontstyle == FONTSTYLE_BOLD){
			uint8_t characterBitmap_bold[MINECRAFT_SMALL_BOLD_CHARACTERS_WIDTH * MINECRAFT_SMALL_BOLD_CHARACTERS_HEIGHT];

			API_Set_Bold_Character_Bitmap(MINECRAFT_SMALL_BOLD_CHARACTERS_WIDTH, MINECRAFT_SMALL_BOLD_CHARACTERS_HEIGHT, (uint8_t *)currentCharacter, characterBitmap_bold);
			error = API_Write_Character_to_VGA(x_coor_cursor, y_coor_cursor, MINECRAFT_SMALL_BOLD_CHARACTERS_WIDTH, MINECRAFT_SMALL_BOLD_CHARACTERS_HEIGHT, color, characterBitmap_bold);
			x_coor_cursor += MINECRAFT_SMALL_BOLD_CHARACTERS_WIDTH;
		}

		else if(fontsize == FONTSIZE_BIG && fontstyle == FONTSTYLE_NORMAL){
			uint8_t characterBitmap_big[MINECRAFT_BIG_CHARACTERS_WIDTH * MINECRAFT_BIG_CHARACTERS_HEIGHT];

			API_Set_Big_Character_Bitmap(MINECRAFT_BIG_CHARACTERS_WIDTH, MINECRAFT_BIG_CHARACTERS_HEIGHT, currentCharacter, characterBitmap_big);
			error = API_Write_Character_to_VGA(x_coor_cursor, y_coor_cursor, MINECRAFT_BIG_CHARACTERS_WIDTH, MINECRAFT_BIG_CHARACTERS_HEIGHT, color, characterBitmap_big);
			x_coor_cursor += MINECRAFT_BIG_CHARACTERS_WIDTH;
		}

		else if(fontsize == FONTSIZE_BIG && fontstyle == FONTSTYLE_ITALIC){
			uint8_t characterBitmap_big			[MINECRAFT_BIG_CHARACTERS_WIDTH 		* MINECRAFT_BIG_CHARACTERS_HEIGHT];
			uint8_t characterBitmap_big_italic	[MINECRAFT_BIG_ITALIC_CHARACTERS_WIDTH  * MINECRAFT_BIG_ITALIC_CHARACTERS_HEIGHT];

			API_Set_Big_Character_Bitmap(MINECRAFT_BIG_CHARACTERS_WIDTH, MINECRAFT_BIG_CHARACTERS_HEIGHT, currentCharacter, characterBitmap_big);
			API_Set_Italic_Character_Bitmap(MINECRAFT_BIG_ITALIC_CHARACTERS_WIDTH, MINECRAFT_BIG_ITALIC_CHARACTERS_HEIGHT, characterBitmap_big, characterBitmap_big_italic);

			error = API_Write_Character_to_VGA(x_coor_cursor, y_coor_cursor, MINECRAFT_BIG_ITALIC_CHARACTERS_WIDTH, MINECRAFT_BIG_ITALIC_CHARACTERS_HEIGHT, color, characterBitmap_big_italic);
			x_coor_cursor += MINECRAFT_BIG_ITALIC_CHARACTERS_WIDTH;
		}

		else if(fontsize == FONTSIZE_BIG && fontstyle == FONTSTYLE_BOLD){
			uint8_t characterBitmap_big			[MINECRAFT_BIG_CHARACTERS_WIDTH 		* MINECRAFT_BIG_CHARACTERS_HEIGHT];
			uint8_t characterBitmap_big_bold	[MINECRAFT_BIG_BOLD_CHARACTERS_WIDTH  * MINECRAFT_BIG_BOLD_CHARACTERS_HEIGHT];

			API_Set_Big_Character_Bitmap(MINECRAFT_BIG_CHARACTERS_WIDTH, MINECRAFT_BIG_CHARACTERS_HEIGHT, currentCharacter, characterBitmap_big);
			API_Set_Bold_Character_Bitmap(MINECRAFT_BIG_BOLD_CHARACTERS_WIDTH, MINECRAFT_BIG_BOLD_CHARACTERS_HEIGHT, characterBitmap_big, characterBitmap_big_bold);

			error = API_Write_Character_to_VGA(x_coor_cursor, y_coor_cursor, MINECRAFT_BIG_BOLD_CHARACTERS_WIDTH, MINECRAFT_BIG_BOLD_CHARACTERS_HEIGHT, color, characterBitmap_big_bold);
			x_coor_cursor += MINECRAFT_BIG_BOLD_CHARACTERS_WIDTH;
		}

		text++;
	}
	return DRAW_TEXT_SUCCESS;
}

TEXT_ERROR_CODES API_Check_Text_Length(uint16_t x_coor, size_t text_length, uint8_t fontsize){
	switch(fontsize){
		case (FONTSIZE_SMALL):
			if((x_coor + (text_length * MAX_SMALL_CHARACTER_WIDTH)) > VGA_DISPLAY_X)
				return ERROR_TEXT_TOO_LONG;
			else
				return CORRECT_TEXT_LENGTH;

		case(FONTSIZE_BIG):
			if((x_coor + (text_length * MAX_BIG_CHARACTER_WIDTH)) > VGA_DISPLAY_X)
				return ERROR_TEXT_TOO_LONG;
			else
				return CORRECT_TEXT_LENGTH;

		default:
			return ERROR_FONTSIZE_NOT_AVAILABLE;
	}
}

TEXT_ERROR_CODES API_Write_Character_to_VGA(uint16_t x_coor, uint16_t y_coor, uint16_t character_w, uint16_t character_h, uint8_t color, const uint8_t *characterBitmap){

	VGA_INIT_ERROR_CODES error = 0;
	for(uint16_t i = y_coor; i < (character_h + y_coor); i++){
		for(uint16_t j = x_coor; j < (character_w + x_coor); j++){
			if(*characterBitmap == 0xFF)
				error = API_SetPixel(j, i, Background_Color);
			else if(*characterBitmap == 0x00)
				error = API_SetPixel(j, i, color);

			characterBitmap++;
		}
	}

	if(error != VGA_SETPIXEL_SUCCESS)
		return ERROR_WRITE_CHARACTER;
	return WRITE_CHARACTER_SUCCESS;
}

void API_Set_Big_Character_Bitmap(uint16_t big_character_w, uint16_t big_character_h, const uint8_t *currentCharacter, uint8_t *characterBitmap){

	for(uint16_t i = 0; i < big_character_h; i += 2){
		for(uint16_t j = 0; j < big_character_w; j += 2){
			if(*currentCharacter == 0xFF){
				*(characterBitmap + ( j 					   + (i * big_character_w))) 	= 0xFF;
				*(characterBitmap + ((j + 1)   				   + (i * big_character_w))) 	= 0xFF;
				*(characterBitmap + ((j + big_character_w)     + (i * big_character_w))) 	= 0xFF;
				*(characterBitmap + ((j + big_character_w + 1) + (i * big_character_w))) 	= 0xFF;
			}
			else if(*currentCharacter == 0x00){
				*(characterBitmap + ( j                        + (i * big_character_w)))  	= 0x00;
				*(characterBitmap + ((j + 1)                   + (i * big_character_w))) 	= 0x00;
				*(characterBitmap + ((j + big_character_w)     + (i * big_character_w))) 	= 0x00;
				*(characterBitmap + ((j + big_character_w + 1) + (i * big_character_w)))	= 0x00;
			}
			currentCharacter++;
		}
	}
}

void API_Set_Italic_Character_Bitmap(uint16_t italic__character_w, uint16_t italic_character_h, uint8_t *currentCharacter, uint8_t *characterBitmap){

	uint16_t areaOne = (italic_character_h / 3);
	uint16_t areaTwo = ((italic_character_h / 3) * 2) + 1;


	// Shift pixels to the right
	for(uint16_t i = 0; i < italic_character_h; i++){
		for(uint16_t j = 0; j < (italic__character_w - ITALIC_SHIFT_TWO_OFFSET); j++){
			if(i >= 0 && i < areaOne){
				// Shift pixel two postitions to the right
				if(*currentCharacter == 0xFF)
					*(characterBitmap + ((j + ITALIC_SHIFT_TWO_OFFSET) + (i * italic__character_w))) = 0xFF;
				else if(*currentCharacter == 0x00)
					*(characterBitmap + ((j + ITALIC_SHIFT_TWO_OFFSET) + (i * italic__character_w))) = 0x00;

				// Fill remaining pixels
				if(j >= 0 && j < 2)
					*(characterBitmap + (j + (i * italic__character_w))) = 0xFF;
			}
			else if(i >= areaOne && i < areaTwo){
				// Shift pixel one position to the right
				if(*currentCharacter == 0xFF)
					*(characterBitmap + ((j + ITALIC_SHIFT_ONE_OFFSET) + (i * italic__character_w))) = 0xFF;
				else if(*currentCharacter == 0x00)
					*(characterBitmap + ((j + ITALIC_SHIFT_ONE_OFFSET) + (i * italic__character_w))) = 0x00;

				// Fill remaining pixels
				if(j == 0)
					*(characterBitmap + (j + (i * italic__character_w))) 	   = 0xFF;
				else if(j == (italic__character_w - 3))
					*(characterBitmap + ((j + ITALIC_SHIFT_TWO_OFFSET) + (i * italic__character_w))) = 0xFF;
			}
			else{
				// Pixel stays on the same position
				if(*currentCharacter == 0xFF)
					*(characterBitmap + (j + (i * italic__character_w))) 	= 0xFF;
				else if(*currentCharacter == 0x00)
					*(characterBitmap + (j + (i * italic__character_w))) 	= 0x00;

				// Fill remaining pixels
				if(j == (italic__character_w - 4))
					*(characterBitmap + ((j + ITALIC_SHIFT_TWO_OFFSET ) + (i * italic__character_w))) = 0xFF;
				else if(j == (italic__character_w - 3))
					*(characterBitmap + ((j + ITALIC_SHIFT_TWO_OFFSET) + (i * italic__character_w))) 	= 0xFF;
			}
			currentCharacter++;
		}
	}
}

void API_Set_Bold_Character_Bitmap(uint16_t bold_character_w, uint16_t bold_character_h, const uint8_t *currentCharacter, uint8_t *characterBitmap){

	for(uint16_t i = 0; i < bold_character_h; i++ ){
		for(uint16_t j = 0; j < bold_character_w; j += 2){
			if(*currentCharacter == 0xFF){
				*(characterBitmap + ( j 					   + (i * bold_character_w))) 	= 0xFF;
				*(characterBitmap + ((j + 1)   				   + (i * bold_character_w))) 	= 0xFF;
			}
			else if(*currentCharacter == 0x00){
				*(characterBitmap + ( j                        + (i * bold_character_w)))  	= 0x00;
				*(characterBitmap + ((j + 1)                   + (i * bold_character_w))) 	= 0x00;
			}
			currentCharacter++;
		}
	}
}

