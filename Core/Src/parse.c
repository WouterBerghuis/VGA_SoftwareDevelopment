/*
 * parse.c
 *
 *  Created on: 22 Apr 2020
 *      Author: stijn
 */
#include <string.h>
#include <stdio.h>
#include "parse.h"

void uart_parser(char uartstring[], char* First_word, char Empty_array[MAX_STRINGS_DEVIDED][MAX_COMMAND_LENGTH])
{
    int i = 0;
	//char Command_array[5][20];
	char delim[]= " ,";
	char *ptr = strtok(uartstring, delim);
	while(ptr != NULL)
		{
		    //strncpy(&Command_array[i][0], ptr, strlen(ptr));
		    strncpy(&Empty_array[i][0], ptr, strlen(ptr));
			ptr = strtok(NULL, delim);
			i++;
		}
	i = 0;

	strncpy(First_word, Empty_array[0], strlen(Empty_array[0]));
	return;
}
