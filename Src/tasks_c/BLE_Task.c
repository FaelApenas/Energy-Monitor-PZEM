/*
 * BLE_Task.c
 *
 *  Created on: Jun 4, 2024
 *      Author: rafae
 */
#include "tasks_h/BLE_Task.h"

void serialize(void *pvParameters){

	meterData pData;

	while(1){

		pData.voltage 		= (float)	values.voltage /10.f;
		pData.current_mA	= (float) 	values.current /1000.f;
		pData.frequency		= (float)	values.frequency /10.f;
		pData.potFact		= (float)	values.power_factor /100.f;

		char data[30];

		sprintf(data, "K,%06.2f,%06.3f,%06.2f,%01.2f,F",
			 pData.voltage,
			 pData.current_mA,
			 pData.frequency,
			 pData.potFact
		 );

		hc05_send_data(data);
		osDelay(1500);

	}

}
