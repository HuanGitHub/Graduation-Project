/*�Y���꘢LED��1�b?�ꉺ*/
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
        //�g�\?��??�a??���??
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR|RCC_APB1Periph_BKP, ENABLE);
        //�g�\RTC�a�@?�񑶊�??
        PWR_BackupAccessCmd(ENABLE);
        BKP_DeInit();   //?��??���
        RCC_LSEConfig(RCC_LSE_ON);  //??�O���ᑬ�U?��
        while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) != SET); //���ҊO���ᑬ??���U�A?
//      �g�\RTC����40K ??
//      RCC_LSICmd(ENABLE);
//    while(RCC_GetFlagStatus(RCC_FLAG_LSIRDY) != SET);
        RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE); //??RTC�O��???�ᑬ���U 32.768
        RCC_RTCCLKCmd(ENABLE); //�g�\RTC??
        RTC_WaitForSynchro();       //����RTC�񑶊퓯?
        RTC_WaitForLastTask();  //���Ҏ�RTC�񑶊튮��
        RTC_ITConfig(RTC_IT_SEC, ENABLE);   //�g�\RTC�񑶊�b���f
        RTC_WaitForLastTask();  //���Ҏ�RTC�񑶊튮��
        RTC_EnterConfigMode();  //��?�z�u
        RTC_SetPrescaler(32767);    //?�u?��? �����?��1
        RTC_WaitForLastTask();      //���Ҏʊ񑶊튮��
        RTC_ExitConfigMode();       //�ޏo�z�u�͎�
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
    �������\�FRTC ���n����?�uRTC��?
    �����Q���F
    �ԉ�?�F    
*/
void RTC_Init(void)
{

    if (BKP_ReadBackupRegister(BKP_DR1) != 0x5050)
    {
        RTC_Configuartion();        //��ꎟ?�s ���n��?�u
        RTC_WaitForLastTask();  //���Ҏ�RTC�񑶊튮��
//  RTC_SetCounter(0);          //?�u??��?
        RTC_EnterConfigMode();
        RTC_SetSec(2016,10,20,1,5,59);
        RTC_WaitForLastTask();  //���Ҏʊ񑶊튮��
        RTC_ExitConfigMode();
        BKP_WriteBackupRegister(BKP_DR1, 0x5050);   //�ʓ��z�u?�u
    }else
    {
        RTC_WaitForSynchro();       //����RTC�񑶊퓯?
        RTC_WaitForLastTask();  //���Ҏ�RTC�񑶊튮��
        RTC_ITConfig(RTC_IT_SEC, ENABLE);   //�g�\RTC �b���f
        RTC_WaitForLastTask();  //���Ҏ�RTC�񑶊튮��
    }
    RCC_ClearFlag();    //����?��?�u
    NVIC_Configuartion();

    LED_Init();
}
/***********************���f����??�N********/
const uint8_t monthTable[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
/*
    �������\�F���f����?�N
    �����Q���F���v���f�I�N?
    �ԉ�?�F    �ԉ�1���� ������?
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
    �������\�F����???�b��z�uRTC
    �����Q���F�N�A���A���A?�A���A�b
    �ԉ�?�F    �ԉ�0���� ������?
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
        if (isLeapYear(year) && i==1)   //?�N ������V
        {
            secCount += 86400UL;
        }
    }
    secCount += (uint32_t)(day-1) * 86400UL;    
    secCount += (uint32_t)(hour)*3600;
    secCount += (uint32_t)(minute)*60;
    secCount += (uint32_t)(sec);
    printf("%u\n",secCount);

    /*?�s�ȉ�����Ȏg�\???�񑶊�a RTC �I??�F 
    1�j��??�u�񑶊� RCC_APB1ENR �I PWREN �a BKPEN �ʗ���??���a�@?�ڌ��I?? 
    2�j?���T���񑶊�(PWR_CR)�I DBP �ʗ��g�\?�@?�񑶊�a RTC �I??
    */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR|RCC_APB1Periph_BKP, ENABLE);
    PWR_BackupAccessCmd(ENABLE);
    RTC_SetCounter(secCount);
    RTC_WaitForLastTask();
    return 0;
}
/********************************************************************************/
/*
    �������\�F��RTC?��b???�N�A���A���A�����A?�A���A�b
                        ���� struct thisDate ��
    �����Q���Fstruct thisDate 
    �ԉ�?�F    �ԉ�0���� ������?
*/
uint8_t RTC_GetDate(struct DATETABLE* thisDate)
{
    uint32_t timeCount = 0;
    uint32_t Count ;
    uint16_t tmp = 0;
    timeCount = RTC_GetCounter();
    Count = timeCount/86400UL;  //?�Z�o�V��
    thisDate->week = (4+Count)%7;
    if (Count !=0)                  //�嘰��V
    {
        tmp = 1970;                     //��1970�N?�n
        while(Count>=365)
        {
            if (isLeapYear(tmp))//��?�N
            {
                if (Count>= 366)    //�V���嘰366
                {
                    Count -= 366;
                }else
                {
                    tmp++;                  //�V������366 �ō@��N
                    break;
                }
            }else
            {
                Count -= 365;       //���N
            }
                tmp++;
        }
        thisDate->year = tmp;   //?�擞���N
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
                    break;  //���N��?�N �� �^?
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
        thisDate->month = tmp+1;    //?�擞��
        thisDate->day = Count+1;    //?�擞��
    }
    Count = timeCount%86400UL;
    thisDate->hour = Count/3600;
    thisDate->minute = (Count%3600)/60;
    thisDate->sec = (Count%3600)%60;
    return 0;
}
