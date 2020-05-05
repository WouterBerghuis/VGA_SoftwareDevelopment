/**
  *********************************************************************************
  * @file	  			repeat.c
  *
  * @author 			Jered van Ling
  * @date 				4 May 2020
  * @brief        		This file contains the function that runs the API_Repeat
  * 					function.
  *
  *********************************************************************************
**/

#include "repeat.h"
extern char Command_word[MAX_COMMANDWORD_SIZE];
extern char Commandstring[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE];
extern uint8_t rx_buffer[MAX_AMOUNT_OF_COMMANDS][MAX_SIZE_MESSAGE];
extern uint8_t Error[];
extern uint8_t No_error[];
extern volatile uint8_t commando;

REPEAT_ERROR_CODES API_Repeat(uint8_t command, uint8_t repeats)
{
	REPEAT_ERROR_CODES error;
	command--;
	uart_parser((char*)rx_buffer[command], Command_word, Commandstring); 		 /**< Send the command to the parser*/
	COMMANDCHECK_ERROR_CODES error_check = Command_check(Command_word, Commandstring);	 /**< Check if the send command is valid */

		if(error_check == CHECK_COMMAND_SUCCESS)
		{
			API_Uart_Transmit (No_error);

			while(repeats > 0)
			{
				Run_Command(Command_word, Commandstring);							 	 /**< If the command is valid, the command wil be ran in Run_Command */
				repeats--;
			}
			error = REPEAT_COMMAND_SUCCESS;
		}

		else if(error_check == COMMAND_DOES_NOT_EXIST)
		{	API_Uart_Transmit (Error);														 	/**< If the command is invalid, inform the user that the command is invalid */
			error = REPEAT_COMMAND_FAILED;
		}
	memset(Commandstring, 0, sizeof(Commandstring));									 	 	/**< Reset the Commandstring buffer*/
	memset(Command_word, 0, sizeof(Command_word));
	return error;
}

