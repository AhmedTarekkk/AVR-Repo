/*
 * EXTI_config.h
 *
 *  Created on: Sep 1, 2022
 *      Author: Ahmed
 */

#ifndef REPO_MCAL_EXTI_EXTI_CONFIG_H_
#define REPO_MCAL_EXTI_EXTI_CONFIG_H_

/* Configure the External interrupt 0 mode
 * EXTI_Low_Level
 * EXTI_Any_Logical_Change
 * EXTI_Falling_Edge
 * EXTI_Rising_Edge
 */
#define EXTI0_MODE		EXTI_Low_Level

/* Configure the External interrupt 1 mode
 * EXTI_Low_Level
 * EXTI_Any_Logical_Change
 * EXTI_Falling_Edge
 * EXTI_Rising_Edge
 */
#define EXTI1_MODE		EXTI_Falling_Edge

/* Configure the External interrupt 2 mode
 * EXTI_Falling_Edge
 * EXTI_Rising_Edge
 */
#define EXTI2_MODE		EXTI_Falling_Edge

#define EXTI_INT0_INIT_STATE	EXTI_Disable_State
#define EXTI_INT1_INIT_STATE	EXTI_Disable_State
#define EXTI_INT2_INIT_STATE	EXTI_Disable_State

#endif /* REPO_MCAL_EXTI_EXTI_CONFIG_H_ */
