/*
 * command_check.h
 *
 *  Created on: 24 Apr 2020
 *      Author: stijn
 */

#ifndef INC_COMMAND_CHECK_H_
#define INC_COMMAND_CHECK_H_

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <VGA_core.h>
#include "parse.h"

typedef enum{
	CHECK_COMMAND_SUCCESS = 0,			/**< No errors occurred during finding the command			*/
	COMMAND_DOES_NOT_EXIST, 			/**< Error occurred during finding the command				*/
}COMMANDCHECK_ERROR_CODES;

struct Data_Structure
{
	char command_word[MAX_COMMANDWORD_SIZE];
	char data1[MAX_COMMANDWORD_SIZE];
	char data2[MAX_COMMANDWORD_SIZE];
	char data3[MAX_COMMANDWORD_SIZE];
	char data4[MAX_COMMANDWORD_SIZE];
	char data5[MAX_COMMANDWORD_SIZE];
	char data6[MAX_COMMANDWORD_SIZE];
	char data7[MAX_COMMANDWORD_SIZE];
	char data8[MAX_COMMANDWORD_SIZE];
	char data9[MAX_COMMANDWORD_SIZE];
};
COMMANDCHECK_ERROR_CODES Command_check(char *First_word, char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]);
//struct Data_Structure Fill_Struct_Lijn(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]);
void Fill_Struct_Rechthoek(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]);
void Fill_Struct_Tekst(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]);
void Fill_Struct_Bitmap(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]);
void Fill_Struct_Clearscherm(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]);



struct Struct_lijn
{
	uint16_t x_coor1;
	uint16_t y_coor1;
	uint16_t x_coor2;
	uint16_t y_coor2;
	char kleur[MAX_COMMANDWORD_SIZE];
	uint16_t dikte;
};

struct Struct_rechthoek
{
	uint16_t x_coor;
	uint16_t y_coor;
	uint16_t breedte;
	uint16_t hoogte;
	char kleur[MAX_COMMANDWORD_SIZE];
	uint8_t gevuld;
};

struct Struct_tekst
{
	uint16_t x_coor;
	uint16_t y_coor;
	uint16_t kleur;
	char tekst[100];
	uint16_t fontnaam;
	uint16_t fontgrootte;
	uint8_t fontstijl;
};

struct Struct_bitmap
{
	uint8_t nr;
	uint16_t x_coor;
	uint16_t y_coor;
};

struct Struct_clearscherm
{
	char kleur[MAX_COMMANDWORD_SIZE];
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
