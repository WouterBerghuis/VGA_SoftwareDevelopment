/**
  ******************************************************************************
  * @file	  			parse.h
  *
  * @author 			Stijn Keller
  * @date 				21 April 2020
  * @brief        		This file is the headerfile of parse.c
  ******************************************************************************
**/

#ifndef INC_PARSE_H_
#define INC_PARSE_H_

/*
 * @brief 	Multiple defines for determining the size of the arrays/2D-arrays
 *
 */
#define MAX_STRINGS_DEVIDED 12		//Maximum amount of words per string
#define MAX_COMMANDWORD_SIZE 13		//Maximum size of a single word


/*
 * FUNCTIONS
 */
void uart_parser(char uartstring[], char* woord, char Empty_array[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]);

#endif /* INC_PARSE_H_ */
