/**
  ******************************************************************************
  * @file	  			special_character.h
  *
  * @author 			Wouter Berghuis
  * @date 				25 april 2020
  * @brief        		This file contains all the needed defines for the
  * 					special character of the minecraft font
  ******************************************************************************
**/

#include "stdint.h"
#include "bitmap.h"

#ifndef __SPECIAL_CHARACTER_H
#define __SPECIAL_CHARACTER_H

#define SPECIAL_CHARACTER_LENGTH						33
#define MINECRAFT_SPECIAL_CHARACTER_CHARACTER_WIDTH  	6
#define MINECRAFT_SPECIAL_CHARACTER_CHARACTER_HEIGHT 	7

extern const uint8_t Special_Character_Minecraft[SPECIAL_CHARACTER_LENGTH][MINECRAFT_SPECIAL_CHARACTER_CHARACTER_WIDTH * MINECRAFT_SPECIAL_CHARACTER_CHARACTER_HEIGHT];

#endif //__SPECIAL_CHARACTER_H
