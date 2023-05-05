/* 
 * @file  RGB_LED.h
 * @brief handles the RGB LED lighting 
 * @author gavin lyons
 */

#include "mcc_generated_files/mcc.h"

#ifndef RGB_LED_H
#define	RGB_LED_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum  {
    RGBOff     = 0x00, // all off
    RGBBlue    = 0x01, // blue
    RGBGreen   = 0x02, // green
    RGBCyan    = 0x03, // blue + green on
    RGBRed     = 0x04, // red
    RGBMagneta = 0x05, // red + blue on
    RGBYellow  = 0x06, // Red + green on
    RGBWhite   = 0x07 // all on 
}RGB_colors_e; // List of available RGB LED colors bitwise set

void RGBDisplay(RGB_colors_e color);

#ifdef	__cplusplus
}
#endif

#endif	/* RGB_LED_H */

