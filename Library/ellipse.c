/**
  ******************************************************************************
  * @file	  			ellipse.c
  *
  * @author 			Wouter Berghuis
  * @date 				1 mei 2020
  * @brief        		This file contains all API function responsible for drawing an
  * 					ellipse on the screen.
  *
  ******************************************************************************
  **/

#include "ellipse.h"

/**
  * @brief	This function is used for drawing an ellipse on the VGA screen.
  *
  * Drawing an ellipse on the screen consist of multiple steps. These steps are:
  * 1. Check the received position of the ellipse
  * 	Does the ellipse fit on the screen with the received position and height/width.
  * 	The function will return an error if the ellipse doesn't fit on the screen.
  * 2. Calculate the individual points of the ellipse
  * 	An ellipse consist of two parabolas, the coordinates of the bottom parabola are calculated. Using these coordinates and
  * 	the center point the top (opposite) parabola is calculated.
  * 3. Check if there is a big jump for old to new point on the y-axis
  * 	If there is a big jump (> 1) an line is drawn between the two points.
  * 	This will fill in the gaps between the two calculated points.
  * 4. Write calculated ellipse point to the VGA RAM
  *
  * @param	x_coor_center 	This is the x-coordinate of the center of the ellipse, 	(uint16_t)
  * @param  y_coor_center 	This is the y-coordinate of the center of the ellipse, 	(uint16_t)
  * @param  width  			This is the width of the ellipse,						(uint16_t)
  * @param  height 			This is the height of the ellipse, 						(uint16_t)
  * @param  color  			This is the color with which the ellipse is drawn, 		(uint8_t)
  *
  * @retval	ELLIPSE_ERROR_CODES
  *
  * @see ELLIPSE_ERROR_CODES
  */
ELLIPSE_ERROR_CODES API_Draw_Ellipse(uint16_t x_coor_center, uint16_t y_coor_center, uint16_t width, uint16_t height, uint8_t color){

	ELLIPSE_ERROR_CODES  Ellipse_error  = 0;
	VGA_INIT_ERROR_CODES VGA_error 		= 0;
	uint16_t start_x_coor 				= x_coor_center - (width/2);
	uint16_t end_x_coor					= (width / 2) + x_coor_center + 1;
	uint16_t y_coor_ellipse 			= 0;
	uint16_t old_y_coor_ellipse_bot		= y_coor_center;
	uint16_t old_y_coor_ellipse_top		= y_coor_center;

	Ellipse_error = API_Check_Ellipse_Position(x_coor_center, y_coor_center, height, width);
	if(Ellipse_error != CORRECT_ELLIPSE_POSITION)
		return Ellipse_error;

	for(uint16_t i = start_x_coor; i < end_x_coor; i++){

	/* BOT PARABOLA	*/
		// Calculate y_coordinate for bottom-parabola of the ellipse
		Ellipse_error = API_Calculate_Point_On_Ellipse(x_coor_center, y_coor_center, (float)width, (float)height, i, &y_coor_ellipse);
		if(Ellipse_error != CALCULATE_POINT_ON_ELLIPSE_SUCCESS)
			return Ellipse_error;

		// If the jump to new point on the ellipse is bigger then one pixel a line is drawn
		bool y_coor_jump = API_Check_Jump_in_Y_Coor(y_coor_ellipse, old_y_coor_ellipse_bot);
		if(y_coor_jump){
			Ellipse_error= API_Draw_Ellipse_Line(i, x_coor_center, y_coor_ellipse, old_y_coor_ellipse_bot, color);
			if(Ellipse_error != ELLIPSE_LINE_PLACEMENT_SUCCESS)
				return Ellipse_error;
		}
		// Write point of ellipse to VGA RAM
		VGA_error = API_SetPixel(i, y_coor_ellipse, color);
		if(VGA_error != VGA_SETPIXEL_SUCCESS)
			return VGA_error;

		old_y_coor_ellipse_bot = y_coor_ellipse;

	/* TOT PARABOLA	*/
		// Calculate y_coordinate for top-parabola of the ellipse
		y_coor_ellipse = y_coor_ellipse - y_coor_center;		// Calculate difference
		y_coor_ellipse = y_coor_center  - y_coor_ellipse;		// Calculate y-coor

		// If the jump to new point on the ellipse is bigger then one pixel a line is drawn
		if(y_coor_jump){
			API_Draw_Ellipse_Line(i, x_coor_center, y_coor_ellipse, old_y_coor_ellipse_top, color);
			if(Ellipse_error != ELLIPSE_LINE_PLACEMENT_SUCCESS)
			return Ellipse_error;
		}

		// Write point of ellipse to VGA RAM
		VGA_error = API_SetPixel(i, y_coor_ellipse, color);
		if(VGA_error != VGA_SETPIXEL_SUCCESS)
			return VGA_error;

		old_y_coor_ellipse_top = y_coor_ellipse;
	}

	return DRAW_ELLIPSE_SUCCESS;
}

