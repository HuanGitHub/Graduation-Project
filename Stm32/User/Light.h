#ifndef __LIGHT_H
#define __LIGHT_H

#define LIGHT_CLK     RCC_APB2Periph_GPIOA

#define LIGHT_PORT		GPIOA 
#define GPIO_Pin_LIGHT		


#define LIGHT_DATA_OUT(a)	if (a)	\
							GPIO_SetBits(LIGHT_PORT,GPIO_Pin_LIGHT);\
							else		\
							GPIO_ResetBits(LIGHT_PORT,GPIO_Pin_LIGHT)


#endif

