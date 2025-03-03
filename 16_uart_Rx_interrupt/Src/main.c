/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "uart.h"
#include "stm32f446xx.h"



#define GPIOAEN				   (1U<<0)
#define GPIOA_5				   (1U<<5)

#define LED_PIN				   GPIOA_5

char key;


static void uart_callback(void);

int main(void)
{

	/*1.Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;

	/*2.Set PA5 as output pin*/
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);


	uart2_rx_interrupt_init();

	while(1)
	{

	}

}

static void uart_callback(void)
{
	key =  USART2->DR;

	if(key == '1')
		{
			GPIOA->ODR |= LED_PIN;
		}
		else{
			GPIOA->ODR &= ~LED_PIN;

		}
}

void USART2_IRQHandler(void)
{
	/*ChecK if RXNE is set*/

	if(USART2->SR & SR_RXNE)
	{
		//Do something
		uart_callback();

	}
}

