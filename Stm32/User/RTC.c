/*YÁê¢LED1b?êº*/
#include "rtc.h"
#include "usart.h"
#include "timer.h"
static void RCC_Configuartion(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
}
static void GPIO_Configuartion(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin= GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

static void LED_Init(void)
{
    RCC_Configuartion();
    GPIO_Configuartion();
}
/***************************************************/
static struct DATETABLE pDate;
static void RTC_Configuartion(void)
{
        //g\?¹??a??ææ??
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR|RCC_APB1Periph_BKP, ENABLE);
        //g\RTCa@?ñ¶í??
        PWR_BackupAccessCmd(ENABLE);
        BKP_DeInit();   //?Ê??ææ
        RCC_LSEConfig(RCC_LSE_ON);  //??Oá¬U?í
        while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) != SET); //ÒOá¬??»UA?
//      g\RTCà40K ??
//      RCC_LSICmd(ENABLE);
//    while(RCC_GetFlagStatus(RCC_FLAG_LSIRDY) != SET);
        RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE); //??RTCO???á¬»U 32.768
        RCC_RTCCLKCmd(ENABLE); //g\RTC??
        RTC_WaitForSynchro();       //ÒRTCñ¶í¯?
        RTC_WaitForLastTask();  //ÒÊRTCñ¶í®¬
        RTC_ITConfig(RTC_IT_SEC, ENABLE);   //g\RTCñ¶íbf
        RTC_WaitForLastTask();  //ÒÊRTCñ¶í®¬
        RTC_EnterConfigMode();  //ò?zu
        RTC_SetPrescaler(32767);    //?u?ª? àï©?Á1
        RTC_WaitForLastTask();      //ÒÊñ¶í®¬
        RTC_ExitConfigMode();       //ÞozuÍ®
}
static void NVIC_Configuartion(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = RTC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}
void RTC_IRQHandler(void)
{
    if (RTC_GetITStatus(RTC_IT_SEC) == SET)
    {
        RTC_ClearITPendingBit(RTC_IT_SEC);
        RTC_GetDate(&pDate);
        printf("%d-%2d-%2d-%d\t%02d:%02d:%02d\n", pDate.year, pDate.month, pDate.day, pDate.week, pDate.hour, pDate.minute, pDate.sec);
        GPIO_WriteBit(GPIOB, GPIO_Pin_6, (BitAction)(1-GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_6)));
    }
}
/******************************************************/
/*
    ÷\FRTC n»ó?uRTC?
    QF
    Ôñ?F    
*/
void RTC_Init(void)
{

    if (BKP_ReadBackupRegister(BKP_DR1) != 0x5050)
    {
        RTC_Configuartion();        //æê?s n»?u
        RTC_WaitForLastTask();  //ÒÊRTCñ¶í®¬
//  RTC_SetCounter(0);          //?u???
        RTC_EnterConfigMode();
        RTC_SetSec(2016,10,20,1,5,59);
        RTC_WaitForLastTask();  //ÒÊñ¶í®¬
        RTC_ExitConfigMode();
        BKP_WriteBackupRegister(BKP_DR1, 0x5050);   //Êüzu?u
    }else
    {
        RTC_WaitForSynchro();       //ÒRTCñ¶í¯?
        RTC_WaitForLastTask();  //ÒÊRTCñ¶í®¬
        RTC_ITConfig(RTC_IT_SEC, ENABLE);   //g\RTC bf
        RTC_WaitForLastTask();  //ÒÊRTCñ¶í®¬
    }
    RCC_ClearFlag();    //´?Ê?u
    NVIC_Configuartion();

    LED_Init();
}
/***********************»f¥Û??N********/
const uint8_t monthTable[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
/*
    ÷\F»f¥Û?N
    QFùv»fIN?
    Ôñ?F    Ôñ1¬÷ ´¼¸?
*/
static uint8_t isLeapYear(uint16_t mYear)   
{
    if (((mYear%4 == 0)&&((mYear%100) != 0))||(mYear%400) == 0)
    {
        return 1;
    }else 
    {
        return 0;
    }
}
/********************************************************************************/
/*
    ÷\Fúú???bózuRTC
    QFNAAúA?AªAb
    Ôñ?F    Ôñ0¬÷ ´¼¸?
*/
uint8_t RTC_SetSec(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t sec)
{
    uint32_t secCount = 0;
  uint16_t i;

    if (year <1970 || year >2099)
    {
        return 1;
    }
    for (i=1970; i<year; i++)
    {
        if (isLeapYear(i))
        {
            secCount += 31622400UL;
        }
        else
        {
            secCount += 31536000UL;
        }
    }

    for (i=0; i<month-1; i++)
    {
        secCount += ((uint32_t)monthTable[i]*86400UL);
        if (isLeapYear(year) && i==1)   //?N ½ÁêV
        {
            secCount += 86400UL;
        }
    }
    secCount += (uint32_t)(day-1) * 86400UL;    
    secCount += (uint32_t)(hour)*3600;
    secCount += (uint32_t)(minute)*60;
    secCount += (uint32_t)(sec);
    printf("%u\n",secCount);

    /*?sÈºìÂÈg\???ñ¶ía RTC I??F 
    1jÊ??uñ¶í RCC_APB1ENR I PWREN a BKPEN ÊÅ??¹a@?ÚûI?? 
    2j?¹T§ñ¶í(PWR_CR)I DBP Êg\?@?ñ¶ía RTC I??
    */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR|RCC_APB1Periph_BKP, ENABLE);
    PWR_BackupAccessCmd(ENABLE);
    RTC_SetCounter(secCount);
    RTC_WaitForLastTask();
    return 0;
}
/********************************************************************************/
/*
    ÷\F¸RTC?æb???NAAúA¯úA?AªAb
                        ¶ü struct thisDate 
    QFstruct thisDate 
    Ôñ?F    Ôñ0¬÷ ´¼¸?
*/
uint8_t RTC_GetDate(struct DATETABLE* thisDate)
{
    uint32_t timeCount = 0;
    uint32_t Count ;
    uint16_t tmp = 0;
    timeCount = RTC_GetCounter();
    Count = timeCount/86400UL;  //?ZoV
    thisDate->week = (4+Count)%7;
    if (Count !=0)                  //å°êV
    {
        tmp = 1970;                     //¸1970N?n
        while(Count>=365)
        {
            if (isLeapYear(tmp))//¥?N
            {
                if (Count>= 366)    //Vå°366
                {
                    Count -= 366;
                }else
                {
                    tmp++;                  //V¬°366 Å@êN
                    break;
                }
            }else
            {
                Count -= 365;       //½N
            }
                tmp++;
        }
        thisDate->year = tmp;   //?æ¹N
        tmp = 0;
        while(Count>= 28)
        {
            if (isLeapYear(thisDate->year) && tmp == 1)
            {
                if (Count >= 29) 
                {
                    Count -= 29;
                }
                else    
                {
                    break;  //N¥?N ñ ^?
                }
            }else
            {
                if (Count >= monthTable[tmp]) 
                {
                    Count -= monthTable[tmp];
                }else
                {
                    break;
                }
            }
                tmp ++;
        }
        thisDate->month = tmp+1;    //?æ
        thisDate->day = Count+1;    //?æú
    }
    Count = timeCount%86400UL;
    thisDate->hour = Count/3600;
    thisDate->minute = (Count%3600)/60;
    thisDate->sec = (Count%3600)%60;
    return 0;
}
