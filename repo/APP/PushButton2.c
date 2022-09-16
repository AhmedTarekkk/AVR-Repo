/*
 * PushButton2.c
 *
 *  Created on: Aug 14, 2022
 *      Author: Ahmed
 */
#include <util/delay.h>
#include "../MCAL/DIO/DIO_types.h"
#include "../MCAL/DIO/DIO.h"
#include "../LIB/STD_types.h"

void PUSH_BUTTON2()
{

	DIO_SetPinDirection(PORTD, Pin0, Input);
	DIO_SetPinDirection(PORTD, Pin1, Input);
	DIO_SetPinDirection(PORTD, Pin2, Input);

	DIO_SetPinDirection(PORTA, Pin0, Output);
	DIO_SetPinDirection(PORTA, Pin1, Output);
	DIO_SetPinDirection(PORTA, Pin2, Output);
	while(1)
	{
		STD_levelTypes Button0 = DIO_GetPinValue(PORTD, Pin0);
		STD_levelTypes Button1 = DIO_GetPinValue(PORTD, Pin1);
		STD_levelTypes Button2 = DIO_GetPinValue(PORTD, Pin2);

		if(Button0 == HIGH && Button1 == LOW && Button2 == LOW)
		{
			DIO_SetPinValue(PORTA, Pin0, HIGH);
			DIO_SetPinValue(PORTA, Pin1, HIGH);
			DIO_SetPinValue(PORTA, Pin2, HIGH);
		}
		else if(Button1 == HIGH && Button0 == LOW && Button2 == LOW)
		{
			DIO_SetPinValue(PORTA, Pin0, HIGH);
			DIO_SetPinValue(PORTA, Pin1, LOW);
			DIO_SetPinValue(PORTA, Pin2, LOW);
			_delay_ms(500);
			DIO_SetPinValue(PORTA, Pin0, LOW);
			DIO_SetPinValue(PORTA, Pin1, HIGH);
			DIO_SetPinValue(PORTA, Pin2, LOW);
			_delay_ms(500);
			DIO_SetPinValue(PORTA, Pin0, LOW);
			DIO_SetPinValue(PORTA, Pin1, LOW);
			DIO_SetPinValue(PORTA, Pin2, HIGH);
			_delay_ms(500);
		}
		else if(Button2 == HIGH && Button1 == LOW && Button0 == LOW)
		{
			DIO_SetPinValue(PORTA, Pin0, LOW); //0
			DIO_SetPinValue(PORTA, Pin1, LOW);
			DIO_SetPinValue(PORTA, Pin2, LOW);
			_delay_ms(500);

			DIO_SetPinValue(PORTA, Pin0, HIGH); //1
			DIO_SetPinValue(PORTA, Pin1, LOW);
			DIO_SetPinValue(PORTA, Pin2, LOW);
			_delay_ms(500);

			DIO_SetPinValue(PORTA, Pin0, LOW); //2
			DIO_SetPinValue(PORTA, Pin1, HIGH);
			DIO_SetPinValue(PORTA, Pin2, LOW);
			_delay_ms(500);

			DIO_SetPinValue(PORTA, Pin0, HIGH); //3
			DIO_SetPinValue(PORTA, Pin1, HIGH);
			DIO_SetPinValue(PORTA, Pin2, LOW);
			_delay_ms(500);

			DIO_SetPinValue(PORTA, Pin0, LOW); //4
			DIO_SetPinValue(PORTA, Pin1, LOW);
			DIO_SetPinValue(PORTA, Pin2, HIGH);
			_delay_ms(500);

			DIO_SetPinValue(PORTA, Pin0, HIGH); //5
			DIO_SetPinValue(PORTA, Pin1, LOW);
			DIO_SetPinValue(PORTA, Pin2, HIGH);
			_delay_ms(500);

			DIO_SetPinValue(PORTA, Pin0, LOW); //6
			DIO_SetPinValue(PORTA, Pin1, HIGH);
			DIO_SetPinValue(PORTA, Pin2, HIGH);
			_delay_ms(500);

			DIO_SetPinValue(PORTA, Pin0, HIGH); //7
			DIO_SetPinValue(PORTA, Pin1, HIGH);
			DIO_SetPinValue(PORTA, Pin2, HIGH);
			_delay_ms(500);
		}
		else
		{
			DIO_SetPinValue(PORTA, Pin0, LOW);
			DIO_SetPinValue(PORTA, Pin1, LOW);
			DIO_SetPinValue(PORTA, Pin2, LOW);
		}
	}
}
