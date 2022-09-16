/*
 * TIMER0.h
 *
 *  Created on: Sep 3, 2022
 *      Author: Ahmed
 */

#ifndef REPO_MCAL_TIMER0_TIMER0_H_
#define REPO_MCAL_TIMER0_TIMER0_H_

#include "../../LIB/std_types.h"
#include "../../LIB/Bit_Math.h"

#include "TIMER0_Config.h"
#include "TIMER0_reg.h"
#include "TIMER0_types.h"

void TIM0_Initialization(void);

void TIM0_CompIntEnable(void);
void TIM0_CompIntDisable(void);

void TIM0_OverFlowIntEnable(void);
void TIM0_OverFlowIntDisable(void);

void TIM0_SetCompValue(uint8 Value);
void TIM0_SetTimerValue(uint8 Value);

void TIM0_OverFlowCallBack(void (*Copy_ptr) (void));
void TIM0_CompareCallBack(void (*Copy_ptr) (void));

#endif /* REPO_MCAL_TIMER0_TIMER0_H_ */
