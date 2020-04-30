/**
  ******************************************************************************
  * @file	  			parse.c
  *
  * @author 			Stijn Keller
  * @date 				21 April 2020
  * @brief        		This file contains the function to parse the incoming string.
  *
  * This file uses 2 libraries (string.h & stdio.h)  and its header file.
  ******************************************************************************
**/
#include <string.h>
#include <stdio.h>
#include "parse.h"

/**
  * @brief	This function parses the incoming string
  *
  * By using the strtok() function the string will be parsed.
  * The words are stored in the 2-dimensional array called Empty_array[][]
  *
  *
  * @param	uartstring This the incoming string from the UART, (char[])
  * @param  First_word Pointer to array where the first word will be stored, (char*)
  * @param  Empty_array 2D-array where the parsed data from the string will be stored, (char[][])
  *
  * @retval	PARSER_ERROR_CODES
  *
  * @see PARSER_ERROR_CODES
  */

void uart_parser(char uartstring[], char* First_word, char Empty_array[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE])
{
    int i = 0;
	char delim[]= " ,";											 //strtok() will look for ' ' and ',' in the string
	char *ptr = strtok(uartstring, delim);
	while(ptr != NULL)
		{
		    //strncpy(&Command_array[i][0], ptr, strlen(ptr));
		    strncpy(&Empty_array[i][0], ptr, strlen(ptr));		 //The word where *ptr is pointing to will be stored in the 2D-array
			ptr = strtok(NULL, delim);							 //Pointer will point to the next word
			i++;
		}
	i = 0;

	strncpy(First_word, Empty_array[0], strlen(Empty_array[0])); //The first word from the parsed string will also be stored in individual array
	return;
}
