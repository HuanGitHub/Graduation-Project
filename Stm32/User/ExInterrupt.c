#include "Exinterrupt.h"
void init_Ex_interrupt(u8 NVIC_IRQChannel,u8 NVIC_IRQChannelPreemptionPriority, \
						u8 NVIC_IRQChannelSubPriority,\
						uint32_t EXTI_Line,EXTIMode_TypeDef EXTI_Mode,EXTITrigger_TypeDef EXTI_Trigger,\
						uint8_t GPIO_PortSourceGPIOX,uint8_t GPIO_PinSourceX)
{
	NVIC_init(NVIC_IRQChannel,NVIC_IRQChannelPreemptionPriority,NVIC_IRQChannelSubPriority, ENABLE);	
	EXTI_init(EXTI_Line,EXTI_Mode,EXTI_Trigger,ENABLE,\
				GPIO_PortSourceGPIOX,GPIO_PinSourceX);
	
	
}
void NVIC_init(u8 NVIC_IRQChannel,u8 NVIC_IRQChannelPreemptionPriority,u8 NVIC_IRQChannelSubPriority, FunctionalState NVIC_IRQChannelCmd)
{
		
		NVIC_InitTypeDef NVIC_InitStrut;
		NVIC_InitStrut.NVIC_IRQChannel=NVIC_IRQChannel;
		NVIC_InitStrut.NVIC_IRQChannelCmd=NVIC_IRQChannelCmd;
		NVIC_InitStrut.NVIC_IRQChannelPreemptionPriority=NVIC_IRQChannelPreemptionPriority;
		NVIC_InitStrut.NVIC_IRQChannelSubPriority=NVIC_IRQChannelSubPriority;
		NVIC_Init(&NVIC_InitStrut);

}

void set_initGPIO(GPIO_TypeDef* GPIOx,GPIOMode_TypeDef Mode,u16 GPIO_Pin_X)
{
	GPIO_InitTypeDef GPIO_init;
	GPIO_init.GPIO_Mode = Mode;
	GPIO_init.GPIO_Pin = GPIO_Pin_X;
	GPIO_init.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOx,&GPIO_init);

}

void EXTI_init(uint32_t EXTI_Line,EXTIMode_TypeDef EXTI_Mode,EXTITrigger_TypeDef EXTI_Trigger,FunctionalState EXTI_LineCmd,\
	uint8_t GPIO_PortSourceGPIOX,uint8_t GPIO_PinSourceX)	
{
		EXTI_InitTypeDef EXTI_InitStruct;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);		//使能复用时钟后才能使用中断
		EXTI_InitStruct.EXTI_Line=EXTI_Line;									//选择中断线
		EXTI_InitStruct.EXTI_LineCmd=EXTI_LineCmd;						//中断使能
		EXTI_InitStruct.EXTI_Mode=EXTI_Mode;									//中断模式
		EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger;						//中断触发方式
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOX,GPIO_PinSourceX);		//调用GPIO_EXTILineConfig()设置GPIO中断线和 GPIO组引脚对应
		EXTI_Init(&EXTI_InitStruct);
}

