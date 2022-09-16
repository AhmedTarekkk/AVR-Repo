/*
 * LCD.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed
 */
#include <util/delay.h>
#include "../LIB/STD_types.h"
#include "../HAL/LCD/LCD.h"

void LCD_App()
{
	uint8 Pattern[8] = {0x0E, 0x08, 0x1F, 0x00, 0x04, 0x04, 0x04, 0x04};
	LCD_Initialization();
	LCD_WriteString("Ahmed Tarek" , 1 , 0);
	LCD_StorePattern(Pattern, 0);
	LCD_WritePattern(0, 0, 0);
}
