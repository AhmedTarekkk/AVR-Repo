/*
 * EXTI.h
 *
 *  Created on: Sep 1, 2022
 *      Author: Ahmed
 */

#ifndef REPO_MCAL_EXTI_EXTI_H_
#define REPO_MCAL_EXTI_EXTI_H_

#include "EXTI_config.h"
#include "EXTI_reg.h"
#include "EXTI_types.h"
#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_types.h"

void EXTI_Initialization(void);

void EXTI_Enable_INT0(void);

void EXTI_Disable_INT0(void);

void EXTI_ISR0( void (*CopyFunctPtr) (void) );

void EXTI_ISR1( void (*CopyFunctPtr) (void) );

#endif /* REPO_MCAL_EXTI_EXTI_H_ */
