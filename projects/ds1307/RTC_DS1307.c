
#include "RTC_DS1307.h"  
#include "HD44780_I2C_lcd.h" // custom
#include "mcc_generated_files/mcc.h"

uint8_t rtcBuff[7] = {0};
rtc_time_read_t rtcData;

// Func Desc:
// Hardcode set RTC time date to 20-07-09-Fri-18-56-0
// mostly used for testing and debugging  ... mostly
void RTCDS1307_writeClockStart() {

    //20-07-09-Fri-18-56-00
    rtcData.secH = 0;
    rtcData.secH = 0;
    rtcData.minL = 6;
    rtcData.minH = 5;
    rtcData.hourL = 8;
    rtcData.hourH = 1;
    rtcData.day = 5;
    rtcData.dateL = 9;
    rtcData.dateH = 0;
    rtcData.monthL = 7;
    rtcData.monthH = 0;
    rtcData.yearL = 0;
    rtcData.yearH = 2;

    memcpy(rtcBuff, &rtcData, sizeof (rtcData));
    uint8_t data_I2C[8];
    data_I2C[0] = 0x00;
    data_I2C[1] = rtcBuff[0];
    data_I2C[2] = rtcBuff[1];
    data_I2C[3] = rtcBuff[2];
    data_I2C[4] = rtcBuff[3];
    data_I2C[5] = rtcBuff[4];
    data_I2C[6] = rtcBuff[5];
    data_I2C[7] = rtcBuff[6];
    i2c_writeNBytes(RTC_ADDR, data_I2C, 8);
}

// Func Desc writes time date to the clock 
// Param1: time date to write as char array YYMMDDWHHMM where W = day of the week
void RTCDS1307_writeClock(char *str) {
    
    rtcData.secH = 0;
    rtcData.secH = 0;
    rtcData.minL = str[10];
    rtcData.minH = str[9];
    rtcData.hourL = str[8];
    rtcData.hourH = str[7];
    rtcData.day = str[6];
    rtcData.dateL = str[5];
    rtcData.dateH = str[4];
    rtcData.monthL = str[3];
    rtcData.monthH = str[2];
    rtcData.yearL = str[1];
    rtcData.yearH = str[0];

    memcpy(rtcBuff, &rtcData, sizeof (rtcData));
    uint8_t data_I2C[8];
    data_I2C[0] = 0x00;
    data_I2C[1] = rtcBuff[0];
    data_I2C[2] = rtcBuff[1];
    data_I2C[3] = rtcBuff[2];
    data_I2C[4] = rtcBuff[3];
    data_I2C[5] = rtcBuff[4];
    data_I2C[6] = rtcBuff[5];
    data_I2C[7] = rtcBuff[6];
    i2c_writeNBytes(RTC_ADDR, data_I2C, 8);
}

// Func Desc : Read time date from the RTC
// Param1: timebuffer HHMM (to check alarm))
char* RTCDS1307_readClock(void) {
    i2c_writeNBytes(RTC_ADDR, Ds1307SecondRegAddress, 1); // 0x00
    i2c_readNBytes(RTC_ADDR, rtcBuff, 7);
    char nameday[4];
    char printBuffer[25] = {0};
    static char timeBuffer[4] ={0}; //declared static as it returned
    
    DayOfWeek_e DayofWeek;
        
    memcpy(&rtcData, rtcBuff, sizeof (rtcData));

    
    switch (rtcData.day) {
        case Sunday: strcpy(nameday, "Sun");
            break;
        case Monday: strcpy(nameday, "Mon");
            break;
        case Tuesday: strcpy(nameday, "Tue");
            break;
        case Wednesday: strcpy(nameday, "Wed");
            break;
        case Thursday: strcpy(nameday, "Thu");
            break;
        case Friday: strcpy(nameday, "Fri");
            break;
        case Saturday: strcpy(nameday, "Sat");
            break;
    }
    sprintf(printBuffer, "20%d%d/%d%d/%d%d %s",
            rtcData.yearH,
            rtcData.yearL,
            rtcData.monthH,
            rtcData.monthL,
            rtcData.dateH,
            rtcData.dateL,
            nameday
            );
    PCF8574_LCDGOTO(1, 0);
    PCF8574_LCDSendString(printBuffer);
    PCF8574_LCDSendChar(' ');
    PCF8574_LCDSendData(1); // Print clock custom char
    
    sprintf(printBuffer, "%d%d:%d%d:%d%d",
            rtcData.hourH,
            rtcData.hourL,
            rtcData.minH,
            rtcData.minL,
            rtcData.secH,
            rtcData.secL
            );
    PCF8574_LCDGOTO(2, 0);
    PCF8574_LCDSendString(printBuffer);
    sprintf(timeBuffer, "%d%d%d%d", rtcData.hourH, rtcData.hourL, rtcData.minH, rtcData.minL);
    return timeBuffer; // return char *
}

// Checks on startup to see if RTC is present on I2C bus
// Returns
// True = present
// False = not present
bool RTCDS1307_IsPresentClock(void) {
    uint8_t data_TX_I2C[2];
    uint8_t data_RX_I2C[1];
    data_TX_I2C[0] = Ds1307ControlRegAddress; //0x07
    data_TX_I2C[1] = Ds1307SecondRegAddress; //0x00
    i2c_writeNBytes(RTC_ADDR, data_TX_I2C, 2);
    i2c_readNBytes(RTC_ADDR, data_RX_I2C, 1);
    return !(data_RX_I2C[0] & 0x80);
}