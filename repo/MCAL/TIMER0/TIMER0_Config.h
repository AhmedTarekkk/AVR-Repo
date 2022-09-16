/*
 * TIMER0_Config.h
 *
 *  Created on: Sep 3, 2022
 *      Author: Ahmed
 */

#ifndef REPO_MCAL_TIMER0_TIMER0_CONFIG_H_
#define REPO_MCAL_TIMER0_TIMER0_CONFIG_H_

/* Mode
 * Normal_Mode
 * PWM_PhaseCorrect
 * CTC
 * Fast_PWM
 */
#define SIGNAL_MODE					Normal_Mode
/****************************************************/

/*COMPARE_OUTPUT_MODE
 * OC0_DISCONNECTED
 * OC0_TOGGLE_ON_COMPARE_MATCH
 * OC0_CLEAR_ON_COMPARE_MATCH
 * OC0_SET_ON_COMPARE_MATCH
 */
#define COMPARE_OUTPUT_MODE            OC0_DISCONNECTED

/* CLOCK_TYPES_Prescalers CHOICES :-
No_Clock_Stop
ClkIo
Clk_8
Clk_64
Clk_256
Clk_1024
Ext_clk_FallingEdge
Ext_clk_RisingEdge
 */
#define CLOCK_Prescaler                  Clk_1024
#endif /* REPO_MCAL_TIMER0_TIMER0_CONFIG_H_ */
