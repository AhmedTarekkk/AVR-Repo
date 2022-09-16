/*
 * ADC.c
 *
 *  Created on: Aug 30, 2022
 *      Author: Ahmed
 */


#include "../LIB/Bit_Math.h"
#include "../LIB/STD_types.h"
#include "../MCAL/DIO/DIO_types.h"
#include "../MCAL/ADC/ADC.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD.h"
#include <util/delay.h>

void ADC_Lab(void)
{
	uint16 value ;
	uint8 stringvalue[8] ;
	DIO_SetPortDirection(PORTC, Output) ;
	DIO_SetPortDirection(PORTB, Output) ;
	DIO_SetPinDirection(PORTA, Pin0, Input);
	STD_levelTypes Button = LOW;
	STD_levelTypes Button2 = LOW;
	ADC_Initialize();
	LCD_Initialization();
	while(1)
	{
		Button = DIO_GetPinValue(PORTA, Pin0);
		if(Button == HIGH && Button2 == LOW)
			{
				ADC_StartConversion(ADC_Channel_1);
				value = ADC_GetResult();
				itoa(value/2,stringvalue,10) ;
				LCD_WriteString(stringvalue, 0, 5);
			}
		else if(Button == LOW && Button2 == HIGH)
		{
			LCD_WriteString("        ", 0, 5);
		}
		Button2 = Button ;
	}
}
