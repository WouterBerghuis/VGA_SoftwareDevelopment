/**
  ******************************************************************************
  * @file	  			bitmap.h
  *
  * @author 			Jered van Ling
  * @date 				23 April 2020
  * @brief        		This file is the headerfile of uart.c
  ******************************************************************************
**/

#ifndef __UART_H
#define __UART_H

#include "usart.h"


#define TIMEOUT 100
#define MAX_SIZE_MESSAGE 100

/*
 * @brief 	Returnvalues for API_Uart_transmit function. These can be used for
 * 			errorhandling.
 *
 */
/*
 * ENUMERATIONS
 */
typedef enum{
	UART_ACTION_SUCCESFULL = 0,			/**< No errors occurred when receiving or transmitting with UART2 	*/
	UART_BUSY,							/**< UART line is already occupied									*/
	UART_TIMEOUT,						/**< This error is given when the set timeout has been exceeded		*/
	UART_ERROR,							/**< General error (e.g. no data in sending message)				*/
}UART_ERROR_CODES;

/*
 * FUNCTIONS
 */

UART_ERROR_CODES API_Uart_Transmit(uint8_t *send_data);

#endif	/**< __UART_H*/
