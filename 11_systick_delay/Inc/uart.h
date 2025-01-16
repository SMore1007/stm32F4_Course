/*
 * uart.h
 *
 *  Created on: Jan 13, 2025
 *      Author: sagar
 */

#ifndef UART_H_
#define UART_H_
#include <stdint.h>
#include<stdio.h>
#include<stm32f446xx.h>
void uart2_tx_init(void);
char uart2_read(void);
void uart2_rxtx_init(void);


#endif /* UART_H_ */
