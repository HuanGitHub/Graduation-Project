#ifndef __BELL_H
#define __BELL_H
#include "stm32f10x.h"
#define RCC_APB2Periph_GPIOBELL RCC_APB2Periph_GPIOB
#define GPIO_Pin_BELL GPIO_Pin_3
#define GPIOBELL	GPIOB





void Bell_Init(void);
void Bell_Switch(u8 flag);
void Bell_Alarm(void);





#endif

