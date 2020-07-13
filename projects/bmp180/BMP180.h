/*
* File: BMP180.h
* Description: header file for Bmp180 pressure sensor PIC project
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F18346 
* IDE:  MPLAB X v5.30
* Created july 2020
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#ifndef BMP180_H
#define BMP180_H


#define BMP180_ULTRALOWPOWER 0
#define BMP180_STANDARD      1
#define BMP180_HIGHRES       2
#define BMP180_ULTRAHIGHRES  3

#define BMP180_DEBUG 0 // Set to one to use example data form datasheet 15.00C and 69964 pascals
#define BMP180_ENABLE_DIAG 0 

#define BMP180_I2CADDR 0x77

#define BMP180_CAL_AC1           0xAA  // R   Calibration data (16 bits)
#define BMP180_CAL_AC2           0xAC  // R   Calibration data (16 bits)
#define BMP180_CAL_AC3           0xAE  // R   Calibration data (16 bits)
#define BMP180_CAL_AC4           0xB0  // R   Calibration data (16 bits)
#define BMP180_CAL_AC5           0xB2  // R   Calibration data (16 bits)
#define BMP180_CAL_AC6           0xB4  // R   Calibration data (16 bits)
#define BMP180_CAL_B1            0xB6  // R   Calibration data (16 bits)
#define BMP180_CAL_B2            0xB8  // R   Calibration data (16 bits)
#define BMP180_CAL_MB            0xBA  // R   Calibration data (16 bits)
#define BMP180_CAL_MC            0xBC  // R   Calibration data (16 bits)
#define BMP180_CAL_MD            0xBE  // R   Calibration data (16 bits)

#define BMP180_CONTROL           0xF4
#define BMP180_TEMPDATA          0xF6
#define BMP180_PRESSUREDATA      0xF6
#define BMP180_READTEMPCMD       0x2E
#define BMP180_READPRESSURECMD   0x34

#define SEA_LEVEL_PRESSURE 101325 
#define GRAVITY 9.81

  uint8_t BMP180begin(uint8_t mode);  
  
  float readTemperature(void);
  int32_t readPressure(void);

  uint16_t readRawTemperature(void);
  uint32_t readRawPressure(void);
  int32_t computeB5(int32_t UT);
  
  uint8_t read8(uint8_t addr);
  uint16_t read16(uint8_t addr);
  void write8(uint8_t addr, uint8_t data);
  
  int32_t readPressureTwo(int32_t altitude, float gravity ); // g = 9.81
  float readAltitude(float sealevelPressure); // std atmosphere  SLP = 101325

  uint8_t oversampling;
  int16_t ac1, ac2, ac3, b1, b2, mb, mc, md;
  uint16_t ac4, ac5, ac6;

#endif 
