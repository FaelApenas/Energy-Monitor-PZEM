/*
 * pzem-004.h
 *
 *  Created on: May 27, 2024
 *      Author: rafae
 */

#ifndef INC_PZEM_004_H_
#define INC_PZEM_004_H_

#include "shared\handles.h"
#include "main.h"
#include "shared\globals.h"

#define Slave_addr   0xF8
//uint8_t rst_buf[4]={0xF8, 0x42,0xC2,0X41};
//uint8_t res_buf[25];



void read_monitor(void *pvParameters);




#endif /* INC_PZEM_004_H_ */
