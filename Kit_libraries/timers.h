/*
 * timers.h
 *
 * Created: 12/27/2014 12:54:42 AM
 *  Author: safifi
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

#include "std_macros.h"
void timer0_init();
void timer0_init_ocr();
uint64_t timer0_ms();
uint64_t timer0_ms_ocr();


#endif /* TIMERS_H_ */