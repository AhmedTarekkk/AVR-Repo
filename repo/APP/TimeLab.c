/*
 * TimeLab.c
 *
 *  Created on: Sep 3, 2022
 *      Author: Ahmed
 */
#include "../LIB/Bit_Math.h"
#include "../LIB/STD_types.h"
#include <util/delay.h>
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/TIMER0/TIMER0.h"
#include "../MCAL/GIE/GIE.h"

unsigned char num = 0;
void Toggle();
void TIMER_LAB(void)
{
	DIO_SetPinDirection(PORTC, Pin0, Output);
	DIO_SetPinValue(PORTC, Pin0, LOW);

	TIM0_Initialization();
	TIM0_OverFlowCallBack(Toggle);

	TIM0_SetTimerValue(6); /*prescaler = 1024 and F = 1Mhz so F = 1Khz Ttimer = 1ms so from 6 to 256 = 250 ms
	so every 2 overflow will be 0.5 sec */

	TIM0_OverFlowIntEnable();
	GIE_Enable_Global();
	while(1)
	{
		if(num == 4) //Toggle every Sec
		{
			DIO_ToggleBit(PORTC, Pin0);
			num = 0;
			TIM0_SetTimerValue(6);
		}
	}
}
void Toggle()
{
	TIM0_SetTimerValue(6);
	num ++;
}
