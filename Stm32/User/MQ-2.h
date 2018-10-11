#ifndef __MQ_H
#define __MQ_H
#include "stm32f10x.h"
#include "Adc.h"
#define RCC_APB2Periph_GPIOMQ2 RCC_APB2Periph_GPIOA
#define ADC_Channel_MQ2		ADC_Channel_4
#define Times 				5
#define GPIO_Pin_MQ2		GPIO_Pin_4
#define GPIOMQ2				GPIOA

void MQ2_Init(void);
u16 Get_MQ2_Average(void);


#endif
