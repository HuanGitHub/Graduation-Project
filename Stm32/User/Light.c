#include "Light.h"

void Init_Light()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(LIGHT_CLK, ENABLE); 

	
  	GPIO_InitStructure.GPIO_Pin = GPIO_PIN_LIGHT;	

	
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

	
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

  	GPIO_Init(LIGHT_PORT, &GPIO_InitStructure);		  

	GPIO_SetBits(LIGHT_PORT, GPIO_Pin_LIGHT);	 
}
