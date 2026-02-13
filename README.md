
# ENERGY MONITOR

The objective was to implement an energy monitoring system using FreeRTOS to manage multiple real-time tasks. The system measures voltage, current, grid frequency, and power factor, integrating different hardware modules and communication interfaces.

## Technologies and Components
BOARD - NUCLEO F446RE 

FreeRTOS – Task management and synchronization using semaphores

PZEM-004T – Energy measurement module via UART

I2C LCD Display – Local visualization of measured values

HC-05 Bluetooth Module – Wireless data transmission

MIT App Inventor – Android application development

## System Architecture

The system was divided into multiple tasks:

Dedicated LCD update tasks (using semaphores to prevent I2C conflicts)

Energy meter data acquisition task via UART

Bluetooth transmission task

Task scheduling and prioritization handled by FreeRTOS

Measured data is serialized into communication frames and transmitted via Bluetooth to a mobile Android application for remote monitoring. 
## Task schedule 
![Task Schedule](Images/1.png)


## Results 
![](Images/2.jpeg) 

![](Images/3.jpeg)
