/*
 * Ultrasonic.h
 *
 * Created: 13/09/2016 07:31:05 م
 *  Author: sameh
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "std_macros.h"
/*
init timer 0
turn overflow on
*/
static void Timer0_init(void);

/*
Start Count 
prescaler = 256
*/
static void Timer0_Start(void);

/*
Turn off timer
*/
static void Timer0_Stop(void);

/*
This function return TCNT0 value
*/
static uint32_t Timer0_read(void);

/*
init ultrasonic
*/
void Ultrasonic_init();

uint32_t Ultrasonic_Read();
#endif /* ULTRASONIC_H_ */