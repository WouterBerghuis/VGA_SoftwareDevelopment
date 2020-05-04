/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "stdbool.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "bitmap.h"
#include "uart.h"
#include "parse.h"
#include "command_check.h"
#include "run_command.h"
#include "text.h"
#include "bitmap.h"
#include "rectangle.h"
#include "ellipse.h"




/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define MAX_SIZE_MESSAGE 100
#define CARRIAGE_RETURN 13
#define MAX_AMOUNT_OF_COMMANDS 60
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t rx_data;
volatile uint8_t rx_index = 0;
uint8_t rx_buffer[MAX_AMOUNT_OF_COMMANDS][MAX_SIZE_MESSAGE];
uint8_t commando = 0;
uint8_t Message_Counter = 0;
bool New_Message = false;
char Command_word[MAX_COMMANDWORD_SIZE] = {0};
char Commandstring[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE] = {0};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT (&huart2, &rx_data, 1);
  /* Initialize non-CubeMX peripherals */
  API_VGA_Screen_Init();

//  API_Draw_Text(0, 10, VGA_COL_RED,  "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", "Minecraft", 0, 0);
//  API_Draw_Text(0, 20, VGA_COL_BLUE, "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB", "Minecraft", 0, 1);
//  API_Draw_Text(0, 30, VGA_COL_GREEN, "SSSSSSSSSSSSSSSSSSSSSSSSSSS", "Minecraft", 0, 2);
//  API_Draw_Text(0, 50, VGA_COL_RED,  "SSSSSSSSSSSSSSSSSSSSSSSSSSS", "Minecraft", 1, 0);
//  API_Draw_Text(0, 70, VGA_COL_BLUE, "XXXXXXXXXXXXXXXXXXXXXX", "Minecraft", 1, 1);
//  API_Draw_Text(0, 90, VGA_COL_GREEN, "QQQQQQQQQQQQQ", "Minecraft", 1, 2);

   API_Draw_Ellipse(100, 100,20, 60, VGA_COL_RED);
   API_Draw_Ellipse(50, 50,80, 40, VGA_COL_BLUE);
   API_Draw_Ellipse(200, 150, 10, 20, VGA_COL_GREEN);
//  API_Draw_Rectangle(10, 10, 20, 30, VGA_COL_RED, 0);
//  API_Draw_Rectangle(100, 50, 30, 50, VGA_COL_GREEN, 1);

  char Command_word[MAX_COMMANDWORD_SIZE] = {0};
  char Commandstring[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE] = {0};

  char Teststring[]="clearscherm, blauw";  // char array waarin je je string met data zet
  	  //HAL_UART_Transmit(&huart2, (uint8_t*)First, sizeof(First), 1000); // string versturen via uart2

  uart_parser(Teststring, Command_word, Commandstring);

  COMMANDCHECK_ERROR_CODES error_check = Command_check(Command_word, Commandstring);

  if(error_check == CHECK_COMMAND_SUCCESS)
	  Run_Command(Command_word, Commandstring);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  API_Send_Command();
    /* USER CODE END WHILE */

//	  char First[]="STM32 is de bom";  // char array waarin je je string met data zet
//	  //HAL_UART_Transmit(&huart2, (uint8_t*)First, sizeof(First), 1000); // string versturen via uart2
//
//	  uart_parser(First, Command_woord, TwoDarray);

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/**
  * @brief	This function is used to receive the data from the UART interrupt.
  *
  *
  * When data reception is finished, it will be called by the interrupt handler function.
  * Unfortunately the HAL_UART_Receive_IT will only trigger if it received the expected size for the message.
  * To receive a message with unknown lenght, we instead set the expected size for the message to 1 byte.
  * The following steps are followed in this function
  *
  * 1. Checking the runtime of USART 2
  * 2. Check if the received byte is a carriage return.
  * 	2.1 If a carriage return was received, reset the rx_index and put a counter on commando
  * 	so the next message will be stored in a new string
  * 	2.2 If no carriage return was received, store the byte in the rx_buffer.
  *
  * Doing this allows us to store the whole message byte by byte until we read a carriage return (a enter, ascii 13) so the next
  * command can be stored in a new array.
  *
  *
  *@param huart Pointer to the huart handler
  *
  * @retval None
  *
  */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	/** Checks the runtime of USART 2*/
	if (huart->Instance == USART2)
	{
		/**< If the character received is ascii '13' which is carriage return (enter), reset rx_index, put counter on commando and set flag message true */
		if (rx_data == CARRIAGE_RETURN)
		{
			rx_index = 0;
			commando++;
			New_Message = true;
		}
		else
		rx_buffer[commando][rx_index++] = rx_data;


		HAL_UART_Receive_IT (&huart2, &rx_data, 1); /**< receive data (one character at a time) */
	}
}

/**
  * @brief	This function is used to send the received message to the parser
  *
  *The function waits for a New_Message flag to be set to true.
  *This flag will only be set to true when the HAL_UART_RxCpltCallback has determined if a new message is received.
  *When the flag is set to true, the uart_parser function will be called and the message will be sent to the parser.
  *To keep track of the messages a message counter is used to make sure the new message will be send to the parser.
  *The New_Message flag will always be reset to false afterwards to only send the message once to the parser.
  * @param	None
  *
  * @retval	None
  *
  */

void API_Send_Command()
{

	if (New_Message == true)
	{
		API_Uart_Transmit ((uint8_t*)rx_buffer[Message_Counter]);   /**< Transmit the data via uart */
		//uart_parser((uint8_t*)rx_buffer[Message_Counter], Command_word, Commandstring);
		Message_Counter++; 											/**< Keeps track of the messages send */
		New_Message = false;										/**< Reset the New_Message flag */
	}

}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
