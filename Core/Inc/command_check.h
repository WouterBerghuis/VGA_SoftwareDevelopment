/**
  ******************************************************************************
  * @file	  			command_check.h
  *
  * @author 			Stijn Keller
  * @date 				26 April 2020
  * @brief        		This file contains the API-function for drawing a line on the screen
  *
  ******************************************************************************
**/

#ifndef INC_COMMAND_CHECK_H_
#define INC_COMMAND_CHECK_H_

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <VGA_core.h>
#include "parse.h"

/**
  * @brief 	Returnvalues for the Command_check function
  */
typedef enum{
	CHECK_COMMAND_SUCCESS = 0,			/**< No errors occurred during finding the command			*/
	COMMAND_DOES_NOT_EXIST, 			/**< Error occurred during finding the command				*/
}COMMANDCHECK_ERROR_CODES;

/*
 * FUNCTIONS
 */
COMMANDCHECK_ERROR_CODES Command_check(char *First_word, char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]);

#endif /* INC_COMMAND_CHECK_H_ */
