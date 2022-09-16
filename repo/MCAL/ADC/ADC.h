/*
 * ADC.h
 *
 *  Created on: Aug 29, 2022
 *      Author: Ahmed
 */

#ifndef REPO_MCAL_ADC_ADC_H_
#define REPO_MCAL_ADC_ADC_H_

#include "../../LIB/STD_types.h"
#include "../../LIB/Bit_Math.h"
#include "ADC_config.h"
#include "ADC_types.h"
#include "ADC_reg.h"

typedef enum
{
	ADC_Channel_0,
	ADC_Channel_1,
	ADC_Channel_2,
	ADC_Channel_3,
	ADC_Channel_4,
	ADC_Channel_5,
	ADC_Channel_6,
	ADC_Channel_7
}ADC_Channel_types;

void ADC_Initialize(void);

void ADC_StartConversion(ADC_Channel_types ADC_Channel);

uint16 ADC_GetResult(void);



#endif /* REPO_MCAL_ADC_ADC_H_ */
