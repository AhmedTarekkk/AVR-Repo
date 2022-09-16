/*
 * TIMER0_reg.h
 *
 *  Created on: Sep 3, 2022
 *      Author: Ahmed
 */

#ifndef REPO_MCAL_TIMER0_TIMER0_REG_H_
#define REPO_MCAL_TIMER0_TIMER0_REG_H_

#define OCR0_reg       *((volatile uint8*)0x5C)
#define TIFR_reg       *((volatile uint8*)0x58)
#define TCCR0_reg      *((volatile uint8*)0x53)
#define TCNT0_reg      *((volatile uint8*)0x52)
#define TIMSK_reg      *((volatile uint8*)0x59)

#endif /* REPO_MCAL_TIMER0_TIMER0_REG_H_ */
