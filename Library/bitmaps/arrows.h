/**
  ******************************************************************************
  * @file	  			arrows.h
  *
  * @author 			Wouter Berghuis
  * @date 				22 April 2020
  * @brief        		This file contains all the needed defines for the different
  * 					arrow bitmaps
  ******************************************************************************
**/

#include "stdint.h"

#ifndef __ARROW_H
#define __ARROW_H

#define ARROW_UP_WIDTH				100
#define ARROW_UP_HEIGHT				177
#define BITMAP_NUMBER_ARROW_UP		2

#define ARROW_DOWN_WIDTH			100
#define ARROW_DOWN_HEIGHT			177
#define BITMAP_NUMBER_ARROW_DOWN	3

#define ARROW_RIGHT_WIDTH			177
#define ARROW_RIGHT_HEIGHT			98
#define BITMAP_NUMBER_ARROW_RIGHT	4

#define ARROW_LEFT_WIDTH			177
#define ARROW_LEFT_HEIGHT			98
#define BITMAP_NUMBER_ARROW_LEFT	5

extern const uint8_t arrow_up   [ARROW_UP_WIDTH    * ARROW_UP_HEIGHT];
extern const uint8_t arrow_down [ARROW_DOWN_WIDTH  * ARROW_DOWN_HEIGHT];
extern const uint8_t arrow_right[ARROW_RIGHT_WIDTH * ARROW_RIGHT_HEIGHT];
extern const uint8_t arrow_left [ARROW_LEFT_WIDTH  * ARROW_LEFT_HEIGHT];


#endif //__ARROW_H
