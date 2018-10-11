#include "MQ-2.h"
#include "stm32f10x.h"
void MQ2_Init(void)
{
	ADC_InitTypeDef ADC_InitStructure; 
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOMQ2 , ENABLE );	  //使能ADC1通道时钟

                      
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_MQ2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		
	GPIO_Init(GPIOMQ2, &GPIO_InitStructure);	

}

u16 Get_MQ2_Average(void)
{
	u32 temp_val=0;
	u8 t;
	for(t=0;t<Times;t++)
	{
		temp_val+=Get_Adc( ADC_Channel_MQ2);
		delay_ms(5);
	}
	return temp_val/Times;
} 	 