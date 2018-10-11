#include "Door.h"

void Init_Door()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(DOOR_CLK, ENABLE); 

												   
  	GPIO_InitStructure.GPIO_Pin = GPIO_PIN_DOOR;	

	
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

	 
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

  	GPIO_Init(DOOR_PORT, &GPIO_InitStructure);		  

	GPIO_SetBits(DOOR_PORT, GPIO_Pin_DOOR);	 
}

