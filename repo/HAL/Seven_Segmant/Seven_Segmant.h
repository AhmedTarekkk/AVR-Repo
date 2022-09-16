/*
 * Seven_Segmant.h
 *
 *  Created on: Aug 20, 2022
 *      Author: Ahmed
 */

#ifndef REPO_HAL_SEVEN_SEGMANT_SEVEN_SEGMANT_H_
#define REPO_HAL_SEVEN_SEGMANT_SEVEN_SEGMANT_H_

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_types.h"
#include "../../MCAL/DIO/DIO_types.h"
#include "../../MCAL/DIO/DIO.h"

void Seven_Segmant_Initialization();

void Seven_Segmant_Write_Number(unsigned char number);

void Seven_Segmant_Enable1();

void Seven_Segmant_Enable2();

void Seven_Segmant_Disable1();

void Seven_Segmant_Disable2();

#endif /* REPO_HAL_SEVEN_SEGMANT_SEVEN_SEGMANT_H_ */
