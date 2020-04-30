/**
  ******************************************************************************
  * @file	  			uart.c
  *
  * @author 			Jered vanLing
  * @date 				23 April 2020
  * @brief        		This file contains the API function responsible for
  * 					transmitting and receiving data over UART2
  ******************************************************************************
**/

#include "uart.h"

UART_ERROR_CODES API_Uart_Transmit(uint8_t *send_data)
{
	HAL_StatusTypeDef error;

 	error = HAL_UART_Transmit_DMA(&huart2, (uint8_t*)send_data, 100);

	if(error == HAL_OK)
		return UART_ACTION_SUCCESFULL;

	else if(error == HAL_BUSY)
		return UART_BUSY;

	else if (error == HAL_TIMEOUT)
		return UART_TIMEOUT;

	else
		return UART_ERROR;
}


UART_ERROR_CODES API_Uart_Receive(uint8_t *incoming)
{
	HAL_StatusTypeDef error;

	error = HAL_UART_Receive_DMA(&huart2, (uint8_t*)incoming, 100);

	if(error == HAL_OK)
		return UART_ACTION_SUCCESFULL;

	else if(error == HAL_BUSY)
		return UART_BUSY;

	else if (error == HAL_TIMEOUT)
		return UART_TIMEOUT;

	else
		return UART_ERROR;
}
