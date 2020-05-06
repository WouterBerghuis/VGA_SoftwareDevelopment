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
  * @brief	This function is used to check if a message has been received and checks if there are still executable commands left to be executed.
  *
  *The function waits for a New_Message flag to be set to true and makes sure that all commando's will be executed
  *The New_Message flag will only be set to true when the HAL_UART_RxCpltCallback function has determined if a new message is received.
  *When the flag is set to true or if there are stacked commands left to be executed, the API_Execute_Command will be called.
  * @param	None
  *
  * @retval	None
  *
  */

void API_Send_Command()
{

	if (New_Message == true)
	{
		API_Execute_Command();													 		 /**< Keeps track of the messages send */
		New_Message = false;															 /**< Reset the New_Message flag */
	}

	else if (Message_Counter != commando)												/**< This makes sure that no commands will be skipped after a wait*/
		API_Wait(100), API_Execute_Command();


}

/**
  * @brief	This function sends the messages to the parser function, calls the Command_check function to check if the received command is valid
  * 		and finally runs the command.
  *
  * Parses the received message, checks if the command is valid and executes it if it is a valid command.
  * The user will be informed if the command was executable or invalid.
  * Afterwards it is necessary to clean the buffers of the Command_word and Commandstring to make sure commands will not be mixed up and create a invalid command.
  * The Message_Counter will be incremented to keep track of how many commmands where executed.
  *
  * @param	None
  *
  * @retval	None
  *
  */

void API_Execute_Command()
{
	uart_parser((char*)rx_buffer[Message_Counter], Command_word, Commandstring); 		 /**< Send the command to the parser*/
	COMMANDCHECK_ERROR_CODES error_check = Command_check(Command_word, Commandstring);	 /**< Check if the send command is valid */

	if(error_check == CHECK_COMMAND_SUCCESS)
	{
		error_check = Run_Command(Command_word, Commandstring);							 /**< If the command is valid, the command will be ran in Run_Command */
		API_Error_Handler(error_check);

													/**< If a error returned, inform the user it is was not executed */
	}

	else if(error_check == COMMAND_DOES_NOT_EXIST)
		API_Uart_Transmit (Error);														 /**< If the command is invalid, inform the user that the command is invalid */

	memset(Commandstring, 0, sizeof(Commandstring));									 /**< Reset the Commandstring buffer*/
	memset(Command_word, 0, sizeof(Command_word));										 /**< Reset the Command_word buffer*/
	Message_Counter++;
}
