/*
 * handles.h
 *
 *  Created on: May 27, 2024
 *      Author: rafae
 */

#ifndef INC_HANDLES_H_
#define INC_HANDLES_H_

#include "main.h"
#include "semphr.h"

extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern SemaphoreHandle_t disp_Semaph;


#endif /* INC_HANDLES_H_ */
