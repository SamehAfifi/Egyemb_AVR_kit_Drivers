#include "SPI.h"

void SPI_Master_Init()
  {
     DDRB = (1<<PB4)|(1<<PB5)|(1<<PB7);	
     SPCR|= (1<<SPE)|(1<<MSTR);
  }

void SPI_Slave_Init()
  {
    DDRB =(1<<PB6);
    SPCR|= (1<<SPE);
  }

uint8_t SPI_Send_Char(uint8_t data)
  {
    SPDR = data;
    while(!(SPSR & (1<<SPIF)));
    return SPDR;   
  }
