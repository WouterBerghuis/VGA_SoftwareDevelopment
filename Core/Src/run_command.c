/**
  ******************************************************************************
  * @file	  			run_command.c
  *
  * @author 			Stijn Keller
  * @date 				30 April 2020
  * @brief        		This file contains the function which calls the different API-functions
  *
  ******************************************************************************
**/


#include <run_command.h>

/**
  * @brief	This function is used calling the API-functions
  *
  * The first thing that will be checked is if the commandword contains a API-function
  * that can be called.
  *
  * @param	First_word This is the pointer to the first char of the 2D-array, (uint16_t)
  * @param  Commandstringdevided This is the 2D-array where all the data for the command is stored, (char[][])
  * @retval	LINE_ERROR_CODES
  *
  * @see LINE_ERROR_CODES
  */
RUNCOMMANDS_ERROR_CODES Run_Command(char *First_word, char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE])
{
	RUNCOMMANDS_ERROR_CODES errorCommand;
	LINE_ERROR_CODES errorLine;
	RECTANGLE_ERROR_CODES errorRectangle;
	TEXT_ERROR_CODES errorText;
	BITMAP_ERROR_CODES errorBitmap;
	ELLIPSE_ERROR_CODES errorEllipse;

	if 	(strcmp(First_word, "lijn") == 0){
		errorLine = Run_Command_Line(Commandstringdevided);

		if (errorLine == ERROR_LINE_PLACEMENT_XCOOR1||ERROR_LINE_PLACEMENT_XCOOR2){
			errorCommand = 1;
		}
		else if (errorLine == ERROR_LINE_PLACEMENT_YCOOR1||ERROR_LINE_PLACEMENT_YCOOR2){
			errorCommand = 2;
		}
		else
			errorCommand = 0;
	}
	else if (strcmp(First_word, "rechthoek") == 0){
		errorRectangle = Run_Command_Rectangle(Commandstringdevided);

		if (errorRectangle == ERROR_POSITION_X_COOR){
			errorCommand = 1;
		}
		else if (errorRectangle == ERROR_POSITION_Y_COOR){
			errorCommand = 2;
		}
		else if (errorRectangle == ERROR_LINE_PLACEMENT){
			errorCommand = 3;
		}
		else if (errorRectangle == ERROR_FILL_RECTANGLE){
			errorCommand = 4;
		}
		else
			errorCommand = 0;
	}
	else if (strcmp(First_word, "tekst") == 0){
		errorText = Run_Command_Text(Commandstringdevided);

	    if (errorText == ERROR_TEXT_FAILED){
	    	errorCommand = 10;
		}
		else if (errorText == ERROR_FONT_NOT_AVAILABLE){
			errorCommand = 5;
		}
		else if (errorText == ERROR_FONTSIZE_NOT_AVAILABLE){
			errorCommand = 6;
		}
		else if (errorText == ERROR_TEXT_TOO_LONG){
			errorCommand = 7;
		}
		else if (errorText == ERROR_WRITE_CHARACTER){
			errorCommand = 8;
		}
		else
			errorCommand = 0;
	}

	else if (strcmp(First_word, "bitmap") == 0){
		errorBitmap = Run_Command_Bitmap(Commandstringdevided);

		if (errorBitmap == DRAW_BITMAP_FAILED){
			errorCommand = 10;
		}
		else if (errorBitmap == ERROR_BITMAP_NUMBER_UNAVAILABLE){
			errorCommand = 9;
		}
		else if (errorBitmap == EROR_BITMAP_PLACEMENT_RIGHT||ERROR_BITMAP_PLACEMENT_LEFT){
			errorCommand = 1;
		}
		else if (errorBitmap == ERROR_BITMAP_PLACEMENT_TOP||ERROR_BITMAP_PLACEMENT_BOT){
			errorCommand = 2;
		}
	}

	else if (strcmp(First_word, "clearscherm") == 0)
		Run_Command_Clearscreen(Commandstringdevided);

	else if (strcmp(First_word, "cirkel") == 0){
		errorEllipse = Run_Command_Circle(Commandstringdevided);

		if (errorEllipse == DRAW_ELLIPSE_FAILED){
			errorCommand = 10;
		}
		else if (errorEllipse == ERROR_ELLIPSE_POSITION_X_COOR){
			errorCommand = 1;
		}
		else if (errorEllipse == ERROR_ELLIPSE_POSITION_Y_COOR){
			errorCommand = 2;
		}
		else if (errorEllipse == ERROR_PLACEMENT_INDIVIDUAL_LINE){
			errorCommand = 3;
		}
		else
			errorCommand = 0;
	}

	else if (strcmp(First_word, "wacht") == 0)
		Run_Command_Wait(Commandstringdevided);

	else{
		return API_FUNCTION_CALL_FAILED;
	}
	return errorCommand;
}

LINE_ERROR_CODES Run_Command_Line(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	LINE_ERROR_CODES errorLine;
	errorLine = API_Draw_Line(atoi(Commandstringdevided[1]),		// x_coor1
			 	  atoi(Commandstringdevided[2]),		// y_coor1
				  atoi(Commandstringdevided[3]),		// x_coor2
				  atoi(Commandstringdevided[4]),		// y_coor2
				  atoi(Commandstringdevided[5]),		// Color
				  atoi(Commandstringdevided[6]));		// Width
	return errorLine;
}

RECTANGLE_ERROR_CODES Run_Command_Rectangle(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	RECTANGLE_ERROR_CODES errorRectangle;
	errorRectangle = API_Draw_Rectangle(atoi(Commandstringdevided[1]),   // x
			 	  	   atoi(Commandstringdevided[2]),	// y
					   atoi(Commandstringdevided[3]),	// Width
					   atoi(Commandstringdevided[4]),	// Height
					   atoi(Commandstringdevided[5]),	// Color
					   atoi(Commandstringdevided[6]));	// Filled
	return errorRectangle;
}

TEXT_ERROR_CODES Run_Command_Text(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	TEXT_ERROR_CODES errorText;
	errorText = API_Draw_Text(atoi(Commandstringdevided[1]),		// x
			 	  atoi(Commandstringdevided[2]),		// y
				  atoi(Commandstringdevided[3]),		// Color
				 	   Commandstringdevided[4],			// Text
					   Commandstringdevided[5],			// Fontname
			 	  atoi(Commandstringdevided[6]),		// Fontsize
				  atoi(Commandstringdevided[7]));		// Font style
	return errorText;
}

BITMAP_ERROR_CODES Run_Command_Bitmap(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	BITMAP_ERROR_CODES errorBitmap = API_Draw_Bitmap(atoi(Commandstringdevided[2]),		// x
			 	    atoi(Commandstringdevided[3]),		// y
				    atoi(Commandstringdevided[1]));     // Bitmap number
	return errorBitmap;
}

void Run_Command_Clearscreen(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	API_Clearscreen(atoi(Commandstringdevided[1]));		// Color
}

ELLIPSE_ERROR_CODES Run_Command_Circle(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	ELLIPSE_ERROR_CODES errorEllipse;
	errorEllipse = API_Draw_Ellipse(atoi(Commandstringdevided[1]),		// x
			 	    atoi(Commandstringdevided[2]),		// y
				    atoi(Commandstringdevided[3]),		// Height
				 	atoi(Commandstringdevided[4]),		// Width
					atoi(Commandstringdevided[5]));		// Color
	return errorEllipse;
}

void Run_Command_Wait(char Commandstringdevided[MAX_STRINGS_DEVIDED][MAX_COMMANDWORD_SIZE]){
	API_Wait(atoi(Commandstringdevided[1]));     // Milliseconds
}

