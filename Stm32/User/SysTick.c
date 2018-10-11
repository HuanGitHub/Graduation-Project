#include "SysTick.h"
static u8  fac_us=0;							//us延时倍乘数			   
static u16 fac_ms=0;							//ms延时倍乘数

void SysTick_init(void)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);			//选择定时器的时钟
	fac_us=SystemCoreClock/8000000;														//确定延时倍数 9M/s 如果需要1ns的延时就是9
	fac_ms=(u16)fac_us*1000;
}
void delay_us(u32 nus)
{
	u32 temp;
	SysTick->LOAD=nus*fac_us;																	//将需要的定时时间装入预装载寄存器中
	SysTick->VAL=0x00;																				//清零
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;										//使能定时器 开始倒数
	do{
			temp=SysTick->CTRL;																		//获取当前定时器状态
	}while((temp&0x01)&&!(temp&(1<<16)));											//判断使能为1  和CTRL最高位是否为1 如果为1 则计时结束
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;									//不使能定时器
	SysTick->VAL =0X00;   
}
void delay_ms(u32 nms)
{
	u32 temp;
	SysTick->LOAD=nms*fac_ms;
	SysTick->VAL=0x00;
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;
	do{
			temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;
	SysTick->VAL =0X00;   
}

	
