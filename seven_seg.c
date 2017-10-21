#include "seven_seg.h"
void seven_seg_init(){
	INIT_Seven_PORT;
	SEG_E1(1);
	SEG_E2(1);	
}

void seven_seg_update(uint8_t counter){
	uint8_t temp;
	temp = counter % 10;
	SEG_E1(1);
	SEG_E2(0);
	SEG_A(READBIT(temp,0));
	SEG_B(READBIT(temp,1));
	SEG_C(READBIT(temp,2));
	SEG_D(READBIT(temp,3));
	
	_delay_ms(1);
	temp = counter / 10;
	SEG_E1(0);
	SEG_E2(1);
	SEG_A(READBIT(temp,0));
	SEG_B(READBIT(temp,1));
	SEG_C(READBIT(temp,2));
	SEG_D(READBIT(temp,3));
	
	_delay_ms(1);
}