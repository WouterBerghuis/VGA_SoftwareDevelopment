/**
  ******************************************************************************
  * @file	  			run_command.h
  *
  * @author 			Stijn Keller
  * @date 				30 April 2020
  * @brief        		This function calls the different API-functions
  *
  ******************************************************************************
**/

#ifndef INC_RUN_COMMAND_H_
#define INC_RUN_COMMAND_H_

#include <parse.h>
#include <VGA_core.h>
#include <line.h>
#include <bitmap.h>
#include <ellipse.h>
#include <rectangle.h>
#include <text.h>
#include <wait.h>
#include <cube.h>
#include <error.h>


/*
 * @brief 	Returnvalues for calling the API-functions
 *
 */
typedef enum{
	API_FUNCTION_CALL_SUCCESS= 0,			/**< No errors occurred during bitmap placement 							*/
	API_FUNCTION_CALL_FAILED,		/**< Received position of bitmap unavailable, too far right for the screen 	*/
}RUNCOMMANDS_ERROR_CODES;

/*
 * FUNCTIONS
 */
RUNCOMMANDS_ERROR_CODES Run_Command(char *First_word, char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]);

LINE_ERROR_CODES Run_Command_Line(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]);
RECTANGLE_ERROR_CODES Run_Command_Rectangle(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]);
TEXT_ERROR_CODES Run_Command_Text(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]);
BITMAP_ERROR_CODES Run_Command_Bitmap(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]);
void Run_Command_Clearscreen(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]);
ELLIPSE_ERROR_CODES Run_Command_Circle(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]);
CUBE_ERROR_CODES Run_Command_Cube(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]);
void Run_Command_Wait(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]);


#endif /* INC_RUN_COMMAND_H_ */
