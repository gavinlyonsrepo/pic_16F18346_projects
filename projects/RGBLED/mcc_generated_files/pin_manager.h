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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F18346
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

// get/set POT_ANA0 aliases
#define POT_ANA0_TRIS                 TRISAbits.TRISA0
#define POT_ANA0_LAT                  LATAbits.LATA0
#define POT_ANA0_PORT                 PORTAbits.RA0
#define POT_ANA0_WPU                  WPUAbits.WPUA0
#define POT_ANA0_OD                   ODCONAbits.ODCA0
#define POT_ANA0_ANS                  ANSELAbits.ANSA0
#define POT_ANA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define POT_ANA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define POT_ANA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define POT_ANA0_GetValue()           PORTAbits.RA0
#define POT_ANA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define POT_ANA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define POT_ANA0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define POT_ANA0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define POT_ANA0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define POT_ANA0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define POT_ANA0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define POT_ANA0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set LED_RA5 aliases
#define LED_RA5_TRIS                 TRISAbits.TRISA5
#define LED_RA5_LAT                  LATAbits.LATA5
#define LED_RA5_PORT                 PORTAbits.RA5
#define LED_RA5_WPU                  WPUAbits.WPUA5
#define LED_RA5_OD                   ODCONAbits.ODCA5
#define LED_RA5_ANS                  ANSELAbits.ANSA5
#define LED_RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED_RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED_RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED_RA5_GetValue()           PORTAbits.RA5
#define LED_RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED_RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED_RA5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED_RA5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED_RA5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED_RA5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED_RA5_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define LED_RA5_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RED_RB4 aliases
#define RED_RB4_TRIS                 TRISBbits.TRISB4
#define RED_RB4_LAT                  LATBbits.LATB4
#define RED_RB4_PORT                 PORTBbits.RB4
#define RED_RB4_WPU                  WPUBbits.WPUB4
#define RED_RB4_OD                   ODCONBbits.ODCB4
#define RED_RB4_ANS                  ANSELBbits.ANSB4
#define RED_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RED_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RED_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RED_RB4_GetValue()           PORTBbits.RB4
#define RED_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RED_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RED_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define RED_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define RED_RB4_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define RED_RB4_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define RED_RB4_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define RED_RB4_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set GREEN_RB5 aliases
#define GREEN_RB5_TRIS                 TRISBbits.TRISB5
#define GREEN_RB5_LAT                  LATBbits.LATB5
#define GREEN_RB5_PORT                 PORTBbits.RB5
#define GREEN_RB5_WPU                  WPUBbits.WPUB5
#define GREEN_RB5_OD                   ODCONBbits.ODCB5
#define GREEN_RB5_ANS                  ANSELBbits.ANSB5
#define GREEN_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define GREEN_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define GREEN_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define GREEN_RB5_GetValue()           PORTBbits.RB5
#define GREEN_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define GREEN_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define GREEN_RB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define GREEN_RB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define GREEN_RB5_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define GREEN_RB5_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define GREEN_RB5_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define GREEN_RB5_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set BLUE_RB6 aliases
#define BLUE_RB6_TRIS                 TRISBbits.TRISB6
#define BLUE_RB6_LAT                  LATBbits.LATB6
#define BLUE_RB6_PORT                 PORTBbits.RB6
#define BLUE_RB6_WPU                  WPUBbits.WPUB6
#define BLUE_RB6_OD                   ODCONBbits.ODCB6
#define BLUE_RB6_ANS                  ANSELBbits.ANSB6
#define BLUE_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define BLUE_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define BLUE_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define BLUE_RB6_GetValue()           PORTBbits.RB6
#define BLUE_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define BLUE_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define BLUE_RB6_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define BLUE_RB6_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define BLUE_RB6_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define BLUE_RB6_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define BLUE_RB6_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define BLUE_RB6_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set BTN_RC4 aliases
#define BTN_RC4_TRIS                 TRISCbits.TRISC4
#define BTN_RC4_LAT                  LATCbits.LATC4
#define BTN_RC4_PORT                 PORTCbits.RC4
#define BTN_RC4_WPU                  WPUCbits.WPUC4
#define BTN_RC4_OD                   ODCONCbits.ODCC4
#define BTN_RC4_ANS                  ANSELCbits.ANSC4
#define BTN_RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define BTN_RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define BTN_RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define BTN_RC4_GetValue()           PORTCbits.RC4
#define BTN_RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define BTN_RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define BTN_RC4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define BTN_RC4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define BTN_RC4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define BTN_RC4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define BTN_RC4_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define BTN_RC4_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

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