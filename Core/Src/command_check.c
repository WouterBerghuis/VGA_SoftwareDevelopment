/**
  ******************************************************************************
  * @file	  			command_check.c
  *
  * @author 			Stijn Keller
  * @date 				26 April 2020
  * @brief        		This file contains the function that will check the parsed data.
  *
  ******************************************************************************
**/
#include "command_check.h"

/**
  * @brief	This function checks the first word of the commandstring
  *
  *	For some commands extra checks or/and adjustments will be done for the string. (i.e. Check_Colour())
  *
  * @param	First_word This is the the first word of the commandstring, (uint16_t)
  * @param  Commandstringdevided This is the 2D-array with all the parsed data, (uint16_t)
  *
  * @retval	COMMANDCHECK_ERROR_CODES
  *
  * @see COMMANDCHECK_ERROR_CODES
  */
COMMANDCHECK_ERROR_CODES Command_check(char *First_word, char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE])
{
	COMMANDCHECK_ERROR_CODES error;
	uint8_t colorValue;
	uint8_t fontstyleValue;
	if 	(strcmp(First_word, "lijn") == 0)
	{
		Check_Color(Commandstringdevided[5], &colorValue);					//Color gets checked if it exists and will be converted into uint8_t
		sprintf(Commandstringdevided[5], "%d", colorValue);					//Integer gets placed in string
		error = CHECK_COMMAND_SUCCESS;
	}

	else if (strcmp(First_word, "rechthoek") == 0)
	{
		Check_Color(Commandstringdevided[5], &colorValue);					//Color gets checked if it exists and will be converted into uint8_t
		sprintf(Commandstringdevided[5], "%d", colorValue);					//Integer gets placed in string
		error = CHECK_COMMAND_SUCCESS;
	}

	else if (strcmp(First_word, "tekst") == 0)
	{
		Check_Color(Commandstringdevided[3], &colorValue);					//Color gets checked if it exists and will be converted into uint8_t
		sprintf(Commandstringdevided[3], "%d", colorValue);
		Check_Fontstyle(Commandstringdevided[7], &fontstyleValue);
		sprintf(Commandstringdevided[7], "%d", fontstyleValue);
		error = CHECK_COMMAND_SUCCESS;
	}


	else if (strcmp(First_word, "bitmap") == 0)
		error = CHECK_COMMAND_SUCCESS;

	else if (strcmp(First_word, "clearscherm") == 0)
	{
		Check_Color(Commandstringdevided[1], &colorValue);					//Color gets checked if it exists and will be converted into uint8_t
		sprintf(Commandstringdevided[1], "%d", colorValue);					//Integer gets placed in string
		error = CHECK_COMMAND_SUCCESS;
	}

	else if (strcmp(First_word, "cirkel") == 0){
		Check_Color(Commandstringdevided[5], &colorValue);					//Color gets checked if it exists and will be converted into uint8_t
		sprintf(Commandstringdevided[5], "%d", colorValue);					//Integer gets placed in string
		error = CHECK_COMMAND_SUCCESS;
	}

	else
		return COMMAND_DOES_NOT_EXIST;

	return error;
}

