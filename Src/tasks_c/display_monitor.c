/*
 * display_monitor.c
 *
 *  Created on: May 27, 2024
 *      Author: rafae
 */


#include "tasks_h\display_monitor.h"

#define Refresh_Delay 	400


void show_voltage(void *pvParameters)
{
	while(1)
	{
		if(xSemaphoreTake(disp_Semaph,portMAX_DELAY)==pdTRUE) //take the semphr
		{
			//Set the display-------------
			R_LCD_XY(0, 0);
			R_LCD_STR("V:      ");
			R_LCD_XY(2, 0);
			//---------------------------

			float volt_float= (float)values.voltage/10;// convert  to float the integer value and divide by 10 to fix the value(ex:2045 -> 240.5)
			char volt_str[5];
			sprintf(volt_str,"%0.1f",volt_float);
			R_LCD_STR(volt_str);



			xSemaphoreGive(disp_Semaph); // give the semaphr
		}
		osDelay(Refresh_Delay);
	}
}

void show_current(void *pvParameters)
{
	while(1)
	{
		if(xSemaphoreTake(disp_Semaph,portMAX_DELAY)==pdTRUE)//take the semphr
			{
			//Set the display-------------
				R_LCD_XY(0, 1);
				R_LCD_STR("A:        ");
				R_LCD_XY(3, 1);
			//----------------------------

				float curr_float= (float)values.current/1000.f; //convert to float and divided by 100 because we are using a 100/1 CT
				char cur_str[5];
				sprintf(cur_str,"%0.2f",curr_float);
				R_LCD_STR(cur_str);


				xSemaphoreGive(disp_Semaph);//give the semphr
			}
			osDelay(Refresh_Delay);
	}
}


void show_frequency(void *pvParameters)
{
	while(1)
		{
			if(xSemaphoreTake(disp_Semaph,portMAX_DELAY)==pdTRUE)//take the semphr
				{
				//Set the display-------------
					R_LCD_XY(0, 2);
					R_LCD_STR("hz:     ");
					R_LCD_XY(3, 2);
				//----------------------------
					float freq_float= (float)values.frequency/10;// convert  to float the integer value and divide by 10 to fix the value(ex:600 -> 60.0)
					char freq_str[5];
					sprintf(freq_str,"%0.1f",freq_float);
					R_LCD_STR(freq_str);


					xSemaphoreGive(disp_Semaph);//give the semphr
				}
				osDelay(Refresh_Delay);
		}
}

void show_power_factor(void *pvParameters)
{
	while(1)
		{
			if(xSemaphoreTake(disp_Semaph,portMAX_DELAY)==pdTRUE)//take the semphr
				{
				//Set the display-------------
					R_LCD_XY(0, 3);
					R_LCD_STR("fp:     ");
					R_LCD_XY(3, 3);
					//----------------------------

					float fp_float= (float)values.power_factor/10;// convert  to float the integer value and divide by 10 to fix the value(ex:2045 -> 240.5)
					char fp_str[5];
					sprintf(fp_str,"%0.1f",fp_float);
					R_LCD_STR(fp_str);
					xSemaphoreGive(disp_Semaph);//give the semphr
				}
				osDelay(Refresh_Delay);
		}
}

