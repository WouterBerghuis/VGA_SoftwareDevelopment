/**
  ******************************************************************************
  * @file	  			receive_command.c
  *
  * @author 			Jered van Ling
  * @date 				4 May 2020
  * @brief        		This file contains the function that sends the message
  * 					to the parser.
  *
  ******************************************************************************
**/
#include "receive_command.h"

uint8_t Message_Counter = 0;
char Command_word[MAX_COMMANDWORD_SIZE] = {0};
char Commandstring[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE] = {0};
uint8_t rx_buffer[MAX_AMOUNT_OF_COMMANDS][MAX_SIZE_MESSAGE];
extern uint8_t commando;
extern bool New_Message;


/**
  * @brief	This function is used to send the received message to the parser
  *
  *The function waits for a New_Message flag to be set to true.
  *This flag will only be set to true when the HAL_UART_RxCpltCallback has determined if a new message is received.
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
		API_Uart_Transmit ((uint8_t*)rx_buffer[Message_Counter]);   /**< Transmit the data via uart */
		uart_parser((char*)rx_buffer[Message_Counter], Command_word, Commandstring);

		COMMANDCHECK_ERROR_CODES error_check = Command_check(Command_word, Commandstring);

		  if(error_check == CHECK_COMMAND_SUCCESS)
			  Run_Command(Command_word, Commandstring);

		  memset(Commandstring, 0, sizeof(Commandstring));
		  memset(Command_word, 0, sizeof(Command_word));
		  Message_Counter++; 											/**< Keeps track of the messages send */
		  New_Message = false;										/**< Reset the New_Message flag */
	}

}
