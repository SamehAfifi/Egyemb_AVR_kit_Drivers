/*
 * timers.c
 *
 * Created: 12/27/2014 12:54:18 AM
 *  Author: safifi
 */ 
#include"timers.h"
uint64_t t1 = 0;
uint64_t t2 = 0;
void timer0_init(){
	TCCR0 = 0x81;  //
	TIMSK = 0x01;  // enable interrupt for OV
	sei();
}
void timer0_init_ocr(){
	TCCR0 = 0x81 | (1<<WGM01);  // no prescaler
	TIMSK = 0x02;  // enable interrupt for ocr
	OCR0 = 250;
	sei();
}
void timer2_init_oc2(){
	TCCR2 = (1<<FOC2)|(1<<WGM21) | (1<<COM20)|(1<<CS22)|(1<<CS21)|(1<<CS20);  // 
	OCR2 = 250; // 250*1024
//	sei();
}

uint64_t timer0_ms(){
	return ( t1 * 0.032);  // 8 MHZ crystal ==>   256 / 8 * 10^-3 
}
uint64_t timer0_ms_ocr(){
	return ( t2 * 0.03125);  // 8 MHZ crystal ==>   250 / 8 * 10^-3
}
#define TOGBIT(REG,BIT)  (REG ^= 1 << BIT)

ISR (TIMER0_OVF_vect){
	t1++;
}

ISR(TIMER0_COMP_vect) {
	t2++;
}
