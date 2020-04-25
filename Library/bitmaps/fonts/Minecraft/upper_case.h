/**
  ******************************************************************************
  * @file	  			upper_case.h
  *
  * @author 			wouter Berghuis
  * @date 				24 april 2020
  * @brief        		This file contains all the needed defines for the
  * 					upper case letter of the minecraft font
  ******************************************************************************
**/

#include "stdint.h"
#include "bitmap.h"

#ifndef __UPPER_CASE_H
#define __UPPER_CASE_H

#define ALPHABET_LENGTH							26
#define MINECRAFT_UPPER_CASE_CHARACTER_WIDTH  	6
#define MINECRAFT_UPPER_CASE_CHARACTER_HEIGHT 	7

extern const uint8_t Upper_Case_Minecraft[ALPHABET_LENGTH][MINECRAFT_UPPER_CASE_CHARACTER_WIDTH * MINECRAFT_UPPER_CASE_CHARACTER_HEIGHT];

#endif //__UPPER_CASE_H
