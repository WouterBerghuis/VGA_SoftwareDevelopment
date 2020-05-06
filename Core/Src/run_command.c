/**
  ******************************************************************************
  * @file	  			run_command.c
  *
  * @author 			Stijn Keller
  * @date 				30 April 2020
  * @brief        		This file contains the function which calls the different API-functions
  *
  ******************************************************************************
**/


#include <run_command.h>

/**
  * @brief	This function is used calling the API-functions
  *
  * The first thing that will be checked is if the commandword contains a API-function
  * that can be called.
  *
  * @param	First_word This is the pointer to the first char of the 2D-array, (uint16_t)
  * @param  Commandstringdevided This is the 2D-array where all the data for the command is stored, (char[][])
  * @retval	LINE_ERROR_CODES
  *
  * @see LINE_ERROR_CODES
  */
RUNCOMMANDS_ERROR_CODES Run_Command(char *First_word, char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE])
{
	RUNCOMMANDS_ERROR_CODES error;
	LINE_ERROR_CODES errorline;
	if 	(strcmp(First_word, "lijn") == 0)
		errorline = Run_Command_Line(Commandstringdevided);

		if (errorline == 4){

		}
	else if (strcmp(First_word, "rechthoek") == 0)
		Run_Command_Rectangle(Commandstringdevided);

	else if (strcmp(First_word, "tekst") == 0)
		Run_Command_Text(Commandstringdevided);

	else if (strcmp(First_word, "bitmap") == 0)
		Run_Command_Bitmap(Commandstringdevided);

	else if (strcmp(First_word, "clearscherm") == 0)
		Run_Command_Clearscreen(Commandstringdevided);

	else if (strcmp(First_word, "cirkel") == 0)
		Run_Command_Circle(Commandstringdevided);

	else if (strcmp(First_word, "wacht") == 0)
		Run_Command_Wait(Commandstringdevided);

	else{
		return API_FUNCTION_CALL_FAILED;
	}
	return API_FUNCTION_CALL_SUCCESS;
}

LINE_ERROR_CODES Run_Command_Line(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	LINE_ERROR_CODES errorline;
	errorline = API_Draw_Line(atoi(Commandstringdevided[1]),		// x_coor1
			 	  atoi(Commandstringdevided[2]),		// y_coor1
				  atoi(Commandstringdevided[3]),		// x_coor2
				  atoi(Commandstringdevided[4]),		// y_coor2
				  atoi(Commandstringdevided[5]),		// Color
				  atoi(Commandstringdevided[6]));		// Width
	return errorline;
}

void Run_Command_Rectangle(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	API_Draw_Rectangle(atoi(Commandstringdevided[1]),   // x
			 	  	   atoi(Commandstringdevided[2]),	// y
					   atoi(Commandstringdevided[3]),	// Width
					   atoi(Commandstringdevided[4]),	// Height
					   atoi(Commandstringdevided[5]),	// Color
					   atoi(Commandstringdevided[6]));	// Filled
}

void Run_Command_Text(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	API_Draw_Text(atoi(Commandstringdevided[1]),		// x
			 	  atoi(Commandstringdevided[2]),		// y
				  atoi(Commandstringdevided[3]),		// Color
				 	   Commandstringdevided[4],			// Text
					   Commandstringdevided[5],			// Fontname
			 	  atoi(Commandstringdevided[6]),		// Fontsize
				  atoi(Commandstringdevided[7]));		// Font style

}

void Run_Command_Bitmap(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	API_Draw_Bitmap(atoi(Commandstringdevided[2]),		// x
			 	    atoi(Commandstringdevided[3]),		// y
				    atoi(Commandstringdevided[1]));     // Bitmap number
}

void Run_Command_Clearscreen(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	API_Clearscreen(atoi(Commandstringdevided[1]));		// Color
}

void Run_Command_Circle(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	API_Draw_Ellipse(atoi(Commandstringdevided[1]),		// x
			 	    atoi(Commandstringdevided[2]),		// y
				    atoi(Commandstringdevided[3]),		// Height
				 	atoi(Commandstringdevided[4]),		// Width
					atoi(Commandstringdevided[5]));		// Color
}

void Run_Command_Wait(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	API_Wait(atoi(Commandstringdevided[1]));     // Milliseconds
}

