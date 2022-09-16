/*
 * ADC.c
 *
 *  Created on: Aug 29, 2022
 *      Author: Ahmed
 */

#include "ADC.h"


void ADC_Initialize(void)
{
/************** Selecting Voltage Reference **************/
	ADMUX_Reg &= ADC_VOLTAGE_REF_clr_msk ;
	ADMUX_Reg |= ADC_VOLTAGE_REF_SELECTOR_msk ;
/*********************************************************/

/***************** Selecting ADC Mode ********************/
	#if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
		SET_Bit(ADCSRA_Reg,5);
		SFIOR_Reg &= ADC_AUTO_TRIG_SRC_clr_msk ;
		SFIOR_Reg |= ADC_AUTO_TRIG_SRCE_SELECTOR ;
	#elif ADC_MODE_SELECTOR == ADC_MODE_SINGLE_CONVERSION
		CLEAR_Bit(ADCSRA_Reg,5);
	#endif
/*********************************************************/

/*************** Selecting ADC Adjustment ****************/
	#if	ADC_ADJUSTMENT_SELECTOR == ADC_RIGHT_ADJUSTED
		CLEAR_Bit(ADMUX_Reg,5);
	#elif ADC_ADJUSTMENT_SELECTOR == ADC_LEFT_ADJUSTED
		SET_BIT(ADMUX_Reg,5);
	#endif
/*********************************************************/

/*************** Clearing Interrupt Flag *****************/
		SET_Bit(ADCSRA_Reg,4);
/*********************************************************/

/******************** Enabling ADC ***********************/
		SET_Bit(ADCSRA_Reg,7);
}

void ADC_StartConversion(ADC_Channel_types ADC_Channel)
{
/***************** Selecting ADC Channel ********************/
	ADMUX_Reg &= ADC_CHANNEL_SELECTOR_clr_msl ;
	ADMUX_Reg |= ADC_Channel ;
/************************************************************/

/***************** ADC Start Conversion *********************/
	SET_Bit(ADCSRA_Reg , 6);
}

uint16 ADC_GetResult(void)
{
	while(GET_Bit(ADCSRA_Reg,6));
	return ADCLH_Reg;
}
