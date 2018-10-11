#ifndef _SysTick
#define _SysTick
#include "stm32f10x.h"

void SysTick_init(void);

void delay_ms(u32 nms);
void delay_us(u32 nus);








#endif
