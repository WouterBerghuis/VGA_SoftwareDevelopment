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
    char *message;
    switch(error)
    {
    	case 0:
    		message = "Command successfully executed\n";
    		API_Uart_Transmit((uint8_t*)message);
    		break;
        case 1:
        	message = "Error: Placements X coordinates\n";
        	API_Uart_Transmit((uint8_t*)message);
        	break;
        case 2:
        	message = "Error: Placements Y coordinates\n";
        	API_Uart_Transmit((uint8_t*)message);
        	break;
        case 3:
        	message = "Error: Line could not be placed\n";
        	API_Uart_Transmit((uint8_t*)message);
        	break;
        case 4:
        	message = "Error: Could not fill rectangle\n";
        	API_Uart_Transmit((uint8_t*)message);
        	break;
        case 5:
        	message = "Error: Received font is not available\n";
        	API_Uart_Transmit((uint8_t*)message);
        	break;
        case 6:
        	message = "Error: Received fontsize is not available\n";
        	API_Uart_Transmit((uint8_t*)message);
        	break;
        case 7:
        	message = "Error: Received string doesn't fit on the screen\n";
        	API_Uart_Transmit((uint8_t*)message);
        	break;
        case 8:
        	message = "Error: Error occurred during writing character to VGA RAM\n";
        	API_Uart_Transmit((uint8_t*)message);
        	break;
        case 9:
        	message = "Error: Received bitmap number doesn't exist\n";
        	API_Uart_Transmit((uint8_t*)message);
        	break;
        case 10:
        	message = "Error: Command failed to execute\n";
        	API_Uart_Transmit((uint8_t*)message);
        	break;
   }

}

