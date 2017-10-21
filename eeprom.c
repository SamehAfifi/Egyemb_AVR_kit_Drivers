#include "eeprom.h"

void eeprom_write(uint8_t data,uint16_t addr ){
	while(READBIT(EECR,1));
	EEAR = addr;
	EEDR = data;
	SETBIT(EECR,2); 
	SETBIT(EECR,1);
}

uint8_t eeprom_read(uint16_t addr ){
	while(READBIT(EECR,1));
	EEAR = addr;
	SETBIT(EECR,0);
	return EEDR;
}
