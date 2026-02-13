/*
 * pzem-004.c
 *
 *  Created on: May 27, 2024
 *      Author: rafae
 */


#include "tasks_h\pzem-004.h"
#include "semphr.h"

 uint8_t read_buffer[8]={Slave_addr,0x04,0x00,0x00,0x00,0x0A,0x64,0x64};


void read_monitor(void *pvParameters)
{


	while(1)
	{
		uint8_t res_buf[25];
		memset(res_buf, 0, sizeof(res_buf));

		HAL_UART_Transmit(&huart1,(uint8_t*) &read_buffer, 8, 20);
		HAL_UART_Receive(&huart1, res_buf, 25, 250);

		values.voltage=((uint32_t) 	res_buf[3]<< 8  	|(uint32_t) res_buf[4]);
		values.current= ((uint32_t) res_buf[5]<<8 	| (uint32_t)res_buf[6] 	| (uint32_t)res_buf[7]<<24 	|(uint32_t)res_buf[8]<<16);
//		values.power= ((uint32_t) 	res_buf[9]<<8 	| (uint32_t)res_buf[10] | (uint32_t)res_buf[11]<<24 |(uint32_t)res_buf[12]<<16);
		values.frequency= ((uint32_t)res_buf[17]<<8 | (uint32_t)res_buf[18]);

		//values.voltage=values.voltage/10;
		//values.current=values.current/100;
		//values.frequency=values.frequency/10;

		osDelay(1000);


	}
}
