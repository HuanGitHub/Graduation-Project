#ifndef __UI_H
#define __UI_H
#include "Stm32f10x.h"

void SYSTEM_RUN(void);				//系统正常运行主界面
void SYSTEM_SET(void);				//设置页面
void SET_TIME(void);				//设置定时页面
void SET_AL(void);					//设置智能页面
void SYSTEM_ERROR(u8 ERR);
	

#endif
