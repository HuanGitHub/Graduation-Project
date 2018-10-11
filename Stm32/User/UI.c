#include "UI.h"
#include "oled.h"
//界面显示函数

void SYSTEM_RUN(void)
{
	OLED_ShowString(0,2,"  System Runing");

}
void SYSTEM_SET(void)
{

	OLED_ShowString(0,0,"  Mode Set");
	

	OLED_ShowString(0,2,"  System Set");
}

void SET_TIME(void)
{
	int i=0;
	OLED_ShowNum(0,0,i,1,1);
	OLED_ShowString(10,0,"Day/Time ");

}
void SET_AL(void)
{
	OLED_ShowString(10,0,"Place Get S_Hum");
	
}
void SYSTEM_ERROR(u8 ERR)
{
	
	OLED_ShowString(0,0,"ERROR_NUM:");
	OLED_ShowNum(100,0,ERR,2,16);

}

