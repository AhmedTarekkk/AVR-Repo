/*
 * PushButton.c
 *
 *  Created on: Aug 14, 2022
 *      Author: Ahmed
 */

#include <util/delay.h>
#include "../MCAL/DIO/DIO_types.h"
#include "../LIB/STD_types.h"
#include "../MCAL/DIO/DIO.h"


void PUSH_BUTTON()
{

	DIO_SetPinDirection(PORTD, Pin2, Input);
	DIO_SetPinDirection(PORTA, Pin2, Output);

	STD_levelTypes Pin_Value = DIO_GetPinValue(PORTD, Pin2);
	if(Pin_Value == HIGH)
	{
		DIO_SetPinValue(PORTA, Pin2, HIGH);
	}
	else if(Pin_Value == LOW)
	{
		DIO_SetPinValue(PORTA, Pin2, LOW);
	}
}
