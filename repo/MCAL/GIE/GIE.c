/*
 * GIE.c
 *
 *  Created on: Sep 3, 2022
 *      Author: Ahmed
 */
#include "GIE.h"

#ifndef REPO_MCAL_GIE_GIE_C_
#define REPO_MCAL_GIE_GIE_C_

void GIE_Enable_Global(void)
{
	SET_Bit(SREG_Reg,7);
}

void GIE_Disable_Global(void)
{
	CLEAR_Bit(SREG_Reg,7);
}

#endif /* REPO_MCAL_GIE_GIE_C_ */
