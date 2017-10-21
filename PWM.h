/*
 * PWM.h
 *
 * Created: 4/22/2017 3:03:13 AM
 *  Author: safifi
 */ 


#ifndef PWM_H_
#define PWM_H_
#include "std_macros.h"

void PWM1_OCR1A_init();
void PWM1_OCR1B_init();
void PWM1_OCR1A_SET_DUTY(uint16_t duty);
void PWM1_OCR1B_SET_DUTY(uint16_t duty);




#endif /* PWM_H_ */