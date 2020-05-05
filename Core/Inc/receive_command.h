/**
  ******************************************************************************
  * @file	  			receive_command.h
  *
  * @author 			Jered van Ling
  * @date 				4 May 2020
  * @brief        		This is the header file of receive_command.c
  *
  ******************************************************************************
**/

#ifndef INC_RECEIVE_COMMAND_H
#define INC_RECEIVE_COMMAND_H

#include <parse.h>
#include "command_check.h"
#include "run_command.h"
#include "stdbool.h"
#include "uart.h"
#include "main.h"

#define MAX_SIZE_MESSAGE 100
#define MAX_AMOUNT_OF_COMMANDS 300

void API_Send_Command(void);
void API_Execute_Command(void);

#endif /*INC_RECEIVE_COMMAND_H_*/
