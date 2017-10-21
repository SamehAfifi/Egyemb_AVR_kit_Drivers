/*
 * keypad.c
 *
 * Created: 4/22/2017 3:02:41 AM
 *  Author: safifi
 */ 

#ifndef  key
#define key

#include "std_macros.h"

#define mykeypadport  SETBIT(DDRA,3); SETBIT(DDRD,5); SETBIT(DDRD,6); DDRD &= ~(7<<2);  
#define pullup  PORTD |= 0b00011100;  
// Keypad configurations
#define k1(x)   if (x == 0) CLRBIT(PORTD,5); else SETBIT(PORTD,5);
#define k2(x)   if (x == 0) CLRBIT(PORTD,6); else SETBIT(PORTD,6);
#define k3(x)   if (x == 0) CLRBIT(PORTA,3); else SETBIT(PORTA,3);

#define k4  READBIT(PIND,2)
#define k5  READBIT(PIND,3)
#define k6  READBIT(PIND,4)

// initialize keypad
void keypad_init();

// Get new click
int8_t keypad_click();

#endif

