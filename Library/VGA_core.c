/**
  ******************************************************************************
  * @file	  			VGA_core.c
  *
  * @author 			Wouter Berghuis
  * @date 				24 April 2020
  * @brief        		This file contains all the core functions for controlling the VGA screen.
  *
  * The VGA screen is controlled outside the main functions loop. This is done with
  * the use of Timers (TIM1 and TIM2) and the DMA (DMA2, Channel6 and Stream5). These
  * will control the different GPIO-pins connected to the VGA connector.
  *
  * Signal: 	PB11      = HSync-Signal
  *         	PB12      = VSync-Signal
  *         	PE8+PE9   = Color Blue
  *         	PE10-PE12 = Color Green
  *         	PE13-PE15 = Color red
  *
  * VGA out:	320x240 Pixel
  * 			8bit color
  *
  ******************************************************************************
**/

/*
 * @brief Includes
 */
#include "VGA_core.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern DMA_HandleTypeDef hdma_tim1_up;

/**
  * @brief	This function initialized the VGA screen.
  *
  * The initialization consist of the following steps:
  * 1. Setting timer2
  * 	Channel 4 is the HSync-signal
  * 	Channel 3 is the trigger point for the DMA start
  * 2. Enabling the DMA which uses timer1
  * 	The DMA is used to send the 8bit color to the VGA color pins from
  * 	the VGA_RAM. In these RAM the color for each individual pixel can be set.
  * 3. Clear the screen
  * 	The screen is set to full black after initializing the VGA_screen.
  *
  * @param	void
  * @retval	VGA_INIT_ERROR_CODES
  *
  * @see VGA_INIT_ERROR_CODES
  */
VGA_INIT_ERROR_CODES API_VGA_Screen_Init(void)
{
	HAL_StatusTypeDef errorHAL;
	VGA_INIT_ERROR_CODES errorVGA;
	VGA.hsync_cnt = 0;
	VGA.start_adr = 0;
	VGA.dma2_cr_reg = 0;

	GPIOB->BSRR = VGA_VSYNC_Pin;

	// TIM2
	errorHAL |= HAL_TIM_Base_Start(&htim2);
	errorHAL |= HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
	errorHAL |= HAL_TIM_PWM_Start_IT(&htim2, TIM_CHANNEL_3);

	// TIM1
	__HAL_TIM_ENABLE_DMA(&htim1, TIM_DMA_UPDATE);
	__HAL_TIM_ENABLE(&htim1);
	errorHAL |= HAL_DMA_Start_IT(&hdma_tim1_up, (uint32_t)&VGA_RAM1[0], VGA_GPIOE_ODR_ADDRESS, VGA_DISPLAY_X + 1);

	errorHAL |= HAL_DMA_Init(&hdma_tim1_up);
	__HAL_DMA_ENABLE_IT(&hdma_tim1_up, DMA_IT_TC);

	//-----------------------
	// Register swap and safe
	//-----------------------
	// content of CR-Register read and save
	VGA.dma2_cr_reg = DMA2_Stream5->CR;

	if(errorHAL)
		return VGA_INIT_FAILED;

	errorVGA = API_Clearscreen(VGA_COL_BLACK);

	if(errorVGA != VGA_CLEARSCREEN_SUCCESS)
		return VGA_INIT_FAILED;

	return VGA_INIT_SUCCESS;
}


/**
  * @brief	This function clears the screen
  *
  * Clearing the screen is done by setting the whole screen to one color.
  * This is done by setting each individual pixel to a specific color.
  *
  * @param	color The color of screen to clear the screen with, (uint8_t)
  * @retval	VGA_INIT_ERROR_CODES
  *
  * @see VGA_INIT_ERROR_CODES
  */
VGA_INIT_ERROR_CODES API_Clearscreen(uint8_t color)
{
	uint16_t xp,yp;

	for(yp = 0; yp < VGA_DISPLAY_Y; yp++) {
		for(xp = 0; xp < VGA_DISPLAY_X; xp++) {
			API_SetPixel(xp, yp, color);
		}
	}
	return VGA_CLEARSCREEN_SUCCESS;
}

/**
  * @brief	This function sets the color of a single pixel
  *
  * Setting the color of a single pixel is done by writing the color code
  * in the VGA_RAM. The position in the RAM corresponds with the coordinates
  * on the screen.
  *
  * Important : The last Pixel+1 from every line must be black
  *				The reason for this is still unclear
  *
  * @param	xp The x-coordinate of the pixel, (uint16_t)
  * @param	yp The y-coordinate of the pixel, (uint16_t)
  * @param	color The color of screen to clear the screen with, (uint8_t)
  * @retval	VGA_INIT_ERROR_CODES
  *
  * @see VGA_INIT_ERROR_CODES
  */
