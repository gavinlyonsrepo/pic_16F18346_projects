Overview
--------------------------------------------
* Name: 7seg_DHT22
* Description: Display DHT22 sensor(AM2302 package) temperature and humidity on an
  4 digit seven segment.
* Author: Gavin Lyons.
* Complier: xc8 v2.1.0
* PIC: PIC16F18346
* IDE:  MPLAB X v5.30

Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)
  * [Output](#output)
  
Features
------------------------------------

In this folder the main C source code can be found in file main.c.
The code generated using the MPLAB Code Configuraton is in a folder called mcc_generated_files. 
The timer0 files have user edits.

The project displays the Temperature and humidity data of a DHT22 sensor(AM2302 package) on a 4 digit seven segment.
It Reads the sensor every ~9 seconds, and toggles between Temperature and humidity display at same time.
  
**Connections**

1. RC0 = DHT22 Sensor line
2. SCLK595 = SCLK
3. RCLK595 = RCLK
4. SER595 = SER

**Seven Segment library**

This library is a port of a seven segment subsection of the arduino library I wrote,
It can be found in Arduino library manger or at [link](https://github.com/gavinlyonsrepo/FourteenSegDisplay).
The full details and schematic of the library can be found at link above in the seven segment section,
The main difference between PIC version and arduino.
is there is no class constructor and the given 3 I/O pins are hard-coded in the "SevenSegDisplay" function
rather than passed in from outside. Also you can vary timing of shifting operation 
by changing defines by top of header file. 

**DHT 22 sensor**

Digital relative humidity & temperature sensor DHT22(AM2302 package)
This 3 wire sensor provides Temperature and humidity data, 
The sensor code is in a library(dht22.c and dht22.h)
The sensor line need WPU option on and analog option off to work.

Possible outputs.

| Condition |  output |
| ----- | ---- |
| Temperature postive mode | t19.4 |
| Temperature negative mode | t19.4. |
| humidity mode | H55.2 |
| Error no response from DHT22 sensor | "   N" |
| Error checksum from DHT22 sensor | "   C" |
| Unknown error from DHT22 sensor | "   U" |


[link](https://www.sparkfun.com/datasheets/Sensors/Temperature/DHT22.pdf)

Output
-----------------------

![ output ](https://github.com/gavinlyonsrepo/pic_16F18346_projects/blob/master/images/output2.jpg)
