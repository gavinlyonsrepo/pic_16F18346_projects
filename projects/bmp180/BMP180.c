/*
* File: BMP180.c
* Description: source file for Bmp180 pressure sensor PIC project
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F18346 
* IDE:  MPLAB X v5.30
* Created july 2020
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#include <math.h>
#include "mcc_generated_files/mcc.h"
#include "BMP180.h"

// Begin function reads in data form sensor
// passed mode see header file for details 
// Returns 1 for success 2 for failure. 
uint8_t BMP180begin(uint8_t mode)
{
    if (mode > BMP180_ULTRAHIGHRES)
        mode = BMP180_ULTRAHIGHRES;
  oversampling = mode;


  if (read8(0xD0) != 0x55)
    return 2;

  /* read calibration data */
  ac1 = read16(BMP180_CAL_AC1);
  ac2 = read16(BMP180_CAL_AC2);
  ac3 = read16(BMP180_CAL_AC3);
  ac4 = read16(BMP180_CAL_AC4);
  ac5 = read16(BMP180_CAL_AC5);
  ac6 = read16(BMP180_CAL_AC6);

  b1 = read16(BMP180_CAL_B1);
  b2 = read16(BMP180_CAL_B2);

  mb = read16(BMP180_CAL_MB);
  mc = read16(BMP180_CAL_MC);
  md = read16(BMP180_CAL_MD);
#if BMP180_ENABLE_DIAG
  //Debug Code here 
#endif
  return 1;
}

uint16_t readRawTemperature(void)
{
  if ((ac1 == 0 || ac1 == -1) && (mb == 0 || mb == -1)) {
    // The device parameters were not read properly, or begin() was never executed
    BMP180begin(oversampling);
  }
  write8(BMP180_CONTROL, BMP180_READTEMPCMD);
  __delay_ms(5);
  return read16(BMP180_TEMPDATA);
}

uint32_t readRawPressure(void)
{
  uint32_t raw;

  write8(BMP180_CONTROL, BMP180_READPRESSURECMD + (oversampling << 6));

  if (oversampling == BMP180_ULTRALOWPOWER)
    __delay_ms(5);
  else if (oversampling == BMP180_STANDARD)
    __delay_ms(8);
  else if (oversampling == BMP180_HIGHRES)
    __delay_ms(14);
  else
    __delay_ms(26);

  raw = read16(BMP180_PRESSUREDATA);

  raw <<= 8;
  raw |= read8(BMP180_PRESSUREDATA + 2);
  raw >>= (8 - oversampling);

#if BMP180_ENABLE_DIAG
  Serial.print("Raw pressure: "); Serial.println(raw);
#endif
  return raw;
}

/*
 * Do some pre-calculation for temperature (B5)
 * The manual (BMP180 Data Sheet Rev 1.2) says:
 *  X1 = (UT - AC6) * AC5 / 2^15
 *  X2 = MC * 2^11 / (X1 + MD)
 *  B5 = X1 + X2
 */
int32_t computeB5(int32_t UT)
{
  int32_t X1;
  int32_t X2;
  int32_t B5;
  X1 = ((UT - ac6) * ac5) >> 15;
  X2 = ((int32_t) mc << 11) / (X1 + md);
  B5 = X1 + X2;

#if BMP180_ENABLE_DIAG
  // Debug code here
#endif
  return B5;
}

