#ifndef _EXIT_Register_H
#define _EXIT_Register_H



#define GICR  *((volatile u8 *) 0x5B)

#define MCUCSR  *((volatile u8 *) 0x54)

#define GIFR  *((volatile u8 *) 0x5A)

#define MCUCR  *((volatile u8 *) 0x55)


#define INT0   6

#define INT1   7

#define INT2   5

#define ISC00  0

#define ISC01  1

#define ISC10  0

#define ISC11  0



void __vector_1(void) __attribute((signal));

#endif
