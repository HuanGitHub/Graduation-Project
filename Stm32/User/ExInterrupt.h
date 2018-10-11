#ifndef __EXINTERRUPT_H
#define __EXINTERRUPT_H
#include "stm32f10x.h"
void EXTI_init(uint32_t EXTI_Line,EXTIMode_TypeDef EXTI_Mode,EXTITrigger_TypeDef EXTI_Trigger,FunctionalState EXTI_LineCmd,\
	uint8_t GPIO_PortSourceGPIOX,uint8_t GPIO_PinSourceX);
void NVIC_init(u8 NVIC_IRQChannel,u8 NVIC_IRQChannelPreemptionPriority,u8 NVIC_IRQChannelSubPriority, FunctionalState NVIC_IRQChannelCmd);

void set_initGPIO(GPIO_TypeDef* GPIOx,GPIOMode_TypeDef Mode,u16 GPIO_Pin_X);
void init_Ex_interrupt(u8 NVIC_IRQChannel,u8 NVIC_IRQChannelPreemptionPriority, \
						u8 NVIC_IRQChannelSubPriority,\
						uint32_t EXTI_Line,EXTIMode_TypeDef EXTI_Mode,EXTITrigger_TypeDef EXTI_Trigger,\
						uint8_t GPIO_PortSourceGPIOX,uint8_t GPIO_PinSourceX);
#endif

