#include "UART.h"
#include <stdio.h>
#include <string.h>
extern SHOW_DATA Show_data;
extern u8 SendData[DATA_SIZE];

int fputc(int ch, FILE *f)
{
	USART_SendData(USART1, (uint8_t) ch);
	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
	return ch;
}
void UsartSend(uint8_t ch)
{
	USART_SendData(USART1, (uint8_t) ch);
	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
	{}
}

void send_Four_data(u16 Val)
{
	int i;
	u8 buff[32],sum;
	memset(buff,0,32);
	buff[0]=0x88;
	buff[1]=0xA1;
	buff[2]=0x1C;
	
	buff[3]=(Val>>8) &0xff;
	buff[4]=Val & 0xff;
	
	for(i=0;i<31;i++)
	{
			sum+=buff[i];
	}
	buff[31]=sum;
	
	for(i=0;i<32;i++)
		UsartSend(buff[i]);
	
}
void USART_init(void)
{

	GPIO_InitTypeDef GPIO_init;
	USART_InitTypeDef USART1_init;
	NVIC_InitTypeDef NVIC_InitStrue;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);				//使能GOIOA的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	GPIO_init.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_init.GPIO_Pin=GPIO_Pin_9;
	GPIO_init.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_init);
	
	GPIO_init.GPIO_Mode= GPIO_Mode_IN_FLOATING;
	GPIO_init.GPIO_Pin=GPIO_Pin_10;
	GPIO_init.GPIO_Speed= GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_init);
	
	NVIC_InitStrue.NVIC_IRQChannel=USART1_IRQn;
	NVIC_InitStrue.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStrue.NVIC_IRQChannelSubPriority=1;
		
	NVIC_Init(&NVIC_InitStrue);
		
	USART1_init.USART_BaudRate=115200;
	USART1_init.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART1_init.USART_Mode=USART_Mode_Tx | USART_Mode_Rx;
	USART1_init.USART_Parity=USART_Parity_No;
	USART1_init.USART_StopBits=USART_StopBits_1;
	USART1_init.USART_WordLength=USART_WordLength_8b;
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	USART_Init(USART1,&USART1_init);
	USART_Cmd(USART1,ENABLE);
}
void send_Normal_data()
{
	u8 i = 8;

	if(Make_Send_Data(&Show_data)){
		for(i=0;i<DATA_SIZE;i++){
			UsartSend(SendData[i]);
			//printf("%d",SendData[i]);
		}
	}
	

}


