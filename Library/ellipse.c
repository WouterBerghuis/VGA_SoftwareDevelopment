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

ELLIPSE_ERROR_CODES API_Check_Ellipse_Position(uint16_t x_coor_center, uint16_t y_coor_center, uint16_t width, uint16_t height){

	// Check horizontal position
	if(x_coor_center - (width / 2) < 0)					// Ellipse placed to far to the left
		return ERROR_ELLIPSE_POSITION_X_COOR;

	if(x_coor_center + (width / 2) > VGA_DISPLAY_X)		// Ellipse placed to far to the right
		return ERROR_ELLIPSE_POSITION_X_COOR;

	// Check vertical position
	if(y_coor_center - (height / 2) < 0)					// Ellipse placed too far top
		return ERROR_ELLIPSE_POSITION_Y_COOR;

	if(y_coor_center + (height / 2) > VGA_DISPLAY_Y) 		// Ellipse placed too far bottom
		return ERROR_ELLIPSE_POSITION_Y_COOR;

	return CORRECT_ELLIPSE_POSITION;
}

ELLIPSE_ERROR_CODES API_Calculate_Point_On_Ellipse(uint16_t x_coor_center, uint16_t y_coor_center, float width, float height, uint16_t x_coor_ellipse, uint16_t *y_coor_ellipse){

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

ELLIPSE_ERROR_CODES API_Draw_Ellipse_Line(uint16_t x_coor, uint16_t x_coor_center, uint16_t y_coor_one, uint16_t y_coor_two, uint8_t color){
	LINE_ERROR_CODES error = 0;
	if(x_coor < x_coor_center && y_coor_one > y_coor_two)
		error |= API_Draw_Line((x_coor - 1), y_coor_two, (x_coor- 1), y_coor_one, color, 1);		// Bottom first half

	else if( x_coor < x_coor_center && y_coor_one < y_coor_two)
		error |= API_Draw_Line((x_coor - 1), y_coor_two, (x_coor- 1), y_coor_one, color, 1);		// Top first half

	else if(x_coor > x_coor_center && y_coor_one < y_coor_two)
		error |= API_Draw_Line(x_coor, (y_coor_two - 1) , x_coor, y_coor_one, color, 1);			// Bottom second half

	else if(x_coor > x_coor_center && y_coor_one > y_coor_two)
		error |= API_Draw_Line(x_coor, (y_coor_two + 1), x_coor, y_coor_one, color, 1);				// Top second half

	if(error != CORRECT_LINE_PLACEMENT)
		return ERROR_PLACEMENT_INDIVIDUAL_LINE;
	return ELLIPSE_LINE_PLACEMENT_SUCCESS;
}


bool API_Check_Jump_in_Y_Coor(uint16_t new_y_coor, uint16_t old_y_coor){
	int16_t jump_size = new_y_coor - old_y_coor;

	if(jump_size > 1 || jump_size < -1)
		return true;
	else
		return false;
}



