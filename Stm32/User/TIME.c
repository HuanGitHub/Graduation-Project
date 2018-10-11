
#include "TIME.h"
#include "Display.h"

extern SHOW_DATA	Show_data;
Flag_Bit FRESH_DISP_FLAG;
char time;
void TIM3_IRQHandler()
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET)
	{
		time++;
		if(time == 10)
		{
			time = 0;
			set_flg(FRESH_DISP_FLAG);
		}
		
//		Show_data = get_Show_Data();
//			SHOW_PAGE(PAGE);
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
	}
} 

void TIME3_Init(void)
{

	NVIC_InitTypeDef NVIC_init;
	TIM_TimeBaseInitTypeDef TIM_struct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); 
	
	TIM_struct.TIM_Period=TIM3_Period;
	TIM_struct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_struct.TIM_ClockDivision=TIM_CKD_DIV1 ;
	TIM_struct.TIM_Prescaler=TIM3_Prescale;
	 
	TIM_TimeBaseInit(TIM3,&TIM_struct);
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	
	NVIC_init.NVIC_IRQChannel=TIM3_IRQn;
	NVIC_init.NVIC_IRQChannelCmd=ENABLE;
	NVIC_init.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_init.NVIC_IRQChannelSubPriority=1;
	
	NVIC_Init(&NVIC_init);		
	TIM_Cmd(TIM3,ENABLE);

}
