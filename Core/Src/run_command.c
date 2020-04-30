/*
 * run_command.c
 *
 *  Created on: 30 Apr 2020
 *      Author: stijn
 */

#include <parse.h>
//#include <command_check.h>
#include <run_command.h>

void Run_Command(char *First_word, char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE])
{
	//RUNCOMMANDS_ERROR_CODES error;
	if 		 (strcmp(First_word, "lijn") == 0)
		Run_Command_Line(Commandstringdevided);

	else if (strcmp(First_word, "rechthoek") == 0)
	{

	}

	else if (strcmp(First_word, "tekst") == 0)
	{

	}

	else if (strcmp(First_word, "bitmap") == 0)
	{

	}

	else if (strcmp(First_word, "clearscherm") == 0)
	{

	}

	else{

	}
	return;
}

void Run_Command_Line(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	API_Draw_Line(atoi(Commandstringdevided[1]),
			 	  atoi(Commandstringdevided[2]),
				  atoi(Commandstringdevided[3]),
				  atoi(Commandstringdevided[4]),
				  	   Commandstringdevided[5],
				  atoi(Commandstringdevided[6]));
}

void Run_Command_Rectangle(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	API_Draw_Rectangle(atoi(Commandstringdevided[1]),
			 	  	   atoi(Commandstringdevided[2]),
					   atoi(Commandstringdevided[3]),
					   atoi(Commandstringdevided[4]),
					   	    Commandstringdevided[5],
					   atoi(Commandstringdevided[6]));
}

void Run_Command_Text(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	API_Draw_Text(atoi(Commandstringdevided[1]),
			 	  atoi(Commandstringdevided[2]),
				  atoi(Commandstringdevided[3]),
				 	   Commandstringdevided[4],
					   Commandstringdevided[5],
			 	  atoi(Commandstringdevided[6]),
				  	   Commandstringdevided[7]);
}

void Run_Command_Bitmap(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	API_Draw_Bitmap(atoi(Commandstringdevided[2]),
			 	    atoi(Commandstringdevided[3]),
				    atoi(Commandstringdevided[1]));
}

void Run_Command_Clearscreen(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	API_Draw_Clearscreen(atoi(Commandstringdevided[1]));
}

//void Fill_Struct_Rechthoek(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
//
//	rechthoek1.x_coor =  atoi(Commandstringdevided[1]);
//	rechthoek1.y_coor =  atoi(Commandstringdevided[2]);
//	rechthoek1.breedte = atoi(Commandstringdevided[3]);
//	rechthoek1.hoogte =  atoi(Commandstringdevided[4]);
//	strcpy(rechthoek1.kleur,  Commandstringdevided[5]);
//	rechthoek1.gevuld =  atoi(Commandstringdevided[6]);
//}
//
//void Fill_Struct_Tekst(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
//
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
//
//	bitmap1.nr =     atoi(Commandstringdevided[1]);
//	bitmap1.x_coor = atoi(Commandstringdevided[2]);
//	bitmap1.y_coor = atoi(Commandstringdevided[3]);
//}
//
//void Fill_Struct_Clearscherm(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
//
//	strcpy(clearscherm1.kleur, Commandstringdevided[1]);
//}
