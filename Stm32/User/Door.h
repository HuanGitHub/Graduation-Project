#ifndef __DOOR_H
#define __DOOR_H
#define DOOR_CLK     RCC_APB2Periph_GPIOA
               
#define DOOR_PORT		GPIOA 
#define GPIO_Pin_DOOR		


#define DOOR_DATA_OUT(a)	if (a)	\
							GPIO_SetBits(DOOR_PORT,GPIO_Pin_DOOR);\
							else		\
							GPIO_ResetBits(DOOR_PORT,GPIO_Pin_DOOR)



#endif

