#include "STD_TYPES.h"
#include "bit.h"

#include "DIO_Interface.h"
#include "EXIT_Register.h"

void EXIT0_VidInit(void)
{

	// modes for INT0
#if ISC == FALLING
	set_bit( MCUCR , ISC01 );
	clr_bit( MCUCR , ISC00);

#elif ISC == RAISING
	set_bit( MCUCR , ISC00 );
	set_bit( MCUCR , ISC01 );

#elif ISC == OCH
	set_bit( MCUCR , ISC00 );
	clr_bit( MCUCR , ISC00);

#else
	clr_bit( MCUCR , ISC00);
	clr_bit( MCUCR , ISC01);
#endif
	// enable INT0

	set_bit( GICR , INT0) ;



}



void EXIT1_VidInit(void) 
{

	// modes for INT1
#if ISC == FALLING
	set_bit( MCUCR , ISC11 );
	clr_bit( MCUCR , ISC10);

#elif ISC == RAISING
	set_bit( MCUCR , ISC11 );
	set_bit( MCUCR , ISC10 );

#elif ISC == OCH
	set_bit( MCUCR , ISC10 );
	clr_bit( MCUCR , ISC11 );

#else
	clr_bit( MCUCR , ISC10);
	clr_bit( MCUCR , ISC11);

#endif
	//enable for INT1 

	set_bit( GICR , INT1) ;

}


