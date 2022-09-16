/*
 * LCD.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed
 */

#include <util/delay.h>
#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_types.h"
#include "../../MCAL/DIO/DIO_types.h"
#include "../../MCAL/DIO/DIO.h"

static uint8 InitSetupFinished = 0;

void LCD_WriteCmd(uint8 Cmd)
{
	DIO_SetPinValue(PORTB, Pin1, LOW); //Rs = 0
	DIO_SetPinValue(PORTB, Pin2, LOW); //Rw = 0

	DIO_SetPinValue(PORTC, Pin4, GET_Bit(Cmd,4));
	DIO_SetPinValue(PORTC, Pin5, GET_Bit(Cmd,5));
	DIO_SetPinValue(PORTC, Pin6, GET_Bit(Cmd,6));
	DIO_SetPinValue(PORTC, Pin7, GET_Bit(Cmd,7));

	DIO_SetPinValue(PORTB, Pin3, HIGH);
	_delay_ms(1);
	DIO_SetPinValue(PORTB, Pin3, LOW);

	if(InitSetupFinished)
	{

	DIO_SetPinValue(PORTC, Pin4, GET_Bit(Cmd,0));
	DIO_SetPinValue(PORTC, Pin5, GET_Bit(Cmd,1));
	DIO_SetPinValue(PORTC, Pin6, GET_Bit(Cmd,2));
	DIO_SetPinValue(PORTC, Pin7, GET_Bit(Cmd,3));

	DIO_SetPinValue(PORTB, Pin3, HIGH);
	_delay_ms(1);
	DIO_SetPinValue(PORTB, Pin3, LOW);

	}

	_delay_ms(2);
}

void LCD_Initialization()
{
	DIO_SetPortDirection(PORTC, Output);
	DIO_SetPortDirection(PORTB, Output);

	_delay_ms(30);

	LCD_WriteCmd(0x20);
	LCD_WriteCmd(0x20);
	LCD_WriteCmd(0x80);
	_delay_ms(1);

	LCD_WriteCmd(0x00);
	LCD_WriteCmd(0xF0);
	_delay_ms(1);

	LCD_WriteCmd(0x00);
	LCD_WriteCmd(0x10);
	_delay_ms(2);

	InitSetupFinished = 1 ;

}

void LCD_WriteData(uint8 Data)
{
	DIO_SetPinValue(PORTB, Pin1, HIGH); //Rs = 1
	DIO_SetPinValue(PORTB, Pin2, LOW); //Rw = 0

	DIO_SetPinValue(PORTC, Pin4, GET_Bit(Data,4));
	DIO_SetPinValue(PORTC, Pin5, GET_Bit(Data,5));
	DIO_SetPinValue(PORTC, Pin6, GET_Bit(Data,6));
	DIO_SetPinValue(PORTC, Pin7, GET_Bit(Data,7));

	DIO_SetPinValue(PORTB, Pin3, HIGH);
	_delay_ms(1);
	DIO_SetPinValue(PORTB, Pin3, LOW);

	DIO_SetPinValue(PORTC, Pin4, GET_Bit(Data,0));
	DIO_SetPinValue(PORTC, Pin5, GET_Bit(Data,1));
	DIO_SetPinValue(PORTC, Pin6, GET_Bit(Data,2));
	DIO_SetPinValue(PORTC, Pin7, GET_Bit(Data,3));

	DIO_SetPinValue(PORTB, Pin3, HIGH);
	_delay_ms(1);
	DIO_SetPinValue(PORTB, Pin3, LOW);

	_delay_ms(2);
}

void LCD_GoToPos(uint8 Row , uint8 Col)
{
	uint8 Address;
	if(Row < 2 && Col < 16)
	{
		Address =  (Row * 0x40) + Col ;
		SET_Bit(Address,7) ;
		LCD_WriteCmd(Address) ;
	}

}

void LCD_WriteString(uint8* String , uint8 Row , uint8 Col)
{
	LCD_GoToPos(Row , Col);
	uint8 i = 0 ;
	uint8 Line0 = 0 ;
	while(*(String+i) != '\0' && ( (i + Col) + (Row * 16) ) < 32 )
	{
		if(((i + Col) + (Row * 16)) < 16)
		{
			LCD_WriteData(*(String+i));
			i++;
		}
		else if(((i + Col) + (Row * 16)) == 16 && Line0 == 0)
		{
			LCD_GoToPos(1 , 0);
			Line0++;
		}
		else if(((i + Col) + (Row * 16)) < 32 && Line0 == 1)
		{
			LCD_WriteData(*(String+i));
			i++;
		}

	}
}

void LCD_StorePattern(uint8* Pattern,uint8 Index)
{
	uint8 Adress;
	if(Index < 8)
	{
		Adress = 0x00 + 8*Index ;
		SET_Bit(Adress , 6);
		LCD_WriteCmd(Adress);
		for(uint8 i = 0 ; i < 8 ; i++)
		{
			LCD_WriteData(Pattern[i]);
		}
	}
	LCD_WriteCmd(0x02); // Return Ac to DDRAM
}

void LCD_WritePattern(uint8 Index , uint8 Row , uint8 Col)
{
	LCD_GoToPos(Row , Col);
	LCD_WriteData(Index);
}
