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
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);		//ʹ�ܸ���ʱ�Ӻ����ʹ���ж�
		EXTI_InitStruct.EXTI_Line=EXTI_Line;									//ѡ���ж���
		EXTI_InitStruct.EXTI_LineCmd=EXTI_LineCmd;						//�ж�ʹ��
		EXTI_InitStruct.EXTI_Mode=EXTI_Mode;									//�ж�ģʽ
		EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger;						//�жϴ�����ʽ
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOX,GPIO_PinSourceX);		//����GPIO_EXTILineConfig()����GPIO�ж��ߺ� GPIO�����Ŷ�Ӧ
		EXTI_Init(&EXTI_InitStruct);
}

