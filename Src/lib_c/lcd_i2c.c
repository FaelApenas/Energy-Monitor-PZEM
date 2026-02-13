/*
 * lcd_i2c.c
 *
 *  Created on: 16 de abr de 2024
 *      Author: rafae
 */

#include "lib_h\lcd_i2c.h"

uint8_t backlight= 1;


void R_LCD_WRITE_NIBLE(uint8_t nibble, uint8_t r_select )
{
    uint8_t data  = nibble <<D4_BIT;
    data |= r_select <<RS_BIT;
    data |= backlight <<BL_BIT;
    data |= 1 <<EN_BIT;
    //tw_master_transmit(I2C_ADDR ,&data,1,0);
    i2c_start();
    i2c_address(I2C_ADDR);
    i2c_write(data);

    HAL_Delay(1);
    //_delay_ms(2);
    data &=~(1<<EN_BIT);
    i2c_write(data);
    //tw_master_transmit(I2C_ADDR ,&data,1,0);
    //_delay_ms(2);
    HAL_Delay(1);
    i2c_stop();

}


void R_LCD_CMD(uint8_t cmd ) {
  uint8_t upper_nibble = cmd >> 4;
  uint8_t lower_nibble = cmd & 0x0F;
  R_LCD_WRITE_NIBLE(upper_nibble, 0);
  R_LCD_WRITE_NIBLE(lower_nibble, 0);
  if (cmd == 0x01 || cmd == 0x02) {
    //_delay_ms(2);
	 HAL_Delay(1);
  }
}


void R_LCD_TRANSMIT(uint8_t data) {
  uint8_t upper_nibble = data >> 4;
  uint8_t lower_nibble = data & 0x0F;
  R_LCD_WRITE_NIBLE(upper_nibble, 1);
  R_LCD_WRITE_NIBLE(lower_nibble, 1);
}

void R_LCD_INIT() {
	HAL_Delay(50);
  R_LCD_WRITE_NIBLE(0x03, 0);
	 HAL_Delay(2);
  R_LCD_WRITE_NIBLE(0x03, 0);
	 HAL_Delay(2);
  R_LCD_WRITE_NIBLE(0x03, 0);
	 HAL_Delay(2);
  R_LCD_WRITE_NIBLE(0x02, 0);
  R_LCD_CMD(0x28); // function set
  R_LCD_CMD(0x0C); // Display on and off
  R_LCD_CMD(0x06);
  R_LCD_CMD(0x01); // Display clear
	 HAL_Delay(2);
}

void R_LCD_STR(char *str) {
  while (*str) {
    R_LCD_TRANSMIT(*str++);
  }
}

void R_LCD_BACKLIGHT(uint8_t state)
{
  if(state) backlight=1;
  else backlight =0 ;
}

void R_LCD_XY(uint8_t x , uint8_t y)
{
  uint8_t addr;
  uint8_t y_address[4]= {0x00,0x40,0x14,0x54};
  if (LCD_ROWS< y) y= 0;
  else addr= y_address[y];
  addr += x;
  R_LCD_CMD(LCD_DDR | addr );
}

void R_LCD_CLEAR()
{
  R_LCD_CMD(0x01);
	 HAL_Delay(2);
}
