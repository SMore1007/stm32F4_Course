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
#include<stdio.h>
#include"timer.h"
#include "stm32f446xx.h"


int timestamp = 0 ;

/*Set up : Connect a jumper wire from PA5 to PA6*/

int main(void)
{

	tim2_pa5_output_compare();
	tim3_pa6_input_capture();


	while(1)
	{

       /*Wait until edge is captured*/
		while(!(TIM3->SR & SR_CC1IF)){}

		/*Read captured value*/
		timestamp =  TIM3->CCR1;

	}

}
