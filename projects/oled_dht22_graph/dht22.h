/*
* Project Name: OLED_DHT22
* File: dht22.h 
* Description: dht22 sensor library header file
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F18346
* IDE:  MPLAB X v5.30
* CreatedL Feb 2020
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#ifndef _dht22_lib_H
#define	_dht22_lib_H

#include <xc.h>
#include <stdint.h>    
#include "mcc_generated_files/mcc.h"

#define DHT22_OUT(level)    	 LATCbits.LATC3 = level  // write I/0 on port
#define DHT22_IN            	 PORTCbits.RC3          // reading I/O from the port
#define DHT22_PIN_DIR			 TRISCbits.TRISC3       //  set port as Input or Output

#define OUTPUT 0
#define INPUT 1
#define LOW 0
#define HIGH 1

// returned states from sensor reading
#define OK			0
#define	TIMEOUT		1
#define CHECKSUM	2

uint8_t  DHT22_data[5]; // data buffer from sensor

extern void DHT22_expect(uint8_t level);
extern uint8_t DHT22_start(void);
extern uint8_t DHT22_read(void);



#endif	// header guard