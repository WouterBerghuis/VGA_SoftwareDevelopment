/**
  *********************************************************************************
  * @file	  			receive_command.c
  *
  * @author 			Jered van Ling
  * @date 				4 May 2020
  * @brief        		This file contains the function that sends the message
  * 					to the parser, checks the command and executes the command.
  *
  *********************************************************************************
**/
#include "receive_command.h"

uint8_t Message_Counter = 0;
char Command_word[MAX_COMMANDWORD_SIZE] = {0};
char Commandstring[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE] = {0};
uint8_t rx_buffer[MAX_AMOUNT_OF_COMMANDS][MAX_SIZE_MESSAGE];
extern uint8_t commando;
extern bool New_Message;
uint8_t Error[] ="Invalid command\n";
uint8_t No_error[] = "Command executed\n";


/**
  * @brief	This function is used to send the received message to the parser
  *
  *The function waits for a New_Message flag to be set to true.
  *This flag will only be set to true when the HAL_UART_RxCpltCallback function has determined if a new message is received.
  *When the flag is set to true, the uart_parser function will be called and the message will be sent to the parser.
  *To keep track of the messages a message counter is used to make sure the new message will be send to the parser.
  *The New_Message flag will always be reset to false afterwards to only send the message once to the parser.
  * @param	None
  *
  * @retval	None
  *
  */

void API_Send_Command()
{

	if (New_Message == true)
	{
		uart_parser((char*)rx_buffer[Message_Counter], Command_word, Commandstring); 		 /**< Send the command to the parser*/
		COMMANDCHECK_ERROR_CODES error_check = Command_check(Command_word, Commandstring);	 /**< Check if the send command is valid */

		if(error_check == CHECK_COMMAND_SUCCESS)
		{
			error_check = Run_Command(Command_word, Commandstring);							 /**< If the command is valid, the command wil be ran in Run_Command */

			if(error_check == API_FUNCTION_CALL_SUCCESS)									 /**< If the command is executed without error, inform the user it is executed */
				API_Uart_Transmit (No_error);
			else
				API_Uart_Transmit (Error);													/**< If a error returned, inform the user it is was not executed */
		}

		else if(error_check == COMMAND_DOES_NOT_EXIST)
			API_Uart_Transmit (Error);														 /**< If the command is invalid, inform the user that the command is invalid */

		memset(Commandstring, 0, sizeof(Commandstring));									 /**< Reset the commandstring buffer*/
		memset(Command_word, 0, sizeof(Command_word));										 /**< Reset the Command_word buffer*/
		Message_Counter++; 																	 /**< Keeps track of the messages send */
		New_Message = false;																 /**< Reset the New_Message flag */
	}

}
