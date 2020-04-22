/**
  ******************************************************************************
  * @file	  			smiley_happy.h
  *
  * @author 			Wouter Berghuis
  * @date 				21 April 2020
  * @brief        		This file contains all the needed defines for the
  * 					'smiley_happy' bitmap.
  ******************************************************************************
**/

#include "stdint.h"

#ifndef __SMILEY_HAPPY_H
#define __SMILEY_HAPPY_H

#define SMILEY_HAPPY_WIDTH 		64
#define SMILEY_HAPPY_HEIGHT 	67
#define BITMAP_NUMBER 			0

extern uint8_t smiley_happy[SMILEY_HAPPY_WIDTH * SMILEY_HAPPY_HEIGHT];

#endif //__SMILEY_HAPPY_H
