#ifndef __RTC_H
#define __RTC_H

static void RCC_Configuartion(void);



static void LED_Init(void);


static void GPIO_Configuartion(void);
static void RTC_Configuartion(void);

void RTC_IRQHandler(void);
void RTC_Init(void);

static void NVIC_Configuartion(void);

static uint8_t isLeapYear(uint16_t mYear)   ;
uint8_t RTC_SetSec(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t sec);
uint8_t RTC_GetDate(struct DATETABLE* thisDate);
#endif

