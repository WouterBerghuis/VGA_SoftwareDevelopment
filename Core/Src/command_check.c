/*
 * command_check.c
 *
 *  Created on: 24 Apr 2020
 *      Author: stijn
 */
#include <string.h>
void Command_check(char *First_word)
{
	int test = 0;
	if 		 (strcmp(First_word, "lijn") == 0)
	{

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


	//	switch(Command_word){
//	case("lijn"):
//			break;
//	case("rechthoek"):
//			break;
//	case("tekst"):
//			break;
//	case("bitmap"):
//			break;
//	case("clearscherm"):
//			break;
//	}
}

