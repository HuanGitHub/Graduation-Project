#include "BELL.h"

void Bell_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOBELL | RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOC	, ENABLE );	   
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_BELL;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	
	GPIO_InitStructure.GPIO_Speed	= GPIO_Speed_50MHz;
	GPIO_Init(GPIOBELL, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	
	GPIO_InitStructure.GPIO_Speed	= GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);	
	
	GPIO_SetBits(GPIOC,GPIO_Pin_14);
//	GPIO_ResetBits(GPIOC,GPIO_Pin_14);
	Bell_Switch(0);
}
void Bell_Switch(u8 flag)
{
	if(!flag)
		GPIO_SetBits(GPIOBELL,GPIO_Pin_BELL);
	else
		GPIO_ResetBits(GPIOBELL,GPIO_Pin_BELL);

}
void Bell_Alarm(void)
{
		Bell_Switch(1);
		delay_ms(100);
		Bell_Switch(0);
		delay_ms(100);
}	
