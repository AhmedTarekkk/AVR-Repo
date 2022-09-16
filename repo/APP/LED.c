/*
 * LED.c
 *
 *  Created on: Aug 7, 2022
 *      Author: Ahmed
 */

#include <util/delay.h>
#include "../MCAL/DIO/DIO_types.h"
#include "../LIB/STD_types.h"
#include "../MCAL/DIO/DIO.h"

void LED()
{
	DIO_SetPortDirection(PORTC, Output);
	DIO_SetPinValue(PORTC, Pin0, HIGH);
	_delay_ms(20);

}
