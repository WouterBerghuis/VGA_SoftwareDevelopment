
#include "text.h"

TEXT_ERROR_CODES API_Draw_Text(uint16_t x_coor, uint16_t y_coor, uint8_t color, char *text, char *fontname,
					 	 	 	uint8_t fontsize, uint8_t fontstyle){

	uint16_t x_coor_cursor = x_coor;
	uint16_t y_coor_cursor = y_coor;
	size_t text_length = strlen(text);
	const uint8_t *Pbitmap;

	if(strcmp(fontname, "Minecraft") != 0)
		return ERROR_FONT_NOT_AVAILABLE;

	if((x_coor + (text_length * MAX_CHARACTER_WIDTH) ) > VGA_DISPLAY_X)
		return ERROR_TEXT_TOO_LONG;

	for(uint32_t i = 0; i < text_length; i++){
		uint8_t characterNumber  = *text;
		characterNumber 		-= ASCII_OFFSET;
		Pbitmap 				 = &Minecraft_Font[characterNumber][0];

		API_Write_Character_to_VGA(x_coor_cursor, y_coor_cursor, MINECRAFT_CHARACTERS_WIDTH, MINECRAFT_CHARACTERS_HEIGHT, color, Pbitmap);

		x_coor_cursor += MINECRAFT_CHARACTERS_WIDTH;
		text++;
	}

	return DRAW_TEXT_SUCCESS;
}

TEXT_ERROR_CODES API_Write_Character_to_VGA(uint16_t x_coor, uint16_t y_coor, uint16_t character_w, uint16_t character_h, uint8_t color, const uint8_t *Pbitmap){

	for(uint16_t i = y_coor; i < (character_h + y_coor); i++){
		for(uint16_t j = x_coor; j < (character_w + x_coor); j++){
			if(*Pbitmap == 0xFF)
				API_SetPixel(j, i, Background_Color);
			else if(*Pbitmap == 0x00)
				API_SetPixel(j, i, color);

			Pbitmap++;
		}
	}
}
