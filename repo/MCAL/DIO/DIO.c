/*
 * DIO.c
 *
 *  Created on: Jul 24, 2022
 *      Author: Ahmed
 */

#include "DIO_REG.h"
#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_types.h"
#include "DIO_types.h"

void DIO_SetPortDirection(DIO_PORT_ID port_ID , DIO_Direction direction)
{
	if(Output == direction)
	{
		switch(port_ID)
		{
			case PORTA: DDRA_Reg = 0xff ; break;
			case PORTB: DDRB_Reg = 0xff ; break;
			case PORTC: DDRC_Reg = 0xff ; break;
			case PORTD: DDRD_Reg = 0xff ; break;
		}
	}
	else if(Input == direction)
	{
		switch(port_ID)
		{
			case PORTA: DDRA_Reg = 0x00 ; break;
			case PORTB: DDRB_Reg = 0x00 ; break;
			case PORTC: DDRC_Reg = 0x00 ; break;
			case PORTD: DDRD_Reg = 0x00 ; break;
		}
	}
}


void DIO_SetPortValue(DIO_PORT_ID port_ID , unsigned char value )
{
	switch(port_ID)
	{
		case PORTA: PORTA_Reg = value ; break ;
		case PORTB: PORTB_Reg = value ; break ;
		case PORTC: PORTC_Reg = value ; break ;
		case PORTD: PORTD_Reg = value ; break ;
	}
}


void DIO_SetPinDirection(DIO_PORT_ID port_ID , DIO_PIN_ID pin_ID , DIO_Direction direction)
{
	if(port_ID <= PORTD && pin_ID <= Pin7)
	{
		if(Output == direction)
		{
			switch(port_ID)
			{
				case PORTA : SET_Bit(DDRA_Reg , pin_ID) ; break;
				case PORTB : SET_Bit(DDRB_Reg , pin_ID) ; break;
				case PORTC : SET_Bit(DDRC_Reg , pin_ID) ; break;
				case PORTD : SET_Bit(DDRD_Reg , pin_ID) ; break;
			}
		}
		else if(Input == direction)
		{
			switch(port_ID)
			{
				case PORTA : CLEAR_Bit(DDRA_Reg , pin_ID) ; break;
				case PORTB : CLEAR_Bit(DDRB_Reg , pin_ID) ; break;
				case PORTC : CLEAR_Bit(DDRC_Reg , pin_ID) ; break;
				case PORTD : CLEAR_Bit(DDRD_Reg , pin_ID) ; break;
			}
		}
	}
}


void DIO_SetPinValue(DIO_PORT_ID port_ID , DIO_PIN_ID pin_ID , STD_levelTypes value )
{
	if(port_ID <= PORTD && pin_ID <= Pin7)
	{
		if(value == HIGH)
		{
			switch(port_ID)
			{
				case PORTA : SET_Bit(PORTA_Reg , pin_ID) ; break;
				case PORTB : SET_Bit(PORTB_Reg , pin_ID) ; break;
				case PORTC : SET_Bit(PORTC_Reg , pin_ID) ; break;
				case PORTD : SET_Bit(PORTD_Reg , pin_ID) ; break;
			}
		}
		else if(value == LOW)
		{
			switch(port_ID)
			{
				case PORTA : CLEAR_Bit(PORTA_Reg , pin_ID) ; break;
				case PORTB : CLEAR_Bit(PORTB_Reg , pin_ID) ; break;
				case PORTC : CLEAR_Bit(PORTC_Reg , pin_ID) ; break;
				case PORTD : CLEAR_Bit(PORTD_Reg , pin_ID) ; break;
			}
		}
	}
}


STD_levelTypes DIO_GetPinValue(DIO_PORT_ID port_ID , DIO_PIN_ID pin_ID )
{
	STD_levelTypes PinValue;
	if(port_ID <= PORTD && pin_ID <= Pin7)
	{
		switch(port_ID)
		{
			case PORTA : PinValue = GET_Bit(PINA_Reg , pin_ID) ; break;
			case PORTB : PinValue = GET_Bit(PINB_Reg , pin_ID) ; break;
			case PORTC : PinValue = GET_Bit(PINC_Reg , pin_ID) ; break;
			case PORTD : PinValue = GET_Bit(PIND_Reg , pin_ID) ; break;
		}
	}

	return PinValue;
}

void DIO_ToggleBit(DIO_PORT_ID port_ID , DIO_PIN_ID pin_ID )
{
	if(port_ID <= PORTD && pin_ID <= Pin7)
	{
		switch(port_ID)
		{
			case PORTA : TOGGLE_Bit(PORTA_Reg,pin_ID) ; break;
			case PORTB : TOGGLE_Bit(PORTB_Reg,pin_ID) ; break;
			case PORTC : TOGGLE_Bit(PORTC_Reg,pin_ID) ; break;
			case PORTD : TOGGLE_Bit(PORTD_Reg,pin_ID) ; break;
		}
	}

}
