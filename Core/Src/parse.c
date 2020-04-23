/*
 * parse.c
 *
 *  Created on: 22 Apr 2020
 *      Author: stijn
 */
#include <string.h>
#include <stdio.h>
#include "usart.h"

void uart_parser(char uartstring[])
{
	int string_size = strlen(uartstring);
	char teststring[] = "dit is een test text met heelveel kleine woorden";
	char delim[]= " ";
	char *ptr = strtok(teststring, " ");
	//_write(teststring);
	while(ptr != NULL)
		{
		    HAL_UART_Transmit(&huart2, (uint8_t*)ptr, sizeof(ptr), 1000);
		//printf("'%s'\n", ptr);
			ptr = strtok(NULL, " ");

			//HAL_UART_Transmit(&huart2, (uint8_t*)test, sizeof(test), 1000); // string versturen via uart2

		}


	//	char output[N][2];
	//	char input[] = "274a2e";
	//
	//	for(int i=0; i<strlen(input)/2; i++) {
	//	    output[i][0] = input[i * 2];
	//	    output[i][1] = input[(i * 2) + 1];
	//	}
}
