#include "STD_TYPES.h"

#include "bit.h"

#include "GIE_Register.h"

void GIE_VidEnable(void)
{
	set_bit (SREG ,  7 );
}


void GIE_VidDisable(void)
{
	clr_bit (SREG ,  7 );
}
