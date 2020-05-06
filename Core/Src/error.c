/**
  *********************************************************************************
  * @file	  			error.c
  *
  * @author 			Stijn Keller, Jered van Ling
  * @date 				5 May 2020
  * @brief        		This file contains the function that handles error
  * 					and informs the user.
  *
  *********************************************************************************
**/

void API_Error_Handler(uint8_t ErrorCode)
{

	API_Uart_Transmit (ErrorCode);

}

