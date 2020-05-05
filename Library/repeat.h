/**
  ******************************************************************************
  * @file	  			repeat.h
  *
  * @author 			Jered van Ling
  * @date 				5 May 2020
  * @brief        		This is the header file of repeat.c
  *
  ******************************************************************************
**/
#ifndef INC_REPEAT_H_
#define INC_REPEAT_H_

#include <parse.h>
#include "command_check.h"
#include "run_command.h"
#include "stdbool.h"
#include "uart.h"
#include "main.h"

#define MAX_SIZE_MESSAGE 100
#define MAX_AMOUNT_OF_COMMANDS 300
/**
  * @brief 	Returnvalues for the API_Repeat function
  */
typedef enum{
	REPEAT_COMMAND_SUCCESS = 0,			/**< No errors occurred during finding the command			*/
	REPEAT_COMMAND_FAILED, 			/**< Error occurred during finding the command				*/
}REPEAT_ERROR_CODES;

/*
 * FUNCTIONS
 */
REPEAT_ERROR_CODES API_Repeat(uint8_t command, uint8_t repeats);


#endif /* INC_REPEAT_H */
