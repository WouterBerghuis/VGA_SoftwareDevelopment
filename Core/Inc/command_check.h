/*
 * command_check.h
 *
 *  Created on: 24 Apr 2020
 *      Author: stijn
 */

#ifndef INC_COMMAND_CHECK_H_
#define INC_COMMAND_CHECK_H_

void Command_check(char Command_word[20]);

struct Struct_lijn
{
	uint16_t x_coor1;
	uint16_t y_coor1;
	uint16_t x_coor2;
	uint16_t y_coor2;
	uint16_t kleur;
	uint16_t dikte;
};

struct Struct_rechthoek
{
	uint16_t x_coor;
	uint16_t y_coor;
	uint16_t breedte;
	uint16_t hoogte;
	uint16_t kleur;
	uint8_t gevuld;
};

struct Struct_tekst
{
	uint16_t x_coor;
	uint16_t y_coor;
	uint16_t kleur;
	uint16_t fontnaam;
	uint16_t fontgrootte;
	uint8_t fontstijl;
};

struct Struct_bitmap
{
	uint8_t nr;
	uint16_t x_coor;
	uint16_t y_coor;
	uint16_t fontnaam;
	uint16_t fontgrootte;
	uint8_t fontstijl;
};

struct Struct_bitmap
{
	uint16_t kleur;
};

struct Struct_wacht
{
	uint16_t msecs;
};

struct Struct_herhaal
{
	uint8_t aantal;
};

struct Struct_cirkel
{
	uint16_t x_coor;
	uint16_t y_coor;
	uint16_t radius;
	uint16_t kleur;
};

struct Struct_figuur
{
	uint16_t x_coor1;
	uint16_t y_coor1;
	uint16_t x_coor2;
	uint16_t y_coor2;
	uint16_t x_coor3;
	uint16_t y_coor3;
	uint16_t x_coor4;
	uint16_t y_coor4;
	uint16_t x_coor5;
	uint16_t y_coor5;
};

#endif /* INC_COMMAND_CHECK_H_ */
