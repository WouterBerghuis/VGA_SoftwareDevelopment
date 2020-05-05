/**
  *********************************************************************************
  * @file	  			wait.c
  *
  * @author 			Jered van Ling
  * @date 				4 May 2020
  * @brief        		This file contains the function that runs the API_Wait
  * 					function.
  *
  *********************************************************************************
**/

#include <wait.h>
uint32_t G_CLK;
uint32_t D_mS;

/**
  * @brief	This function is used to get the clock frequency and calculate how many ticks equals 1 millisecond
  *
  *The function request the current clock frequency from HAL_RCC_GetSysClockFreq(); and stores it in G_CLK
  *For this application a clock speed of 168MHz is used, the value received from HAL_RCC_GetSysClockFreq();
  *will be 168000000.
  *Because a while loop takes 4 ticks, the 168MHz is divided by 4000 to equal 1 millisecond to elapse.
  *The amount of ticks needed wait 1 millisecond is calculated at 42000 ticks.
  *
  * @retval	None
  *
  */

void API_Wait_Init()
{
	  G_CLK = HAL_RCC_GetSysClockFreq();		/**< Request the set clock frequency and store it in G_CLK */
	  D_mS = (G_CLK / TICKS);					/**< Calculate the clock ticks needed to wait 1 millisecond*/
}

/**
  * @brief	This function is used to wait the amount of milliseconds the user wants.
  *
  *
  * @param	ms This is the amount of milliseconds the user want to wait(uint32_t ms)
  *
  * @retval	0 Return a zero when the function is done.
  *
  */

uint32_t API_Wait(uint32_t ms)
{
  /* Multiply micros with multipler */
  /* Substract 10 */
  ms = ms * D_mS;
  /* 4 cycles for one loop */
  while (ms--);
  return 0;
}
