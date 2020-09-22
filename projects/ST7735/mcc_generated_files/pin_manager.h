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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.5
        Device            :  PIC16F18346
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
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

// get/set CS_RA0 aliases
#define CS_RA0_TRIS                 TRISAbits.TRISA0
#define CS_RA0_LAT                  LATAbits.LATA0
#define CS_RA0_PORT                 PORTAbits.RA0
#define CS_RA0_WPU                  WPUAbits.WPUA0
#define CS_RA0_OD                   ODCONAbits.ODCA0
#define CS_RA0_ANS                  ANSELAbits.ANSA0
#define CS_RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define CS_RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define CS_RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define CS_RA0_GetValue()           PORTAbits.RA0
#define CS_RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define CS_RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define CS_RA0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define CS_RA0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define CS_RA0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define CS_RA0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define CS_RA0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define CS_RA0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set DC_RA1 aliases
#define DC_RA1_TRIS                 TRISAbits.TRISA1
#define DC_RA1_LAT                  LATAbits.LATA1
#define DC_RA1_PORT                 PORTAbits.RA1
#define DC_RA1_WPU                  WPUAbits.WPUA1
#define DC_RA1_OD                   ODCONAbits.ODCA1
#define DC_RA1_ANS                  ANSELAbits.ANSA1
#define DC_RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define DC_RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define DC_RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define DC_RA1_GetValue()           PORTAbits.RA1
#define DC_RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define DC_RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define DC_RA1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define DC_RA1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define DC_RA1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define DC_RA1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define DC_RA1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define DC_RA1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set SDATA_RA2 aliases
#define SDATA_RA2_TRIS                 TRISAbits.TRISA2
#define SDATA_RA2_LAT                  LATAbits.LATA2
#define SDATA_RA2_PORT                 PORTAbits.RA2
#define SDATA_RA2_WPU                  WPUAbits.WPUA2
#define SDATA_RA2_OD                   ODCONAbits.ODCA2
#define SDATA_RA2_ANS                  ANSELAbits.ANSA2
#define SDATA_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define SDATA_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define SDATA_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define SDATA_RA2_GetValue()           PORTAbits.RA2
#define SDATA_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define SDATA_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define SDATA_RA2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define SDATA_RA2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define SDATA_RA2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define SDATA_RA2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define SDATA_RA2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define SDATA_RA2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set SCLK_RA4 aliases
#define SCLK_RA4_TRIS                 TRISAbits.TRISA4
#define SCLK_RA4_LAT                  LATAbits.LATA4
#define SCLK_RA4_PORT                 PORTAbits.RA4
#define SCLK_RA4_WPU                  WPUAbits.WPUA4
#define SCLK_RA4_OD                   ODCONAbits.ODCA4
#define SCLK_RA4_ANS                  ANSELAbits.ANSA4
#define SCLK_RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define SCLK_RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define SCLK_RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define SCLK_RA4_GetValue()           PORTAbits.RA4
#define SCLK_RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define SCLK_RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define SCLK_RA4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define SCLK_RA4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define SCLK_RA4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define SCLK_RA4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define SCLK_RA4_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define SCLK_RA4_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RST_RA5 aliases
#define RST_RA5_TRIS                 TRISAbits.TRISA5
#define RST_RA5_LAT                  LATAbits.LATA5
#define RST_RA5_PORT                 PORTAbits.RA5
#define RST_RA5_WPU                  WPUAbits.WPUA5
#define RST_RA5_OD                   ODCONAbits.ODCA5
#define RST_RA5_ANS                  ANSELAbits.ANSA5
#define RST_RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RST_RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RST_RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RST_RA5_GetValue()           PORTAbits.RA5
#define RST_RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RST_RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RST_RA5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define RST_RA5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define RST_RA5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define RST_RA5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define RST_RA5_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define RST_RA5_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

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

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

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

// get/set LED_RC5 aliases
#define LED_RC5_TRIS                 TRISCbits.TRISC5
#define LED_RC5_LAT                  LATCbits.LATC5
#define LED_RC5_PORT                 PORTCbits.RC5
#define LED_RC5_WPU                  WPUCbits.WPUC5
#define LED_RC5_OD                   ODCONCbits.ODCC5
#define LED_RC5_ANS                  ANSELCbits.ANSC5
#define LED_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LED_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LED_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LED_RC5_GetValue()           PORTCbits.RC5
#define LED_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LED_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LED_RC5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define LED_RC5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define LED_RC5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define LED_RC5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define LED_RC5_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define LED_RC5_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

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