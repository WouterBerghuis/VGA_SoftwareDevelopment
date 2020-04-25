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

void Command_check(char *First_word, char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMAND_LENGTH] )
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
		strcpy(lijn1.kleur, Commandstringdevided[5]);
		lijn1.dikte   = atoi(Commandstringdevided[6]);
		test = 1;
		//Command_check_lijn();
	}
	else if (strcmp(First_word, "rechthoek") == 0)
	{
		test = 2;
	}
	else if (strcmp(First_word, "tekst") == 0)
	{
		test = 3;
	}
	else if (strcmp(First_word, "bitmap") == 0)
	{
		test = 4;
	}
	else if (strcmp(First_word, "clearscherm") == 0)
	{
		test = 5;
	}
	else{


	}
}

