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

/*
 * @brief Defines for the minecraft font pack
 */
#define NUMBER_OF_CHARACTERS						91										/**< Number of characters in the minecraft font pack		*/

#define MINECRAFT_SMALL_CHARACTERS_WIDTH  			6										/**< Pixel width of the small/normal minecraft characters   */
#define MINECRAFT_SMALL_CHARACTERS_HEIGHT 			7										/**< Pixel height of the small/normal minecraft characters  */

#define MINECRAFT_SMALL_ITALIC_CHARACTERS_WIDTH		(MINECRAFT_SMALL_CHARACTERS_WIDTH + 2)	/**< Pixel width of the small/italic minecraft characters   */
#define MINECRAFT_SMALL_ITALIC_CHARACTERS_HEIGHT	MINECRAFT_SMALL_CHARACTERS_HEIGHT		/**< Pixel height of the small/italic minecraft characters  */

#define MINECRAFT_SMALL_BOLD_CHARACTERS_WIDTH		(MINECRAFT_SMALL_CHARACTERS_WIDTH * 2)	/**< Pixel width of the small/bold minecraft characters   	*/
#define MINECRAFT_SMALL_BOLD_CHARACTERS_HEIGHT		MINECRAFT_SMALL_CHARACTERS_HEIGHT		/**< Pixel height of the small/bold minecraft characters   	*/

#define MINECRAFT_BIG_CHARACTERS_WIDTH  			(MINECRAFT_SMALL_CHARACTERS_WIDTH * 2)	/**< Pixel width of the big/normal minecraft characters   	*/
#define MINECRAFT_BIG_CHARACTERS_HEIGHT 			(MINECRAFT_SMALL_CHARACTERS_HEIGHT * 2)	/**< Pixel height of the big/normal minecraft characters   	*/

#define MINECRAFT_BIG_ITALIC_CHARACTERS_WIDTH		(MINECRAFT_BIG_CHARACTERS_WIDTH + 2)	/**< Pixel width of the big/italic minecraft characters   	*/
#define MINECRAFT_BIG_ITALIC_CHARACTERS_HEIGHT		MINECRAFT_BIG_CHARACTERS_HEIGHT			/**< Pixel height of the big/italic minecraft characters   	*/

#define MINECRAFT_BIG_BOLD_CHARACTERS_WIDTH  		(MINECRAFT_BIG_CHARACTERS_WIDTH * 2)	/**< Pixel width of the big/bold minecraft characters   	*/
#define MINECRAFT_BIG_BOLD_CHARACTERS_HEIGHT 		MINECRAFT_BIG_CHARACTERS_HEIGHT			/**< Pixel height of the big/bold minecraft characters    	*/

/*
 * @brief Extern definition for the mincraft font pack
 */
extern const uint8_t Minecraft_Font[NUMBER_OF_CHARACTERS][MINECRAFT_SMALL_CHARACTERS_WIDTH * MINECRAFT_SMALL_CHARACTERS_HEIGHT];

#endif // __MINECRAFT_H
