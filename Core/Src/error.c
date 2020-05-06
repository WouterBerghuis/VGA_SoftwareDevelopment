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
    uint8_t message;
    switch(error)
    {
    	case 0:
        	message = "Command successfully executed";
        	API_UART_Transmit(message);
        case 1:
        	message = "Error: Placements X coordinates";
        	API_UART_Transmit(message);
        case 2:
        	message = "Error: Placements Y coordinates";
        	API_UART_Transmit(message);
        case 3:
        	message = "Error: Line could not be placed";
        	API_UART_Transmit(message);
        case 4:
        	message = "Error: Could not fill rectangle";
        	API_UART_Transmit(message);
        case 5:
        	message = "Error: Received font is not available";
        	API_UART_Transmit(message);
        case 6:
        	message = "Error: Received fontsize is not available ";
        	API_UART_Transmit(message);
        case 7:
        	message = "Error: Received string doesn't fit on the screen ";
        	API_UART_Transmit(message);
        case 8:
        	message = "Error: Error occurred during writing character to VGA RAM";
        	API_UART_Transmit(message);
        case 9:
        	message = "Error: Received bitmap number doesn't exist ";
        	API_UART_Transmit(message);

        default:
        	message = "Error: Command failed to execute";
        	API_UART_Transmit(message);

   }

}

