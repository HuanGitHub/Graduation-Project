#include "SysTick.h"
static u8  fac_us=0;							//us��ʱ������			   
static u16 fac_ms=0;							//ms��ʱ������

void SysTick_init(void)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);			//ѡ��ʱ����ʱ��
	fac_us=SystemCoreClock/8000000;														//ȷ����ʱ���� 9M/s �����Ҫ1ns����ʱ����9
	fac_ms=(u16)fac_us*1000;
}
void delay_us(u32 nus)
{
	u32 temp;
	SysTick->LOAD=nus*fac_us;																	//����Ҫ�Ķ�ʱʱ��װ��Ԥװ�ؼĴ�����
	SysTick->VAL=0x00;																				//����
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;										//ʹ�ܶ�ʱ�� ��ʼ����
	do{
			temp=SysTick->CTRL;																		//��ȡ��ǰ��ʱ��״̬
	}while((temp&0x01)&&!(temp&(1<<16)));											//�ж�ʹ��Ϊ1  ��CTRL���λ�Ƿ�Ϊ1 ���Ϊ1 ���ʱ����
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;									//��ʹ�ܶ�ʱ��
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

	
