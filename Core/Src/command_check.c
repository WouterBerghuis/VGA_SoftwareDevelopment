/*
 * command_check.c
 *
 *  Created on: 24 Apr 2020
 *      Author: stijn
 */

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
	if 		(strcmp(First_word, "lijn") == 0)
	{
		Check_Colour(Commandstringdevided[5]);
		error = CHECK_COMMAND_SUCCESS;
	}

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

