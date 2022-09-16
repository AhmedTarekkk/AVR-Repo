/*
 * SevenSegment.c
 *
 *  Created on: Aug 21, 2022
 *      Author: Ahmed
 */

#include <util/delay.h>
#include "../LIB/STD_types.h"
#include "../HAL/Seven_Segmant/Seven_Segmant.h"


void SEV_SEG(unsigned char number)
{
	Seven_Segmant_Initialization();
	if(number < 100)
	{
		for(uint8 k = 0 ; k < 10 ; k++)
		{
			uint8 right = number%10; //e2
			uint8 left = number/10; //e1
			Seven_Segmant_Disable1();
			Seven_Segmant_Disable2();
			Seven_Segmant_Write_Number(left);
			Seven_Segmant_Enable1();
			_delay_ms(10);
			Seven_Segmant_Disable1();
			Seven_Segmant_Write_Number(right);
			Seven_Segmant_Enable2();
			_delay_ms(10);
		}
	}
}