int32_t readPressure(void)
{
  int32_t UT;
  int32_t UP;
  int32_t B3;
  int32_t B5;
  int32_t B6;
  int32_t X1;
  int32_t X2;
  int32_t X3;
  int32_t p;
  uint32_t B4;
  uint32_t B7;

  UT = readRawTemperature();
  UP = readRawPressure();

#if BMP180_DEBUG == 1
  // use numbers provided by datasheet example
  UT = 27898;
  UP = 23843;
  ac6 = 23153;
  ac5 = 32757;
  mc = -8711;
  md = 2868;
  b1 = 6190;
  b2 = 4;
  ac3 = -14383;
  ac2 = -72;
  ac1 = 408;
  ac4 = 32741;
  oversampling = 0;
#endif

  // Do temperature calculations
  B5 = computeB5(UT);
  // Do pressure calculations
  B6 = B5 - 4000;
  X1 = ((int32_t) b2 * ((B6 * B6) >> 12)) >> 11;
  X2 = ((int32_t) ac2 * B6) >> 11;
  X3 = X1 + X2;
  B3 = ((((int32_t) ac1 * 4 + X3) << oversampling) + 2) / 4;

#if BMP180_ENABLE_DIAG
     // Debug code here
#endif

  X1 = ((int32_t) ac3 * B6) >> 13;
  X2 = ((int32_t) b1 * ((B6 * B6) >> 12)) >> 16;
  X3 = ((X1 + X2) + 2) >> 2;
  B4 = ((uint32_t) ac4 * (uint32_t) (X3 + 32768)) >> 15;
  B7 = ((uint32_t) UP - B3) * (uint32_t) (50000UL >> oversampling);

#if BMP180_ENABLE_DIAG
    // Debug code here
#endif

  if (B7 < 0x80000000) {
    p = (B7 * 2) / B4;
  } else {
    p = (B7 / B4) * 2;
  }
  X1 = (p >> 8) * (p >> 8);
  X1 = (X1 * 3038) >> 16;
  X2 = (-7357 * p) >> 16;

#if BMP180_ENABLE_DIAG
  // Debug code here
#endif

  p = p + ((X1 + X2 + (int32_t) 3791) >> 4);
#if BMP180_ENABLE_DIAG
  // Debug code here
#endif
  return p;
}

/*
 * Read and calculate true temperature
 * The manual (BMP180 Data Sheet Rev 1.2) says:
 *  X1 = (UT - AC6) * AC5 / 2^15
 *  X2 = MC * 2^11 / (X1 + MD)
 *  B5 = X1 + X2
 *  T = (B5 + 8) / 2^4
 * and this is in units of 0.1 degrees Celcius
 */
float readTemperature(void)
{
  int32_t UT, B5;
  float temp;

  UT = readRawTemperature();

#if BMP180_DEBUG == 1
  // use numbers provided in the datasheet example.
  UT = 27898;
  ac6 = 23153;
  ac5 = 32757;
  mc = -8711;
  md = 2868;
#endif

  B5 = computeB5(UT);
  temp = (B5 + 8) >> 4;
  temp /= 10;

  return temp;
}

 /* Function to Read the pressure calculated to Sea Level Pressure based on the passed
 * altitude and local gravity */
int32_t readPressureTwo(int32_t altitude, float gravity)
{
  float Rd = 287.0f; // dry gas constant for the atmosphere
  int32_t pressure = readPressure();
  float temperature = readTemperature();
  int32_t seaLevelPressure = pressure + pressure -
          ((pressure * 1000) / exp((gravity * altitude) / (Rd * (temperature + 273.15)))) / 1000;
  return seaLevelPressure;
}

/* Function to Read Altitude,  given sea level pressure */
float readAltitude(float sealevelPressure)
{
  float altitude;

  float pressure = readPressure();

  altitude = 44330 * (1.0 - pow(pressure / sealevelPressure, 0.1903));

  return altitude;
}

/* Function  to Read a 1 byte register */
uint8_t read8(uint8_t a)
{
  uint8_t ret;
  uint8_t data_I2C[1];
  data_I2C[0] = a;
  i2c_writeNBytes (BMP180_I2CADDR, data_I2C, 1);
  i2c_readNBytes (BMP180_I2CADDR, data_I2C, 1);
  ret = data_I2C[0];
  return ret;
}

/* Function to read Read a 2 byte register */
uint16_t read16(uint8_t a)
{
  uint16_t ret;
  uint8_t data_I2C[2];
  data_I2C[0] = a;
  i2c_writeNBytes (BMP180_I2CADDR, data_I2C, 1);
  i2c_readNBytes (BMP180_I2CADDR,  data_I2C, 2);
  ret = data_I2C[0];
  ret <<= 8;
  ret = ret | data_I2C[1]; 
  return ret;
}

/* Function to Write a 1 byte register */
void write8(uint8_t a, uint8_t d)
{
    uint8_t data_I2C[2];
    data_I2C[0] = a;
    data_I2C[1] = d;
    i2c_writeNBytes (BMP180_I2CADDR, data_I2C, 2);  
}