/**
  * @brief	This function is used for checking to position of the ellipse
  *
  * This function returns an errormessage if the received position doesn't fit on the screen.
  *
  * @param	x_coor_center 	This is the x-coordinate of the center of the ellipse, 	(uint16_t)
  * @param  y_coor_center 	This is the y-coordinate of the center of the ellipse, 	(uint16_t)
  * @param  width  			This is the width of the ellipse,						(uint16_t)
  * @param  height 			This is the height of the ellipse, 						(uint16_t)
  *
  * @retval	ELLIPSE_ERROR_CODES
  *
  * @see ELLIPSE_ERROR_CODES
  */
ELLIPSE_ERROR_CODES API_Check_Ellipse_Position(uint16_t x_coor_center, uint16_t y_coor_center, uint16_t width, uint16_t height){

	// Check horizontal position
	if(x_coor_center - (width / 2) < 0)					// Ellipse placed to far to the left
		return ERROR_ELLIPSE_POSITION_X_COOR;

	if(x_coor_center + (width / 2) > VGA_DISPLAY_X)		// Ellipse placed to far to the right
		return ERROR_ELLIPSE_POSITION_X_COOR;

	// Check vertical position
	if(y_coor_center - (height / 2) < 0)				// Ellipse placed too far top
		return ERROR_ELLIPSE_POSITION_Y_COOR;

	if(y_coor_center + (height / 2) > VGA_DISPLAY_Y) 	// Ellipse placed too far bottom
		return ERROR_ELLIPSE_POSITION_Y_COOR;

	return CORRECT_ELLIPSE_POSITION;
}

/**
  * @brief	This function is used for calculating individual coordinates of the ellipse
  *
  * The calculation is based on the following formula: \f$\frac{(x - h)^2}{a^2}+\frac{(x - k)^2}{b^2}= 1\f$
  * - x = x-coordinate
  * - y = y-coordinate
  * - h = x-coordinate of the center
  * - k = y-coordinate of the center
  *	- a = Radius of the width
  *	- b = Radius of the heigth
  *
  * If you solve for Y the formula is equal to: \f$y = \pm\sqrt{\frac{(a^2\cdot b^2)-(b^2(x - h)^2)}{a^2}} + k\f$
  * Using this equation the y-coordinate of a point on the ellipse is calculated. For an easier to read and write code the
  * formula is divided into the following three sections:
  * - Section one: \f$(a^2\cdot b^2)\f$
  * - Section two: \f$(b^2(x - h)^2)\f$
  * - Section three: \f$\frac{(a^2\cdot b^2)-(b^2(x - h)^2)}{a^2}\f$
  *
  * There is one special case with this formula. This is if section three is smaller then 0. In this case the
  * y-coordinate is equal to y-coordinate of the center.
  *
  * @param	x_coor_center 	This is the x-coordinate of the center of the ellipse, 	  		(uint16_t)
  * @param  y_coor_center 	This is the y-coordinate of the center of the ellipse, 	  		(uint16_t)
  * @param  width  			This is the width of the ellipse,						  		(uint16_t)
  * @param  height 			This is the height of the ellipse, 						  		(uint16_t)
  * @param  x_coor_ellipse 	This is the current x-coordinate of the point on ellipse, 		(uint16_t)
  * @param  y_coor_ellipse 	This is a pointer where the calculated y-coordinate is stored,	(uint16_t *)
  *
  * @retval	ELLIPSE_ERROR_CODES
  *
  * @see ELLIPSE_ERROR_CODES
  */
