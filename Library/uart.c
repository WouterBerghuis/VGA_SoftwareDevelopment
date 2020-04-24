/**
  ******************************************************************************
  * @file	  			uart.c
  *
  * @author 			Jered vanLing
  * @date 				23 April 2020
  * @brief        		This file contains all API function responsible for
  * 					transmitting and receiving data over UART2
  ******************************************************************************
**/

#include "uart.h"

UART_ERROR_CODES API_Uart_Transmit(char *send_data)
{
	HAL_StatusTypeDef error;
	//HAL_UART_Transmit(&huart2, (uint8_t*)send_data, sizeof(send_data), 1000);

 	error = HAL_UART_Transmit(&huart2, (uint8_t*)send_data, sizeof(send_data), 1000);

	if(error == HAL_OK)
		return UART_ACTION_SUCCESFULL;

	else if(error == HAL_BUSY)
		return UART_BUSY;

	else if (error == HAL_TIMEOUT)
		return UART_TIMEOUT;

	else
		return UART_ERROR;

}


UART_ERROR_CODES API_Uart_Receive()
{
	char *in;
	HAL_UART_Receive(&huart2, (uint8_t*)in, sizeof(in), 1000);
	return UART_ACTION_SUCCESFULL;
}
