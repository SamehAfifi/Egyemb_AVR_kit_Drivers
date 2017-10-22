/*
 * Ultrasonic.c
 *
 * Created: 13/09/2016 07:30:42 م
 *  Author: sameh
 */ 

#include "Ultrasonic.h"

static volatile uint8_t count = 0;
#define Trigger_ON   (PORTC |= (1<<PC0))
#define Trigger_OFF  (PORTC &=~(1<<PC0))

void Ultrasonic_init(){
		Timer0_init();
		DDRC |=(1<<PC0);  // pc0 Trigger
		DDRC  &= ~(1<<PC1); // pc1 ECHO
}
uint32_t Ultrasonic_Read(){
	
		volatile uint32_t Duration=0;
			Trigger_OFF;
			_delay_us(10);
			Trigger_ON;
			_delay_us(10);
			Trigger_OFF;
		if (!(PINC & (1<<PC1)))
		{
			while(!(PINC & (1<<PC1)));  // wait until echo goes high
			Timer0_Start();
			while(PINC &(1<<PC1) && count != 3);
			Timer0_Stop();
		}
		else{
			while((PINC & (1<<PC1)));  // wait until echo goes high
			Timer0_Start();
			while(!(PINC &(1<<PC1)) && count != 3);
			Timer0_Stop();			
		}
		/*stopWatch value reading*/
		Duration =Timer0_read() * 34000 / F_CPU / 2;
		return Duration;
}	

void Timer0_init(void)
{
	TCCR0 = (1<<FOC0);
	TCNT0 = 0;
	sei();
	TIMSK |= (1<<TOIE0);
}
void Timer0_Start(void)
{
	count =0;
	TCNT0 = 0;
	TCCR0 |= (1<<CS02);
}
void Timer0_Stop(void)
{
	TCCR0 &= 0xf8;
}
uint32_t Timer0_read(void)
{
	return (TCNT0 + 256 * count) * 256;
}

ISR(TIMER0_OVF_vect){
	count++;
}