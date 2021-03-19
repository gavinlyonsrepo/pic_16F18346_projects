/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
        Device            :  PIC16F18346
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode()         do { ANSELBbits.ANSB6 = 1; } while(0)
#define RB6_SetDigitalMode()        do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set LED_RC2 aliases
#define LED_RC2_TRIS                 TRISCbits.TRISC2
#define LED_RC2_LAT                  LATCbits.LATC2
#define LED_RC2_PORT                 PORTCbits.RC2
#define LED_RC2_WPU                  WPUCbits.WPUC2
#define LED_RC2_OD                   ODCONCbits.ODCC2
#define LED_RC2_ANS                  ANSELCbits.ANSC2
#define LED_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LED_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LED_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LED_RC2_GetValue()           PORTCbits.RC2
#define LED_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LED_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LED_RC2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LED_RC2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LED_RC2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define LED_RC2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define LED_RC2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define LED_RC2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set DHT22_RC3 aliases
#define DHT22_RC3_TRIS                 TRISCbits.TRISC3
#define DHT22_RC3_LAT                  LATCbits.LATC3
#define DHT22_RC3_PORT                 PORTCbits.RC3
#define DHT22_RC3_WPU                  WPUCbits.WPUC3
#define DHT22_RC3_OD                   ODCONCbits.ODCC3
#define DHT22_RC3_ANS                  ANSELCbits.ANSC3
#define DHT22_RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define DHT22_RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define DHT22_RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define DHT22_RC3_GetValue()           PORTCbits.RC3
#define DHT22_RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define DHT22_RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define DHT22_RC3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define DHT22_RC3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define DHT22_RC3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define DHT22_RC3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define DHT22_RC3_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define DHT22_RC3_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/