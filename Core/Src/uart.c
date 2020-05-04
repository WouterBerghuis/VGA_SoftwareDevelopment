/**
  ******************************************************************************
  * @file	  			uart.c
  *
  * @author 			Jered vanLing
  * @date 				23 April 2020
  * @brief        		This file contains the API function responsible for
  * 					transmitting data over UART2
  ******************************************************************************
**/

#include "uart.h"

/**
  * @brief	This function is used to transmit a string over the UART2
  *
  *To transmit data over UART2 to a terminal for example, the HAL_UART_Transmit function is used.
  *This function was made to transmit a string
  *
  *@param send_data Pointer to the location of the string that will be transmitted
  *
  * @retval	UART_ERROR_CODES
  *
  * @see UART_ERROR_CODES
  */
UART_ERROR_CODES API_Uart_Transmit(uint8_t *send_data)
{
	HAL_StatusTypeDef error;

 	error = HAL_UART_Transmit(&huart2, (uint8_t*)send_data, MAX_SIZE_MESSAGE, TIMEOUT);

	if(error == HAL_OK)
		return UART_ACTION_SUCCESFULL;

	else if(error == HAL_BUSY)
		return UART_BUSY;

	else if (error == HAL_TIMEOUT)
		return UART_TIMEOUT;

	else
		return UART_ERROR;
}

