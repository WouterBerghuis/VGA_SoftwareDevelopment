/**
  ******************************************************************************
  * @file	  			lower_case.h
  *
  * @author 			wouter Berghuis
  * @date 				25 april 2020
  * @brief        		This file contains all the needed defines for the
  * 					lower case letter of the minecraft font
  ******************************************************************************
**/

#include "stdint.h"
#include "bitmap.h"

#ifndef __LOWER_CASE_H
#define __LOWER_CASE_H

#define ALPHABET_LENGTH							26
#define MINECRAFT_LOWER_CASE_CHARACTER_WIDTH  	6
#define MINECRAFT_LOWER_CASE_CHARACTER_HEIGHT 	7

extern const uint8_t Lower_Case_Minecraft[ALPHABET_LENGTH][MINECRAFT_LOWER_CASE_CHARACTER_WIDTH * MINECRAFT_LOWER_CASE_CHARACTER_HEIGHT];

#endif //__LOWER_CASE_H
