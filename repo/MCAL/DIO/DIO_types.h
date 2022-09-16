/*
 * DIO_types.h
 *
 *  Created on: Jul 24, 2022
 *      Author: Ahmed
 */

#ifndef REPO_MCAL_DIO_DIO_TYPES_H_
#define REPO_MCAL_DIO_DIO_TYPES_H_

typedef enum
{
	Input,
	Output
}DIO_Direction;

typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD
}DIO_PORT_ID;



typedef enum
{
	Pin0,
	Pin1,
	Pin2,
	Pin3,
	Pin4,
	Pin5,
	Pin6,
	Pin7
}DIO_PIN_ID;


#endif /* REPO_MCAL_DIO_DIO_TYPES_H_ */
