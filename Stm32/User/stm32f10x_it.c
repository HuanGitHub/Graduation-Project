#include "stm32f10x_it.h"
#include "Config.h"
extern PAGE;
extern Clear_Oled;
extern uint16_t Rxdata;
void EXTI15_10_IRQHandler()	
{
	//printf("Enter interrupt\r\n");
	if(EXTI_GetITStatus(EXTI_Line15)){
		
		PAGE = PAGE_SECOND;
		EXTI_ClearITPendingBit(EXTI_Line15);
	}
	if(EXTI_GetITStatus(EXTI_Line12)){
		
		PAGE = PAGE_FIRST;
	//	EXTI->IMR = 0x00;											//Ö±½Ó²Ù×÷¼Ä´æÆ÷ÆÁ±ÎÖÐ¶Ï£»
	//	EXTI_DeInit();
		EXTI_ClearITPendingBit(EXTI_Line12);
	}
	if(EXTI_GetITStatus(EXTI_Line14)){
	
		PAGE = PAGE_SECOND;
		EXTI_ClearITPendingBit(EXTI_Line14);
	}
}


void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}
void Door_Con()
{

}
char door_flag =0;
void USART1_IRQHandler(void)
{
	uint16_t res;
	
	if(USART_GetITStatus(USART1,USART_IT_RXNE))
	{
		res=USART_ReceiveData(USART1);	
//		USART_SendData(USART1,res);		
	}
		if(res == 13)
		{
	//		printf("%d",res);
			if(door_flag == 0){
				GPIO_SetBits(GPIOC,GPIO_Pin_14);
				door_flag = 1;
			}
			else{
				GPIO_ResetBits(GPIOC,GPIO_Pin_14);
				door_flag =0;
			}
		}
		if(res == 15){
			Bell_Alarm();
			GPIO_ResetBits(GPIOC,GPIO_Pin_14);
		}
//	 Rxdata = res;

}
