/*
* File: main.c
* Description: RGB LED  PIC project 
* Author: Gavin Lyons.
* Complier: xc8 v2.40 compiler
* PIC: PIC16F18346 
* IDE:  MPLAB X v6.0
* Created April 2023
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/


// Libraries 
#include "RGB_LED.h"
#include "Push_button.h"

#include "mcc_generated_files/mcc.h"
#include <time.h> // to seed srand

//delays
#define SETUP_DELAY 1000 //mS delay used in setup during LED test.

// Function Prototypes
void Setup(void);
void TimeMode(void);
void SteadyMode(uint8_t _runMode);
uint16_t mapADCTime(uint16_t x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max);
void ADCRead(void);

/* 
 * Main application:
 * Theory of operation:
 * By default the Display is set to a random RGB color
 * The rate of change is defined by reading of an ADC input.
 * A push button changes the state to steady ON 
 * Each subsequent push  button press changes steady state to a different color
 */
void main(void)
{  
    Setup();
    uint8_t runMode = 0;  // 0 = timer mode 1-8 = steady modes
    
    // Seed random generator 
    time_t toc;
    time(&toc);
    srand((uint16_t) toc);
    
    while (1)
    {
        if (runMode == 0)
            TimeMode(); //  If run mode is zero we execute TimeMode

        if (gPushButtonEvent == true) // if push button is pressed 
        {
            LED_RA5_SetHigh();
            gPushButtonEvent = false;
            runMode++;
            SteadyMode(runMode); // enter steady mode 1-8
            LED_RA5_SetLow();
            if (runMode == 9) // when push button is pressed on 8 go back to timeMode
                runMode = 0;
        }
    }
} // --- end of main ---

// --- Function Space ---

/*!
    @brief initialize the device and carries out RGB test before starting
 */
void Setup(void)
{
    SYSTEM_Initialize();   // initialize the device
    INTERRUPT_GlobalInterruptEnable();     // Enable the Global Interrupts
    INTERRUPT_PeripheralInterruptEnable(); // Enable the Peripheral Interrupts
    //INTERRUPT_GlobalInterruptDisable();  // Disable the Global Interrupts
    //INTERRUPT_PeripheralInterruptDisable();   // Disable the Peripheral Interrupts
     
    //  Display colour's test RGB at start at start-up
    LED_RA5_SetHigh();

    RGBDisplay(RGBRed);
    __delay_ms(SETUP_DELAY);
    RGBDisplay(RGBGreen);
    __delay_ms(SETUP_DELAY);
    RGBDisplay(RGBBlue);
    __delay_ms(SETUP_DELAY);
    
     LED_RA5_SetLow();
     
     //get ADC dummy read as first value is often inaccurate for some reason!
    uint16_t potValueDummy = 0; //var to hold pot value from RA4
    potValueDummy = ADC_GetConversion(POT_ANA0)>> 6;

}

/*!
 *  @brief Carries out Steady Mode (runMode 1-8)
 *  Steady mode displays a single color 
 *  color( + runmode) is changed by a push button press
 *  when  9 is reached goes back to timeMode state
 */
void SteadyMode(uint8_t _runMode)
{
    switch(_runMode)
    {
        case 0:  return;               break;
        case 1: RGBDisplay(RGBRed);    break;
        case 2: RGBDisplay(RGBGreen);  break;
        case 3: RGBDisplay(RGBBlue);   break;
        case 4: RGBDisplay(RGBOff);    break;
        case 5: RGBDisplay(RGBYellow); break;
        case 6: RGBDisplay(RGBMagneta);break;
        case 7: RGBDisplay(RGBCyan);   break;
        case 8: RGBDisplay(RGBWhite);  break;    
    }
}

/*!
    @brief Function to carry out the TimeMode(runMode = 0)
           TimeMode displays a random color at an interval controlled by ADCchannel ANA0 value
    @note Reads the ADC uses that to set the rate that custom Ticker callback
        function called, timer1 interrupts on 500mS interval so 60 = 30 seconds.
        The color is chosen at random
 */
void TimeMode(void)
{
    ADCRead();
    if (gTimer1ColorChange == true) // changed by timer1 callback
    {
        static uint8_t lastColor = 1;  // Keep track of last color 
        uint8_t colorMode;
        //every 30 seconds change color random
        do 
        {
            colorMode = rand() % 7 + 1;
        }while (colorMode == lastColor);
        
        switch(colorMode)
        {
            case 1: RGBDisplay(RGBRed);    break;
            case 2: RGBDisplay(RGBGreen);  break;
            case 3: RGBDisplay(RGBBlue);   break;
            case 4: RGBDisplay(RGBYellow); break;
            case 5: RGBDisplay(RGBMagneta);break;
            case 6: RGBDisplay(RGBCyan);   break;
            case 7: RGBDisplay(RGBWhite);  break;
                
        }
     lastColor = colorMode;
     gTimer1ColorChange = false;
     LED_RA5_Toggle();
    }  
}

/*!
    @brief Function Map the ADC to the Timer1 interrupt Ticker Factor(500 mS per tick) 
    @param x ADCvalue The reading from the ADc  channel
    @param in_min minimum range of ADC 
    @param in_max maximum range of ADC 
    @param out_min minimum value for gTimerOneinteruptTickerFactor 
    @param out_max minimum value for gTimerOneinteruptTickerFactor
    @return mapped value for gTimerOneinteruptTickerFactor  
*/
uint16_t mapADCTime(uint16_t x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/*!
    @brief Reads the ADC
*/
void ADCRead(void)
{
    static uint8_t counter =0 ; 
    counter++;
    if (counter >= 20)
    {
        uint16_t potValue = 0; //var to hold pot value from RA4
        //get ADC 
        potValue = ADC_GetConversion(POT_ANA0)>> 6;
        // Map the ADC to the to the callback ticker timer1 1 = 500mS 0-60
        gTimer1interuptTickerFactor = mapADCTime(potValue ,0 , 1023, 2, 59);
        counter = 0;
    }
}
/** End of File */