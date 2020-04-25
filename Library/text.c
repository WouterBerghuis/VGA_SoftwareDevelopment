
#include "text.h"

TEXT_ERROR_CODES API_Draw_Text(uint16_t x_coor, uint16_t y_coor, char *text, char *fontname,
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

			API_Write_Bitmap_to_VGA(x_coor_cursor, y_coor_cursor, MINECRAFT_CHARACTERS_WIDTH, MINECRAFT_CHARACTERS_HEIGHT, Pbitmap);

			x_coor_cursor += MINECRAFT_CHARACTERS_WIDTH;
			text++;
	}

	return DRAW_TEXT_SUCCESS;
}
