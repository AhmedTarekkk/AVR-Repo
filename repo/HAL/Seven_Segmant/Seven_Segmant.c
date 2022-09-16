/*
 * Seven_Segmant.c
 *
 *  Created on: Aug 20, 2022
 *      Author: Ahmed
 */

#include "Seven_Segmant.h"

void Seven_Segmant_Initialization()
{
	DIO_SetPinDirection(PORTA, Pin4, Output); //A
	DIO_SetPinDirection(PORTA, Pin5, Output); //B
	DIO_SetPinDirection(PORTA, Pin6, Output); //C
	DIO_SetPinDirection(PORTA, Pin7, Output); //D

	DIO_SetPinDirection(PORTB, Pin0, Output);
	DIO_SetPinDirection(PORTB, Pin1, Output);
}

void Seven_Segmant_Enable1()
{
	DIO_SetPinValue(PORTB, Pin0, HIGH);
}

void Seven_Segmant_Enable2()
{
	DIO_SetPinValue(PORTB, Pin1, HIGH);
}

void Seven_Segmant_Disable1()
{
	DIO_SetPinValue(PORTB, Pin0, LOW);
}

void Seven_Segmant_Disable2()
{
	DIO_SetPinValue(PORTB, Pin1, LOW);
}

void Seven_Segmant_Write_Number(unsigned char number)
{
	if(number < 10)
	{
		DIO_SetPinValue(PORTA, Pin4, GET_Bit(number , 0)); //A
		DIO_SetPinValue(PORTA, Pin5, GET_Bit(number , 1)); //B
		DIO_SetPinValue(PORTA, Pin6, GET_Bit(number , 2)); //C
		DIO_SetPinValue(PORTA, Pin7, GET_Bit(number , 3)); //D
	}
}
