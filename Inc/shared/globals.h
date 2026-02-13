/*
 * globals.h
 *
 *  Created on: 29 de mai de 2024
 *      Author: rafae
 */

#ifndef INC_GLOBALS_H_
#define INC_GLOBALS_H_

#include "main.h"

typedef struct
{
	int current;
	int voltage;
	int frequency;
//	float power;
	int power_factor;
}monitor_values;


extern monitor_values values;



#endif /* INC_GLOBALS_H_ */
