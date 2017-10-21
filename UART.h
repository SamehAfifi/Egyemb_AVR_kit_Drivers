/*
 * uart.h
 *
 * Created: 12/7/2014 5:11:28 PM
 *  Author: safifi
 */ 


#ifndef UART_H_
#define UART_H_
#include "std_macros.h"
uint8_t Uart_Read();
void Uart_init(uint16_t);
void Uart_Write(uint8_t);
uint8_t Uart_available();
void Uart_Write_string(uint8_t *data);

#endif /* UART_H_ */