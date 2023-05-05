/* 
 * @file  RGB_LED.c
 * @brief handles the RGB LED lighting 
 * @author gavin lyons
 */


#include "RGB_LED.h"

/*!
    @brief Sets the color of the RGB's 
    @param  RGBcolorsDisplay an enum with the RGB value
 */
void RGBDisplay(RGB_colors_e RGBcolorsDisplay) {
    // RGBcolorsDisplay 0x0000 0RGB
    
    RED_RB4_LAT = (RGBcolorsDisplay >> 2) & 1 ;
    GREEN_RB5_LAT = (RGBcolorsDisplay >> 1) & 1 ;
    BLUE_RB6_LAT = RGBcolorsDisplay & 1;
}

