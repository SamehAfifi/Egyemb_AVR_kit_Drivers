#ifndef _seven_seg
#define _seven_seg
#define INIT_Seven_PORT 	DDRB = 0xff; PORTB = 0x00;

#include "std_macros.h"
#define SEG_A(x)    if (x == 0) CLRBIT(PORTB,0); else SETBIT(PORTB,0);
#define SEG_B(x)    if (x == 0) CLRBIT(PORTB,1); else SETBIT(PORTB,1);
#define SEG_C(x)    if (x == 0) CLRBIT(PORTB,6); else SETBIT(PORTB,6);
#define SEG_D(x)    if (x == 0) CLRBIT(PORTB,7); else SETBIT(PORTB,7);
#define SEG_E1(x)   if (x == 0) CLRBIT(PORTB,4); else SETBIT(PORTB,4);
#define SEG_E2(x)   if (x == 0) CLRBIT(PORTB,5); else SETBIT(PORTB,5);

void seven_seg_init();
void seven_seg_update(uint8_t counter);

#endif