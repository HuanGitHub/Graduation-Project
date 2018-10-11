/*添加一个LED灯1秒?一下*/
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
        //使能?源??和??区域??
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR|RCC_APB1Periph_BKP, ENABLE);
        //使能RTC和后?寄存器??
        PWR_BackupAccessCmd(ENABLE);
        BKP_DeInit();   //?位??区域
        RCC_LSEConfig(RCC_LSE_ON);  //??外部低速振?器
        while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) != SET); //等待外部低速??晶振就?
//      使能RTC内部40K ??
//      RCC_LSICmd(ENABLE);
//    while(RCC_GetFlagStatus(RCC_FLAG_LSIRDY) != SET);
        RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE); //??RTC外部???低速晶振 32.768
        RCC_RTCCLKCmd(ENABLE); //使能RTC??
        RTC_WaitForSynchro();       //等待RTC寄存器同?
        RTC_WaitForLastTask();  //等待写RTC寄存器完成
        RTC_ITConfig(RTC_IT_SEC, ENABLE);   //使能RTC寄存器秒中断
        RTC_WaitForLastTask();  //等待写RTC寄存器完成
        RTC_EnterConfigMode();  //允?配置
        RTC_SetPrescaler(32767);    //?置?分? 内部会自?加1
        RTC_WaitForLastTask();      //等待写寄存器完成
        RTC_ExitConfigMode();       //退出配置模式
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
    函数功能：RTC 初始化并?置RTC初?
    函数参数：
    返回?：    
*/
void RTC_Init(void)
{

    if (BKP_ReadBackupRegister(BKP_DR1) != 0x5050)
    {
        RTC_Configuartion();        //第一次?行 初始化?置
        RTC_WaitForLastTask();  //等待写RTC寄存器完成
//  RTC_SetCounter(0);          //?置??初?
        RTC_EnterConfigMode();
        RTC_SetSec(2016,10,20,1,5,59);
        RTC_WaitForLastTask();  //等待写寄存器完成
        RTC_ExitConfigMode();
        BKP_WriteBackupRegister(BKP_DR1, 0x5050);   //写入配置?志
    }else
    {
        RTC_WaitForSynchro();       //等待RTC寄存器同?
        RTC_WaitForLastTask();  //等待写RTC寄存器完成
        RTC_ITConfig(RTC_IT_SEC, ENABLE);   //使能RTC 秒中断
        RTC_WaitForLastTask();  //等待写RTC寄存器完成
    }
    RCC_ClearFlag();    //清除?位?志
    NVIC_Configuartion();

    LED_Init();
}
/***********************判断是否??年********/
const uint8_t monthTable[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
/*
    函数功能：判断是否?年
    函数参数：需要判断的年?
    返回?：    返回1成功 其他失?
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
    函数功能：日期???秒并配置RTC
    函数参数：年、月、日、?、分、秒
    返回?：    返回0成功 其他失?
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
        if (isLeapYear(year) && i==1)   //?年 多加一天
        {
            secCount += 86400UL;
        }
    }
    secCount += (uint32_t)(day-1) * 86400UL;    
    secCount += (uint32_t)(hour)*3600;
    secCount += (uint32_t)(minute)*60;
    secCount += (uint32_t)(sec);
    printf("%u\n",secCount);

    /*?行以下操作可以使能???寄存器和 RTC 的??： 
    1）通??置寄存器 RCC_APB1ENR 的 PWREN 和 BKPEN 位来打??源和后?接口的?? 
    2）?源控制寄存器(PWR_CR)的 DBP 位来使能?后?寄存器和 RTC 的??
    */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR|RCC_APB1Periph_BKP, ENABLE);
    PWR_BackupAccessCmd(ENABLE);
    RTC_SetCounter(secCount);
    RTC_WaitForLastTask();
    return 0;
}
/********************************************************************************/
/*
    函数功能：从RTC?取秒???年、月、日、星期、?、分、秒
                        存入 struct thisDate 中
    函数参数：struct thisDate 
    返回?：    返回0成功 其他失?
*/
uint8_t RTC_GetDate(struct DATETABLE* thisDate)
{
    uint32_t timeCount = 0;
    uint32_t Count ;
    uint16_t tmp = 0;
    timeCount = RTC_GetCounter();
    Count = timeCount/86400UL;  //?算出天数
    thisDate->week = (4+Count)%7;
    if (Count !=0)                  //大于一天
    {
        tmp = 1970;                     //从1970年?始
        while(Count>=365)
        {
            if (isLeapYear(tmp))//是?年
            {
                if (Count>= 366)    //天数大于366
                {
                    Count -= 366;
                }else
                {
                    tmp++;                  //天数小于366 最后一年
                    break;
                }
            }else
            {
                Count -= 365;       //平年
            }
                tmp++;
        }
        thisDate->year = tmp;   //?取到了年
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
                    break;  //当年是?年 二月 某?
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
        thisDate->month = tmp+1;    //?取到月
        thisDate->day = Count+1;    //?取到日
    }
    Count = timeCount%86400UL;
    thisDate->hour = Count/3600;
    thisDate->minute = (Count%3600)/60;
    thisDate->sec = (Count%3600)%60;
    return 0;
}
