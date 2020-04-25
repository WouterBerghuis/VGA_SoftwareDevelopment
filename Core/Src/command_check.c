/*
 * command_check.c
 *
 *  Created on: 24 Apr 2020
 *      Author: stijn
 */
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "parse.h"
#include "command_check.h"

COMMANDCHECK_ERROR_CODES Command_check(char *First_word, char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMAND_LENGTH] )
{
	int test = 0;
	COMMANDCHECK_ERROR_CODES error;
	if 		 (strcmp(First_word, "lijn") == 0)
	{
		struct Struct_lijn lijn1;
		lijn1.x_coor1 = atoi(Commandstringdevided[1]);
		lijn1.y_coor1 = atoi(Commandstringdevided[2]);
		lijn1.x_coor2 = atoi(Commandstringdevided[3]);
		lijn1.y_coor2 = atoi(Commandstringdevided[4]);
		strcpy(lijn1.kleur,  Commandstringdevided[5]);
		lijn1.dikte   = atoi(Commandstringdevided[6]);
		test = 1;
		//Command_check_lijn();
	}
	else if (strcmp(First_word, "rechthoek") == 0)
	{
		struct Struct_rechthoek rechthoek1;
		rechthoek1.x_coor =  atoi(Commandstringdevided[1]);
		rechthoek1.y_coor =  atoi(Commandstringdevided[2]);
		rechthoek1.breedte = atoi(Commandstringdevided[3]);
		rechthoek1.hoogte =  atoi(Commandstringdevided[4]);
		strcpy(rechthoek1.kleur,  Commandstringdevided[5]);
		rechthoek1.gevuld =  atoi(Commandstringdevided[6]);
		test = 2;
	}
	else if (strcmp(First_word, "tekst") == 0)
	{
		struct Struct_tekst tekst1;
		tekst1.x_coor =     atoi(Commandstringdevided[1]);
		tekst1.y_coor =     atoi(Commandstringdevided[2]);
		tekst1.kleur=       atoi(Commandstringdevided[3]);
		strcpy(tekst1.tekst,     Commandstringdevided[4]);
		strcpy(tekst1.fontnaam,  Commandstringdevided[5]);
		tekst1.fontgrootte= atoi(Commandstringdevided[6]);
		strcpy(tekst1.fontstijl, Commandstringdevided[7]);
		test = 3;
	}
	else if (strcmp(First_word, "bitmap") == 0)
	{
		struct Struct_bitmap bitmap1;
		bitmap1.nr =     atoi(Commandstringdevided[1]);
		bitmap1.x_coor = atoi(Commandstringdevided[2]);
		bitmap1.y_coor = atoi(Commandstringdevided[3]);
		API_Draw_Bitmap(bitmap1.x_coor, bitmap1.y_coor, bitmap1.nr);
		test = 4;
	}
	else if (strcmp(First_word, "clearscherm") == 0)
	{
		struct Struct_clearscherm clearscherm1;
		strcpy(clearscherm1.kleur, Commandstringdevided[1]);
		test = 5;
	}
	else{
		error = FIND_COMMAND_FAILED;
		return error;
	}

	error = FIND_COMMAND_SUCCESS;
	return error;
}

