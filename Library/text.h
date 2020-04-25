
#ifndef __TEXT_H
#define __TEXT_H

#include <stdint.h>
#include <string.h>
#include "VGA_core.h"
#include "./Minecraft/upper_case.h"
#include "bitmap.h"

#define MAX_CHARACTER_WIDTH 		8

#define UPPER_CASE_ASCII_OFFSET		65
#define UPPER_CASE_A_ASCII_VALUE	65
#define UPPER_CASE_Z_ASCII_VALUE	90

typedef enum{
	DRAW_TEXT_SUCCESS			= 0,
	ERROR_FONT_NOT_AVAILABLE,
	ERROR_TEXT_TOO_LONG
}TEXT_ERROR_CODES;


TEXT_ERROR_CODES API_Draw_Text(uint16_t x_coor, uint16_t y_coor, char *text, char *fontname, uint8_t fontsize, uint8_t fontstyle);

#endif //__TEXT_H
