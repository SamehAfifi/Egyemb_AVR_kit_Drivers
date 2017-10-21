/*
 * I2C.h
 *
 * Created: 11/26/2014 6:45:32 PM
 *  Author: safifi
 */
#ifndef I2C_MASTER_H
#define I2C_MASTER_H

#include "std_macros.h"
#include <util/twi.h>

void I2C_master_init(void);
void I2C_start(uint8_t address);
void I2C_write(uint8_t data);
uint8_t I2C_read(void);
void I2C_stop(void);
uint8_t I2C_Slave_avialable();
void I2C_Slave_Init(uint8_t My_Add);
#endif // I2C_MASTER_H