VGA_INIT_ERROR_CODES API_SetPixel(uint16_t xp, uint16_t yp, uint8_t color)
{
	if(xp >= VGA_DISPLAY_X)
		xp = 0;
	if(yp >= VGA_DISPLAY_Y)
		yp = 0;

	// Write pixel to ram
	VGA_RAM1[(yp * (VGA_DISPLAY_X + 1)) + xp] = color;

	return VGA_SETPIXEL_SUCCESS;
}

/**
  * @brief	This function checks the colour of the string
  *
  * @param	Colour Pointer to the string that contains the colour, (char *)
  * @retval	VGA_INIT_ERROR_CODES
  *
  * @see VGA_INIT_ERROR_CODES
  */
VGA_INIT_ERROR_CODES Check_Color(char *Color, uint8_t *colorValue){

	VGA_INIT_ERROR_CODES error;
	if (strcmp(Color, "zwart") == 0){
		error = Color_String_to_Int(Color, colorValue);
		return COLOR_FOUND;
	}

	else if (strcmp(Color, "blauw") == 0){

		return COLOR_FOUND;
	}

	else if (strcmp(Color, "lichtblauw") == 0){

		return COLOR_FOUND;
	}

	else if (strcmp(Color, "groen") == 0){

		return COLOR_FOUND;
	}

	else if (strcmp(Color, "lichtgroen") == 0){

		return COLOR_FOUND;
	}

	else if (strcmp(Color, "cyaan") == 0){

		return COLOR_FOUND;
	}

	else if (strcmp(Color, "lichtcyaan") == 0){

		return COLOR_FOUND;
	}

	else if (strcmp(Color, "rood") == 0){

		return COLOR_FOUND;
	}

	else if (strcmp(Color, "lichtrood") == 0){

		return COLOR_FOUND;
	}

	else if (strcmp(Color, "magenta") == 0){

		return COLOR_FOUND;
	}

	else if (strcmp(Color, "lichtmagenta") == 0){

		return COLOR_FOUND;
	}

	else if (strcmp(Color, "bruin") == 0){

		return COLOR_FOUND;
	}

	else if (strcmp(Color, "geel") == 0){

		return COLOR_FOUND;
	}

	else if (strcmp(Color, "grijs") == 0){

		return COLOR_FOUND;
	}

	else if (strcmp(Color, "wit") == 0){

		return COLOR_FOUND;
	}
	else
		return COLOR_NOT_FOUND;
}

/**
  * @brief	This function returns the decimal value of the colour sent to the function
  *
  * @param	Colour Pointer to the string that contains the colour, (char *)
  * @retval	VGA_INIT_ERROR_CODES
  *
  * @see VGA_INIT_ERROR_CODES
  */
VGA_INIT_ERROR_CODES Color_String_to_Int(char *Colorstring, uint8_t *Colorvalue)
{

	if (strcmp(Colorstring, "zwart") == 0)
		*Colorvalue = VGA_COL_BLACK ;

	else if (strcmp(Colorstring, "blauw") == 0)
		*Colorvalue = VGA_COL_BLUE ;

	else if (strcmp(Colorstring, "lichtblauw") == 0)
		*Colorvalue = 23;

	else if (strcmp(Colorstring, "groen") == 0)
		*Colorvalue = VGA_COL_GREEN ;

	else if (strcmp(Colorstring, "lichtgroen") == 0)
		*Colorvalue = 157;

	else if (strcmp(Colorstring, "cyaan") == 0)
		*Colorvalue = VGA_COL_CYAN ;

	else if (strcmp(Colorstring, "lichtcyaan") == 0)
		*Colorvalue = 31;

	else if (strcmp(Colorstring, "rood") == 0)
		*Colorvalue = VGA_COL_RED;

	else if (strcmp(Colorstring, "lichtrood") == 0)
		*Colorvalue = 233;

	else if (strcmp(Colorstring, "magenta") == 0)
		*Colorvalue = VGA_COL_MAGENTA;

	else if (strcmp(Colorstring, "lichtmagenta") == 0)
		*Colorvalue = 243;

	else if (strcmp(Colorstring, "bruin") == 0)
		*Colorvalue = VGA_COL_BROWN;

	else if (strcmp(Colorstring, "geel") == 0)
		*Colorvalue = VGA_COL_YELLOW;

	else if (strcmp(Colorstring, "grijs") == 0)
		*Colorvalue = 146;

	else if (strcmp(Colorstring, "wit") == 0)
		*Colorvalue = VGA_COL_WHITE;

	else
		return COLOR_TO_STRING_FAILED;

	return COLOR_TO_STRING_SUCCES;
}
