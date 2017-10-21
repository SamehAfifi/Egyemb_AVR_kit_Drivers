/*
 * PWM.c
 *
 * Created: 4/22/2017 3:02:41 AM
 *  Author: safifi
 */ 
#include "PWM.h"
void PWM1_OCR1A_init(){
	DDRD |= (1<<PIND5);
	TCNT1 = 0;
	TCCR1A |= ((1<<WGM11)|(1<<WGM10)|(1<<COM1A1)); // phase correct PWM at OC1A
	TCCR1B |= (1<<CS10);  // enable PWM with period 1.024/8 = 0.128 usec
}
void PWM1_OCR1A_SET_DUTY(uint16_t duty){
	OCR1A = (duty*10.23);	
}
void PWM1_OCR1B_SET_DUTY(uint16_t duty){
	OCR1B = (duty*10.23);	
}
void PWM1_OCR1B_init(){
	DDRD |= (1<<PIND4);
	TCNT1 = 0;
	TCCR1A |= ((1<<WGM11)|(1<<WGM10)|(1<<COM1B1)); // phase correct PWM at OC1B
	TCCR1B |= (1<<CS10);  // enable PWM with period 1.024/8 = 0.128 usec
}
