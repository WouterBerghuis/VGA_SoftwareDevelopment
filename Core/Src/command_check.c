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

/**
  * @brief	This function checks the parsed data and puts the data in structures
  *
  *
  * @param	First_word This the the first word of the command wh, (uint16_t)
  * @param  Commandstringdevided This is the 2D-array with all the parsed data, (uint16_t)
  *
  * @retval	COMMANDCHECK_ERROR_CODES
  *
  * @see COMMANDCHECK_ERROR_CODES
  */

COMMANDCHECK_ERROR_CODES Command_check(char *First_word, char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE])
{
	COMMANDCHECK_ERROR_CODES error;
	if 		 (strcmp(First_word, "lijn") == 0)
		error = CHECK_COMMAND_SUCCESS;

	else if (strcmp(First_word, "rechthoek") == 0)
		error = CHECK_COMMAND_SUCCESS;

	else if (strcmp(First_word, "tekst") == 0)
		error = CHECK_COMMAND_SUCCESS;

	else if (strcmp(First_word, "bitmap") == 0)
		error = CHECK_COMMAND_SUCCESS;

	else if (strcmp(First_word, "clearscherm") == 0)
		error = CHECK_COMMAND_SUCCESS;

	else
		return COMMAND_DOES_NOT_EXIST;

	return error;
}

//struct Data_Structure Fill_Struct_Lijn(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
//	strcpy((*Data) -> command_word, Commandstringdevided[0]);
//	strcpy(Data->command_word, Commandstringdevided[0]);
//	strcpy(Data.data1, Commandstringdevided[1]);
//	strcpy(Data.data2, Commandstringdevided[2]);
//	strcpy(Data.data3, Commandstringdevided[3]);
//	strcpy(Data.data4, Commandstringdevided[4]);
//	strcpy(Data.data5, Commandstringdevided[5]);
//	strcpy(Data.data6, Commandstringdevided[6]);
//	strcpy(Data.data7, Commandstringdevided[7]);
//	strcpy(Data.data8, Commandstringdevided[8]);
//	strcpy(Data.data9, Commandstringdevided[9]);
//}

//void Fill_Struct_Lijn(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
//	struct Struct_lijn lijn1;
//	lijn1.x_coor1 = atoi(Commandstringdevided[1]);
//	lijn1.y_coor1 = atoi(Commandstringdevided[2]);
//	lijn1.x_coor2 = atoi(Commandstringdevided[3]);
//	lijn1.y_coor2 = atoi(Commandstringdevided[4]);
//	strcpy(lijn1.kleur,  Commandstringdevided[5]);
//	lijn1.dikte   = atoi(Commandstringdevided[6]);
//}

//void Fill_Struct_Rechthoek(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
//	struct Struct_rechthoek rechthoek1;
//	rechthoek1.x_coor =  atoi(Commandstringdevided[1]);
//	rechthoek1.y_coor =  atoi(Commandstringdevided[2]);
//	rechthoek1.breedte = atoi(Commandstringdevided[3]);
//	rechthoek1.hoogte =  atoi(Commandstringdevided[4]);
//	strcpy(rechthoek1.kleur,  Commandstringdevided[5]);
//	rechthoek1.gevuld =  atoi(Commandstringdevided[6]);
//}
//
//void Fill_Struct_Tekst(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
//	struct Struct_tekst tekst1;
//	tekst1.x_coor =     atoi(Commandstringdevided[1]);
//	tekst1.y_coor =     atoi(Commandstringdevided[2]);
//	tekst1.kleur=       atoi(Commandstringdevided[3]);
//	strcpy(tekst1.tekst,     Commandstringdevided[4]);
//	strcpy(tekst1.fontnaam,  Commandstringdevided[5]);
//	tekst1.fontgrootte= atoi(Commandstringdevided[6]);
//	strcpy(tekst1.fontstijl, Commandstringdevided[7]);
//}
//
//void Fill_Struct_Bitmap(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
//	struct Struct_bitmap bitmap1;
//	bitmap1.nr =     atoi(Commandstringdevided[1]);
//	bitmap1.x_coor = atoi(Commandstringdevided[2]);
//	bitmap1.y_coor = atoi(Commandstringdevided[3]);
//}
//
//void Fill_Struct_Clearscherm(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
//	struct Struct_clearscherm clearscherm1;
//	strcpy(clearscherm1.kleur, Commandstringdevided[1]);
//}
