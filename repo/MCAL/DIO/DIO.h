/*
 * DIO.h
 *
 *  Created on: Jul 24, 2022
 *      Author: Ahmed
 */

#ifndef REPO_MCAL_DIO_DIO_H_
#define REPO_MCAL_DIO_DIO_H_

#include "../../LIB/STD_types.h"
#include "DIO_types.h"
#include"DIO_REG.h"

void DIO_SetPortDirection(DIO_PORT_ID port_ID , DIO_Direction direction);

void DIO_SetPortValue(DIO_PORT_ID port_ID , unsigned char value );

void DIO_SetPinDirection(DIO_PORT_ID port_ID , DIO_PIN_ID pin_ID , DIO_Direction direction);

void DIO_SetPinValue(DIO_PORT_ID port_ID , DIO_PIN_ID pin_ID , STD_levelTypes value );

STD_levelTypes DIO_GetPinValue(DIO_PORT_ID port_ID , DIO_PIN_ID pin_ID );

void DIO_ToggleBit(DIO_PORT_ID port_ID , DIO_PIN_ID pin_ID );

#endif /* REPO_MCAL_DIO_DIO_H_ */
