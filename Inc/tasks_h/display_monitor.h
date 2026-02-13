/*
 * display_monitor.h
 *
 *  Created on: May 27, 2024
 *      Author: rafae
 */

#ifndef INC_DISPLAY_MONITOR_H_
#define INC_DISPLAY_MONITOR_H_

#include "shared\handles.h"
#include "shared\globals.h"


void show_voltage(void *pvParameters);

void show_current(void *pvParameters);

void show_frequency(void *pvParameters);
void show_power_factor(void *pvParameters);

#endif /* INC_DISPLAY_MONITOR_H_ */
