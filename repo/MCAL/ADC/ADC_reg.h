/*
 * ADC_reg.h
 *
 *  Created on: Aug 29, 2022
 *      Author: Ahmed
 */

#ifndef REPO_MCAL_ADC_ADC_REG_H_
#define REPO_MCAL_ADC_ADC_REG_H_

#define ADMUX_Reg			*((volatile uint8*) 0x27)
#define ADCSRA_Reg			*((volatile uint8*) 0x26)
#define SFIOR_Reg			*((volatile uint8*) 0x50)
#define ADCL_Reg			*((volatile uint8*) 0x24)
#define ADCH_Reg			*((volatile uint8*) 0x25)
#define ADCLH_Reg			*((volatile uint16*) 0x24)

#endif /* REPO_MCAL_ADC_ADC_REG_H_ */
