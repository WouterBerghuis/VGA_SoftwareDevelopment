/**
  ******************************************************************************
  * @file	  			VGA_core.h
  *
  * @author 			Wouter Berghuis
  * @date 				24 April 2020
  * @brief        		This file is the headerfile of VGA_core.c
  ******************************************************************************
**/

//--------------------------------------------------------------
#ifndef __VGA_core_H
#define __VGA_core_H

/**
  * @brief Includes
  */
#include "main.h"
#include "parse.h"
#include "text.h"

/**
  * @brief 8Bit Color Designation
  *
  * 8Bit color (R3G3B2)
  * Red   (3bit) -> Bit7-Bit5
  * Green (3bit) -> Bit4-Bit2
  * Blue  (2bit) -> Bit1-Bit0
  */
#define  VGA_COL_BLACK          0x00
#define  VGA_COL_BLUE           0x03
#define  VGA_COL_GREEN          0x1C
#define  VGA_COL_RED            0xE0
#define  VGA_COL_WHITE          0xFF
#define  VGA_COL_CYAN           0x1F
#define  VGA_COL_MAGENTA        0xE3
#define  VGA_COL_YELLOW         0xFC
#define  VGA_COL_BROWN 			0x68
#define  VGA_COL_LIGHTMAGENTA	0xF7
#define  VGA_COL_LIGHTBLUE		0x17
#define  VGA_COL_LIGHTGREEN		0xBE
#define  VGA_COL_LIGHTCYAN		0x9F
#define  VGA_COL_LIGHTRED		0x4F
#define  VGA_COL_GREY			0X92

/**
  * @brief Define the VGA_display resolution
  */
#define VGA_DISPLAY_X   320
#define VGA_DISPLAY_Y   240

/**
  * @brief 	Returnvalues for the different core VGA functions
  */
typedef enum{
	VGA_INIT_SUCCESS = 0,
	VGA_INIT_FAILED,
	VGA_CLEARSCREEN_SUCCESS,
	VGA_SETPIXEL_SUCCESS,
	COLOR_FOUND,
	COLOR_NOT_FOUND,
	COLOR_TO_STRING_FAILED,
	COLOR_TO_STRING_SUCCES,
	FONTSTYLE_NOT_FOUND,
	FONTSTYLE_TO_INT_FAILED,
	FONTSTYLE_TO_INT_SUCCESS
}VGA_INIT_ERROR_CODES;

/**
  * @brief 	VGA structure
  */
typedef struct {
  uint16_t hsync_cnt;   /**< Counter						*/
  uint32_t start_adr;   /**< Start_adsress					*/
  uint32_t dma2_cr_reg; /**< Register constant CR-Register	*/
}VGA_t;
VGA_t VGA;

/**
  * @brief 	Display RAM
  */
uint8_t VGA_RAM1[(VGA_DISPLAY_X+1)*VGA_DISPLAY_Y];

/**
  * @brief Timer1 defines
  *
  * Function  = Pixelclock (Speed for  DMA Transfer)
  *
  * basefreq  = 2 * APB2 (APB2=84MHz) => TIM_CLK=168MHz
  * Frq       = 168MHz/1/12 = 14MHz
  */
#define VGA_TIM1_PERIODE      11
#define VGA_TIM1_PRESCALE      0

/**
  * @brief Timer2 defines
  *
  * Function  = CH4 : HSync-Signal on PB11
  *             CH3 : Trigger point for DMA start
  *
  * basefreq  = 2*APB1 (APB1=48MHz) => TIM_CLK=84MHz
  * Frq       = 84MHz/1/2668 = 31,48kHz => T = 31,76us
  * 1TIC      = 11,90ns
  */
#define  VGA_TIM2_HSYNC_PERIODE   2667
#define  VGA_TIM2_HSYNC_PRESCALE     0

#define  VGA_TIM2_HSYNC_IMP        320  /**< HSync-length (3,81us)									*/
#define  VGA_TIM2_HTRIGGER_START   480  /**< HSync+BackPorch (5,71us)								*/
#define  VGA_TIM2_DMA_DELAY         37  /**< Ease the delay when DMA START (Optimization = none)	*/
// #define  VGA_TIM2_DMA_DELAY         30  // ease the delay when DMA START (Optimization = -O1)

/**
  * @brief VSync-Signal
  *
  * Trigger   = Timer2 Update (f=31,48kHz => T = 31,76us)
  * 1TIC      = 31,76us
  */
#define  VGA_VSYNC_PERIODE         525
#define  VGA_VSYNC_IMP               2
#define  VGA_VSYNC_BILD_START       36
#define  VGA_VSYNC_BILD_STOP       514   // (16,38ms)

/**
  * @brief Adress from PORTE (Reg ODR) callback DMA
  *
  * (See page 53+204 of the User Manual(STM32F407) for additional information
  *
  * Data-Bit0 => PE8
  * Data-Bit7 => PE15
  */
#define VGA_GPIOE_BASE_ADR     ((uint32_t)0x40021000) /**< ADR from Port-E			*/
#define VGA_GPIO_ODR_OFFSET    ((uint32_t)0x00000014) /**< ADR from Register ODR	*/
#define VGA_GPIO_BYTE_OFFSET   ((uint32_t)0x00000001) /**< Data for 8bit			*/
#define VGA_GPIOE_ODR_ADDRESS   (VGA_GPIOE_BASE_ADR | VGA_GPIO_ODR_OFFSET | VGA_GPIO_BYTE_OFFSET)

/**
  * @brief Define for black on PE8 - PE15
  */
#define VGA_GPIO_HINIBBLE  ((uint16_t)0xFF00) // GPIO_Pin_8 to GPIO_Pin_15

/**
  * @brief Global variables
  */
uint8_t Background_Color;

/**
  * @brief Global Function call
  */
VGA_INIT_ERROR_CODES API_VGA_Screen_Init(void);
VGA_INIT_ERROR_CODES API_Clearscreen(uint8_t color);
VGA_INIT_ERROR_CODES API_SetPixel(uint16_t xp, uint16_t yp, uint8_t color);
VGA_INIT_ERROR_CODES Check_Color(char *Colorstring, uint8_t *colorValue);
VGA_INIT_ERROR_CODES Color_String_to_Int(char *Colorstring, uint8_t *colorValue);
VGA_INIT_ERROR_CODES Check_Fontstyle(char *Fontstylestring, uint8_t *fontstyleValue);
VGA_INIT_ERROR_CODES Fontstyle_String_to_Int(char *Fontstylestring, uint8_t *fontstyleValue);

#endif // __VGA_core_H