ELLIPSE_ERROR_CODES API_Calculate_Point_On_Ellipse(uint16_t x_coor_center, uint16_t y_coor_center, float width, float height,
													uint16_t x_coor_ellipse, uint16_t *y_coor_ellipse){

	float radius_width_sqrt  = __Square_Number((float)(width / 2));
	float radius_height_sqrt = __Square_Number((float)(height / 2));

	float formula_section_one 			= radius_width_sqrt * radius_height_sqrt;

	float formula_section_two	 		= x_coor_ellipse - x_coor_center;
	formula_section_two 				= __Square_Number(formula_section_two);
	formula_section_two 			   *= radius_height_sqrt;

	float formula_section_three 		= formula_section_one - formula_section_two;
	formula_section_three			   /= radius_width_sqrt;

	if(formula_section_three < 0)
		*y_coor_ellipse = y_coor_center;
	else{
		formula_section_three 				= sqrt(formula_section_three);
		*y_coor_ellipse = (round(formula_section_three) + y_coor_center);
	}

	return CALCULATE_POINT_ON_ELLIPSE_SUCCESS;
}

/**
  * @brief	This function is used for drawing vertical filling lines for the ellipse
  *
  * This function uses the API_Draw_Lijne function to draw a line between two points on the ellipse.
  * Depending on the position on the ellipse the line is different. In the case of the first half of
  * both parabolas the line is on the previous x-coordinate. On the second half the y-coordinate is different, either
  * -1 or +1 depending on the bottom or top parabola.
  *
  * @param	x_coor 			This is the x-coordinate for the line, 	  						(uint16_t)
  * @param  x_coor_center 	This is the x-coordinate of the center of the ellipse, 	  		(uint16_t)
  * @param  y_coor_one 		Y-coordinate of the begin point of the line, 					(uint16_t)
  * @param  y_coor_two 		Y-coordinate of the end point of the line,						(uint16_t)
  * @param  color 			The color of the to draw line									(uint8_t)
  *
  * @retval	ELLIPSE_ERROR_CODES
  *
  * @see ELLIPSE_ERROR_CODES
  */
ELLIPSE_ERROR_CODES API_Draw_Ellipse_Line(uint16_t x_coor, uint16_t x_coor_center, uint16_t y_coor_one, uint16_t y_coor_two, uint8_t color){
	LINE_ERROR_CODES error = 0;
	if(x_coor < x_coor_center && y_coor_one > y_coor_two)											// Bottom first half
		error |= API_Draw_Line((x_coor - FILLING_LINE_OFFSET), y_coor_two, (x_coor- FILLING_LINE_OFFSET), y_coor_one, color, FILLING_LINE_SIZE);

	else if( x_coor < x_coor_center && y_coor_one < y_coor_two)										// Top first half
		error |= API_Draw_Line((x_coor - FILLING_LINE_OFFSET), y_coor_two, (x_coor- FILLING_LINE_OFFSET), y_coor_one, color, FILLING_LINE_SIZE);

	else if(x_coor > x_coor_center && y_coor_one < y_coor_two)										// Bottom second half
		error |= API_Draw_Line(x_coor, (y_coor_two - FILLING_LINE_OFFSET) , x_coor, y_coor_one, color, FILLING_LINE_SIZE);

	else if(x_coor > x_coor_center && y_coor_one > y_coor_two)										// Top second half
		error |= API_Draw_Line(x_coor, (y_coor_two + FILLING_LINE_OFFSET), x_coor, y_coor_one, color, FILLING_LINE_SIZE);

	if(error != CORRECT_LINE_PLACEMENT)
		return ERROR_PLACEMENT_INDIVIDUAL_LINE;
	return ELLIPSE_LINE_PLACEMENT_SUCCESS;
}

/**
  * @brief	This function checks if there is a jump in the y_coordinate
  *
  * If the jump on the y-axis is bigger then 1 or -1, depending on the bottom or top parabola, the function
  * returns true. If this is not the case the function returns false
  *
  * @param	new_y_coor 		New calcualted point on the ellipse 	(uint16_t)
  * @param  old_y_coor 		previous point on the ellipse  	  		(uint16_t)
  *
  * @retval	bool
  */
bool API_Check_Jump_in_Y_Coor(uint16_t new_y_coor, uint16_t old_y_coor){
	int16_t jump_size = new_y_coor - old_y_coor;

	if(jump_size > 1 || jump_size < -1)
		return true;
	else
		return false;
}



