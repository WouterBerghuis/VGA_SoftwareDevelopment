/**
  *********************************************************************************
  * @file	  			error.h
  *
  * @author 			Stijn Keller, Jered van Ling
  * @date 				5 May 2020
  * @brief        		This file contains the function that handles error
  * 					and informs the user.
  *
  *********************************************************************************
**/
#ifndef ERROR_H_
#define ERROR_H_

#include "main.h"
#include "uart.h"
/*
 * FUNCTIONS
 */
void 			API_Error_Handler(uint8_t ErrorCode);

#endif /* INC_WAIT_H */
