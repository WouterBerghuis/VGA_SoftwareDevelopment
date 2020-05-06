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
    uint8_t message[60];
    switch(error)
    {
    	case 0:
    		strcpy((char*)message, "Command successfully executed\n");
    		break;
        case 1:
    		strcpy((char*)message, "Error: Placements X coordinates\n");

        	break;
        case 2:
    		strcpy((char*)message, "Error: Placements Y coordinates\n");

        	break;
        case 3:
    		strcpy((char*)message, "Error: Line could not be placed\n");

        	break;
        case 4:
    		strcpy((char*)message, "Error: Could not fill rectangle\n");

        	break;
        case 5:
    		strcpy((char*)message, "Error: Received font is not available\n");

        	break;
        case 6:
    		strcpy((char*)message, "Error: Received fontsize is not available\n");

        	break;
        case 7:
    		strcpy((char*)message, "Error: Received string doesn't fit on the screen\n");

        	break;
        case 8:
    		strcpy((char*)message, "Error occurred during writing character to VGA RAM\n");

        	break;
        case 9:
    		strcpy((char*)message, "Received bitmap number doesn't exist\n");

        	break;
        case 10:
    		strcpy((char*)message, "Error: Command failed to execute\n");

        	break;

        default: strcpy((char*)message,"Error: Error in error handling");
   }
	API_Uart_Transmit(message);
}

