/*
 * EXTI.c
 *
 *  Created on: Sep 1, 2022
 *      Author: Ahmed
 */


#include "../MCAL/DIO/DIO.h"
#include "../MCAL/EXTI/EXTI.h"
#include <util/delay.h>
#include "../MCAL/GIE/GIE.h"

void EXTI0ISR(void);

void EXTI_LAB(void)
{
	 DIO_SetPinDirection(PORTD, Pin2, Input); //button ant int0
	 DIO_SetPinDirection(PORTA, Pin3, Output); //buzzer
	 DIO_SetPinDirection(PORTD, Pin3, Output); // led

	 EXTI_Initialization();
	 EXTI_ISR0(EXTI0ISR);
	 EXTI_Enable_INT0();
	 GIE_Enable_Global();

	 while(1)
	 {
		 DIO_SetPinValue(PORTD, Pin3, HIGH);
		 _delay_ms(500);
		 DIO_SetPinValue(PORTD, Pin3, LOW);
		 _delay_ms(500);
	 }
}

void EXTI0ISR(void)
{
	 DIO_SetPinValue(PORTA, Pin3, HIGH);
	 _delay_ms(5000);

}
