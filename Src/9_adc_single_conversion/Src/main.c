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
#include "adc.h"



uint32_t sensor_value;

int main(void)
{

	uart2_tx_init();
	pa1_adc_init();
	while(1)
	{

		start_converstion();
		sensor_value =  adc_read();
		printf("Sensor value : %d \n\r",(int)sensor_value);
	}

}
