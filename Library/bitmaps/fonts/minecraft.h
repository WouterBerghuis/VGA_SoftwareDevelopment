/**
  ******************************************************************************
  * @file	  			minecraft.h
  *
  * @author 			Wouter Berghuis
  * @date 				25 april 2020
  * @brief        		This file contains all the needed defines for the
  * 					Minecraft font. This font supports both upper, lower case
  * 					a range of special characters.
  *
  ******************************************************************************
**/

#ifndef __MINECRAFT_H
#define __MINECRAFT_H

#include "stdint.h"
#include "bitmap.h"

#define NUMBER_OF_CHARACTERS			91
#define MINECRAFT_CHARACTERS_WIDTH  	6
#define MINECRAFT_CHARACTERS_HEIGHT 	7

extern const uint8_t Minecraft_Font[NUMBER_OF_CHARACTERS][MINECRAFT_CHARACTERS_WIDTH * MINECRAFT_CHARACTERS_HEIGHT];

#endif // __MINECRAFT_H
