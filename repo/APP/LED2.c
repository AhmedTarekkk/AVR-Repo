/*
 * LED2.c
 *
 *  Created on: Aug 26, 2022
 *      Author: Ahmed
 */

#include <util/delay.h>
#include "../LIB/STD_types.h"
#include "../MCAL/DIO/DIO_types.h"
#include "../MCAL/DIO/DIO.h"

void LED2()
{
	DIO_SetPortDirection(PORTC, Output);
	DIO_SetPortDirection(PORTA, Input);
	DIO_SetPortValue(PORTC, 0x00);
	while(1)
	{
		if(DIO_GetPinValue(PORTA, Pin0) && !DIO_GetPinValue(PORTA, Pin1) && !DIO_GetPinValue(PORTA, Pin2))
		{
			_delay_ms(30);
			if(DIO_GetPinValue(PORTA, Pin0) && !DIO_GetPinValue(PORTA, Pin1) && !DIO_GetPinValue(PORTA, Pin2))
			{
				DIO_SetPinValue(PORTC, Pin0, HIGH);
				_delay_ms(500);
				DIO_SetPinValue(PORTC, Pin0, LOW);

				DIO_SetPinValue(PORTC, Pin1, HIGH);
				_delay_ms(500);
				DIO_SetPinValue(PORTC, Pin1, LOW);

				DIO_SetPinValue(PORTC, Pin2, HIGH);
				_delay_ms(500);
				DIO_SetPinValue(PORTC, Pin2, LOW);
			}
		}
		if(DIO_GetPinValue(PORTA, Pin1) && !DIO_GetPinValue(PORTA, Pin0) && !DIO_GetPinValue(PORTA, Pin2))
		{
			if(DIO_GetPinValue(PORTA, Pin1) && !DIO_GetPinValue(PORTA, Pin0) && !DIO_GetPinValue(PORTA, Pin2))
			{
				DIO_SetPinValue(PORTC, Pin0, HIGH);
				DIO_SetPinValue(PORTC, Pin1, HIGH);
				DIO_SetPinValue(PORTC, Pin2, HIGH);
				_delay_ms(500);
				DIO_SetPinValue(PORTC, Pin0, LOW);
				DIO_SetPinValue(PORTC, Pin1, LOW);
				DIO_SetPinValue(PORTC, Pin2, LOW);
			}
		}
		if(DIO_GetPinValue(PORTA, Pin2) && !DIO_GetPinValue(PORTA, Pin1) && !DIO_GetPinValue(PORTA, Pin0))
		{
			if(DIO_GetPinValue(PORTA, Pin2) && !DIO_GetPinValue(PORTA, Pin1) && !DIO_GetPinValue(PORTA, Pin0))
			{
				DIO_SetPinValue(PORTC, Pin0, HIGH);
				DIO_SetPinValue(PORTC, Pin1, LOW);
				DIO_SetPinValue(PORTC, Pin2, HIGH);
				_delay_ms(500);
				DIO_SetPinValue(PORTC, Pin0, LOW);
				DIO_SetPinValue(PORTC, Pin1, HIGH);
				DIO_SetPinValue(PORTC, Pin2, LOW);
			}
		}
	}
}
