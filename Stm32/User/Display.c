#include "Display.h"
#include "Manager.h"
DISP_PAGE PAGE;
char Clear_Oled = 0;
extern SHOW_DATA Show_data;
void Disp_Init()
{
	PAGE = PAGE_FIRST;

}
void SHOW_PAGE(DISP_PAGE page)
{
	switch(page){
		case	PAGE_FIRST:	
				Display_FIRST_page();
				break;
		case	PAGE_SECOND:
				Display_SECOND_page();
				break;
		case	PAGE_THIRD:
			
				break;	
		default:
				Display_Welcome_page();
	};
}
void Display_FIRST_page()
{
	if(Clear_Oled == 0){
		Clear_Oled = 1;
		OLED_Clear();
	}
		OLED_ShowString(0,0,"YanWu:");
		OLED_ShowString(0,2,"Guang:");
		OLED_ShowString(0,4,"WenDu:");
		OLED_ShowString(0,6,"ShiDu:");

		OLED_ShowNum(60,0,Show_data.Smoke,4,16);
		OLED_ShowNum(60,2,Show_data.light_data,4,16);
		OLED_ShowNum(60,4,Show_data.DHT11_Data.temp_int,2,16);OLED_ShowString(76,4,"C");	
		OLED_ShowNum(60,6,Show_data.DHT11_Data.humi_int,2,16); 

}
void Display_SECOND_page()
{
	if(Clear_Oled == 0){
		Clear_Oled = 1;
		OLED_Clear();
	}
	
	OLED_ShowString(0,0,"PMdata:");
	OLED_ShowNum(60,0,Show_data.PMdata,4,16);

}
void Display_THIRD_page()
{
	if(Clear_Oled == 0){
		Clear_Oled = 1;
		OLED_Clear();
	}
}
void Display_Welcome_page()
{
	if(Clear_Oled == 0){
		Clear_Oled = 1;
		OLED_Clear();
	}
	

}
