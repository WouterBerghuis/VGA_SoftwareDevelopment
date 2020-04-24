/*
 * parser.h
 *
 *  Created on: 22 Apr 2020
 *      Author: stijn
 */

#ifndef INC_PARSE_H_
#define INC_PARSE_H_

#define COMMAND_WORD_SIZE 12
#define MAX_STRINGS_DEVIDED 12
#define MAX_COMMAND_LENGTH 13

void uart_parser(char uartstring[], char* woord, char Empty_array[MAX_STRINGS_DEVIDED][MAX_COMMAND_LENGTH]);

#endif /* INC_PARSE_H_ */
