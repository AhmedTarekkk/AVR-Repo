/*
 * EXTI.c
 *
 *  Created on: Sep 1, 2022
 *      Author: Ahmed
 */
#include "EXTI.h"

void (*CallBackPtr0) (void) = NULL ;
void (*CallBackPtr1) (void) = NULL ;
void (*CallBackPtr2) (void) = NULL ;

void EXTI_Initialization(void)
{
	MCUCR_Reg &= EXTI_Clear_msk ;
	CLEAR_Bit(MCUCSR_Reg,6);
/* ******************** Selecting Mode ******************* */
	/* **************** INT0 ************ */
	#if EXTI0_MODE == EXTI_Low_Level
		MCUCR_Reg |= EXTI_Low_Level ;
	#elif EXTI0_MODE == EXTI_Any_Logical_Change
		MCUCR_Reg |= EXTI_Any_Logical_Change ;
	#elif EXTI0_MODE == EXTI_Falling_Edge
		MCUCR_Reg |= EXTI_Falling_Edge ;
	#elif EXTI0_MODE == EXTI_Rising_Edge
		MCUCR_Reg |= EXTI_Rising_Edge ;
	#endif

	/* **************** INT1 ************ */
	#if EXTI1_MODE == EXTI_Low_Level
		MCUCR_Reg |= (EXTI_Low_Level << 2) ;
	#elif EXTI1_MODE == EXTI_Any_Logical_Change
		MCUCR_Reg |= (EXTI_Any_Logical_Change << 2) ;
	#elif EXTI1_MODE == EXTI_Falling_Edge
		MCUCR_Reg |= (EXTI_Falling_Edge << 2) ;
	#elif EXTI1_MODE == EXTI_Rising_Edge
		MCUCR_Reg |= (EXTI_Rising_Edge << 2) ;
	#endif

	/* **************** INT2 ************ */
	#if EXTI2_MODE == EXTI_Falling_Edge
		MCUCSR_Reg |= (EXTI_Falling_Edge << 6) ;
	#elif EXTI2_MODE == EXTI_Rising_Edge
		MCUCSR_Reg |= (EXTI_Rising_Edge << 6) ;
	#endif

/* ******************** Selecting State ******************* */
	/* **************** INT0 ************ */
	#if EXTI_INT0_INIT_STATE == EXTI_Disable_State
		CLEAR_Bit(GICR_Reg,6) ;
	#elif EXTI_INT0_INIT_STATE == EXTI_Enable_State
		SET_Bit(GICR_Reg,6) ;
	#endif
	/* **************** INT1 ************ */
	#if EXTI_INT1_INIT_STATE == EXTI_Disable_State
		CLEAR_Bit(GICR_Reg,7) ;
	#elif EXTI_INT1_INIT_STATE == EXTI_Enable_State
		SET_Bit(GICR_Reg,7) ;
	#endif
	/* **************** INT2 ************ */
	#if EXTI_INT2_INIT_STATE == EXTI_Disable_State
		CLEAR_Bit(GICR_Reg,5) ;
	#elif EXTI_INT2_INIT_STATE == EXTI_Enable_State
		SET_Bit(GICR_Reg,5) ;
	#endif
/* ******************** Clearing Flag ******************* */
	SET_Bit(GIFR_Reg,5);
	SET_Bit(GIFR_Reg,6);
	SET_Bit(GIFR_Reg,7);
}

void EXTI_Enable_INT0(void)
{
	SET_Bit(GICR_Reg,6);
}

void EXTI_Disable_INT0(void)
{
	CLEAR_Bit(GICR_Reg,6);
}
/********************** INT0 ISR *********************/
void EXTI_ISR0( void (*CopyFunctPtr) (void) )
{
	CallBackPtr0 = CopyFunctPtr;
}

void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	if(CallBackPtr0 != NULL)
	{
		CallBackPtr0();
	}
}
/********************** INT1 ISR *********************/
void EXTI_ISR1( void (*CopyFunctPtr) (void) )
{
	CallBackPtr1 = CopyFunctPtr;
}

void __vector_2(void) __attribute__((signal,used));
void __vector_2(void)
{
	if(CallBackPtr1 != NULL)
	{
		CallBackPtr1();
	}
}
/********************** INT2 ISR *********************/
void EXTI_ISR2( void (*CopyFunctPtr) (void) )
{
	CallBackPtr2 = CopyFunctPtr;
}

void __vector_3(void) __attribute__((signal,used));
void __vector_3(void)
{
	if(CallBackPtr2 != NULL)
	{
		CallBackPtr2();
	}
}
