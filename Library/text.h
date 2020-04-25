
#ifndef __TEXT_H
#define __TEXT_H

#include <stdint.h>
#include <string.h>
#include "VGA_core.h"
#include "minecraft.h"
#include "bitmap.h"

#define MAX_CHARACTER_WIDTH 	7
#define ASCII_OFFSET			32

typedef enum{
	DRAW_TEXT_SUCCESS			= 0,
	ERROR_FONT_NOT_AVAILABLE,
	ERROR_TEXT_TOO_LONG
}TEXT_ERROR_CODES;


TEXT_ERROR_CODES API_Draw_Text(uint16_t x_coor, uint16_t y_coor, char *text, char *fontname, uint8_t fontsize, uint8_t fontstyle);

#endif //__TEXT_H
