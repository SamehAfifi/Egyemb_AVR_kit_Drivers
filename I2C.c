#include "I2C.h"
#define F_SCL 400000UL // SCL frequency
#define Prescaler 1
#define TWBR_val ((((F_CPU / F_SCL) / Prescaler) - 16 ) / 2)
void I2C_master_init(void)
{
	TWBR = (uint8_t)TWBR_val;
}

void I2C_start(uint8_t address)
{
	// reset TWI control register
	TWCR = 0;
	// transmit START condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	
	// load slave address into data register
	TWDR = address<<1;
	// start transmission of address
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
}

void I2C_write(uint8_t data)
{
	// load data into data register
	TWDR = data;
	// start transmission of data
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
}

uint8_t I2C_read(void)
{

	// start TWI module and acknowledge data after reception
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA); 
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	// return received data from TWDR
	return TWDR;
}

void I2C_stop(void)
{
	// transmit STOP condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}
void I2C_Slave_Init(uint8_t My_Add){
	TWAR = My_Add<<1;
	TWCR = (1<<TWEA) | (1<<TWINT) | (1<<TWEN);
}

uint8_t I2C_Slave_avialable(){	
	TWCR |= (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	return ((TWSR & 0xF8) == TW_SR_SLA_ACK); 
}

