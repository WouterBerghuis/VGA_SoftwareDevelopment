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
#include "error.h"

void API_Error_Handler(uint8_t ErrorCode)
{
    uint8_t error = ErrorCode;
    char* message;
    switch(error)
    {
    	case 0:
    		message = "Command successfully executed";
    		API_Uart_Transmit((uint8_t*)message);
        case 1:
        	message = "Error: Placements X coordinates";
        	API_Uart_Transmit((uint8_t*)message);
        case 2:
        	message = "Error: Placements Y coordinates";
        	API_Uart_Transmit((uint8_t*)message);
        case 3:
        	message = "Error: Line could not be placed";
        	API_Uart_Transmit((uint8_t*)message);
        case 4:
        	message = "Error: Could not fill rectangle";
        	API_Uart_Transmit((uint8_t*)message);
        case 5:
        	message = "Error: Received font is not available";
        	API_Uart_Transmit((uint8_t*)message);
        case 6:
        	message = "Error: Received fontsize is not available ";
        	API_Uart_Transmit((uint8_t*)message);
        case 7:
        	message = "Error: Received string doesn't fit on the screen ";
        	API_Uart_Transmit((uint8_t*)message);
        case 8:
        	message = "Error: Error occurred during writing character to VGA RAM";
        	API_Uart_Transmit((uint8_t*)message);
        case 9:
        	message = "Error: Received bitmap number doesn't exist ";
        	API_Uart_Transmit((uint8_t*)message);
        case 10:
        	message = "Error: Command failed to execute";
        	API_Uart_Transmit((uint8_t*)message);
   }

}

