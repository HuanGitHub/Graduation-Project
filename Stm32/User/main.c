#include "Config.h"
extern PAGE;
extern char FRESH_DISP_FLAG;
SHOW_DATA Show_data;
uint16_t Rxdata;
int main()
{	
	System_init();							//系统初始化

	while(1){
		if(FRESH_DISP_FLAG)
		{
			Show_data = get_Show_Data();
			SHOW_PAGE(PAGE);
			rset_flg(FRESH_DISP_FLAG);
		}
		
		if(Show_data.Smoke > MQ2_VALUE)
		{
			Bell_Alarm();
		}
		send_Normal_data();
		delay_ms(1000);
			
	}

}
void System_init()
{
	USART_init();
	Adc_Init();
	SysTick_init();	   
	OLED_Init();		 
	OLED_Clear(); 
	Bell_Init();
	DHT11_Init();
	IIC_Init();
	BH1750_Init();
	GP2Y_ADC_init();
	Disp_Init();
	TIME3_Init();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO,ENABLE); 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	 
	set_initGPIO(GPIOB,GPIO_Mode_Out_PP,GPIO_Pin_9);
	
	init_Ex_interrupt(EXTI15_10_IRQn,1,1,EXTI_Line15,EXTI_Mode_Interrupt,\
						EXTI_Trigger_Falling,GPIO_PortSourceGPIOB,GPIO_PinSource15);
	init_Ex_interrupt(EXTI15_10_IRQn,1,1,EXTI_Line12,EXTI_Mode_Interrupt,\
						EXTI_Trigger_Falling,GPIO_PortSourceGPIOA,GPIO_PinSource12);	
	init_Ex_interrupt(EXTI15_10_IRQn,1,1,EXTI_Line14,EXTI_Mode_Interrupt,\
						EXTI_Trigger_Falling,GPIO_PortSourceGPIOB,GPIO_PinSource14);
	set_initGPIO(GPIOB,GPIO_Mode_IPD,GPIO_Pin_14);
	
	set_initGPIO(GPIOB,GPIO_Mode_IPD,GPIO_Pin_15);
	set_initGPIO(GPIOA,GPIO_Mode_IPD,GPIO_Pin_12);
	GPIO_ResetBits(GPIOB,GPIO_Pin_9);

}

