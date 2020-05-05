/**
  ******************************************************************************
  * @file	  			receive_command.h
  *
  * @author 			Jered van Ling
  * @date 				4 May 2020
  * @brief        		This is the header file of wait.c
  *
  ******************************************************************************
**/
#ifndef INC_WAIT_H_
#define INC_WAIT_H_

#include "main.h"

#define TICKS 4000

/*
 * FUNCTIONS
 */
void API_Wait_Init(void);
uint32_t API_Wait(uint32_t ms);


#endif /* INC_WAIT_H */
