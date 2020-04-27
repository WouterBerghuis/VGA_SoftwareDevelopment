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

TEXT_ERROR_CODES API_Draw_Text(uint16_t x_coor, uint16_t y_coor, uint8_t color, char *text, char *fontname,
					 	 	 	uint8_t fontsize, uint8_t fontstyle){

	TEXT_ERROR_CODES error;
	uint16_t x_coor_cursor = x_coor;
	uint16_t y_coor_cursor = y_coor;
	size_t text_length = strlen(text);
	const uint8_t *Pbitmap;

	if(strcmp(fontname, "Minecraft") != 0)
		return ERROR_FONT_NOT_AVAILABLE;

	error = API_Check_Text_Length(x_coor, text_length, fontsize);
	if(error != CORRECT_TEXT_LENGTH)
		return error;

	for(uint32_t i = 0; i < text_length; i++){
		uint8_t characterNumber  = *text;
		characterNumber 		-= ASCII_OFFSET;
		Pbitmap 				 = &Minecraft_Font[characterNumber][0];

		if(fontsize == FONTSIZE_SMALL){
			error = API_Write_Small_Character_to_VGA(x_coor_cursor, y_coor_cursor, MINECRAFT_CHARACTERS_WIDTH, MINECRAFT_CHARACTERS_HEIGHT, color, Pbitmap);
			x_coor_cursor += MINECRAFT_CHARACTERS_WIDTH;
		}

		if(fontsize == FONTSIZE_BIG){
			error = API_Write_Big_Character_to_VGA(x_coor_cursor, y_coor_cursor, (MINECRAFT_CHARACTERS_WIDTH * 2), (MINECRAFT_CHARACTERS_HEIGHT * 2), color, Pbitmap);
			x_coor_cursor += (MINECRAFT_CHARACTERS_WIDTH * 2);
		}
		if(error == ERROR_WRITE_CHARACTER)
			return error;

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

TEXT_ERROR_CODES API_Write_Small_Character_to_VGA(uint16_t x_coor, uint16_t y_coor, uint16_t character_w, uint16_t character_h, uint8_t color, const uint8_t *Pbitmap){

	VGA_INIT_ERROR_CODES error = 0;
	for(uint16_t i = y_coor; i < (character_h + y_coor); i++){
		for(uint16_t j = x_coor; j < (character_w + x_coor); j++){
			if(*Pbitmap == 0xFF)
				error = API_SetPixel(j, i, Background_Color);
			else if(*Pbitmap == 0x00)
				error = API_SetPixel(j, i, color);

			Pbitmap++;
		}
	}

	if(error != VGA_SETPIXEL_SUCCESS)
		return ERROR_WRITE_CHARACTER;
	return WRITE_CHARACTER_SUCCESS;
}

TEXT_ERROR_CODES API_Write_Big_Character_to_VGA(uint16_t x_coor, uint16_t y_coor, uint16_t character_w, uint16_t character_h, uint8_t color, const uint8_t *Pbitmap){

	VGA_INIT_ERROR_CODES error = 0;
	for(uint16_t i = y_coor; i < (character_h + y_coor); i += 2){
		for(uint16_t j = x_coor; j < (character_w + x_coor); j+= 2){
			if(*Pbitmap == 0xFF){
				error = API_SetPixel(j    , i    , Background_Color);
				error = API_SetPixel(j + 1, i    , Background_Color);
				error = API_SetPixel(j    , i + 1, Background_Color);
				error = API_SetPixel(j +1 , i + 1, Background_Color);
			}
			else if(*Pbitmap == 0x00){
				error = API_SetPixel(j    , i    , color);
				error = API_SetPixel(j + 1, i    , color);
				error = API_SetPixel(j    , i + 1, color);
				error = API_SetPixel(j +1 , i + 1, color);
			}
			Pbitmap++;
		}
	}

	if(error != VGA_SETPIXEL_SUCCESS)
		return ERROR_WRITE_CHARACTER;
	return WRITE_CHARACTER_SUCCESS;
}

