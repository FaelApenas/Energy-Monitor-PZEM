/*
 * BLE_Task.h
 *
 *  Created on: Jun 4, 2024
 *      Author: rafae
 */

#ifndef INC_TASKS_H_BLE_TASK_H_
#define INC_TASKS_H_BLE_TASK_H_

#include "shared\handles.h"
#include "main.h"
#include "shared\globals.h"

typedef struct
{
    float voltage     ;
    float current_mA  ;
    float frequency   ;
    float potFact     ;
}meterData;

void serialize(void *pvParameters);


#endif /* INC_TASKS_H_BLE_TASK_H_ */
