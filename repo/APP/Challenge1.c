/*
 * Challenge1.c
 *
 *  Created on: Aug 26, 2022
 *      Author: Ahmed
 */
#include <util/delay.h>
#include "../LIB/STD_types.h"
#include "../MCAL/DIO/DIO_types.h"
#include "../MCAL/DIO/DIO.h"

void Challenge1(void)
{
	DIO_SetPortDirection(PORTC, Output);
	while(1)
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
