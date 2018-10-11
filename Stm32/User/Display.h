#ifndef __DISPLAY_H
#define __DISPLAY_H
typedef enum 
{
	PAGE_FIRST = 1,
	PAGE_SECOND,
	PAGE_THIRD

}DISP_PAGE;

void SHOW_PAGE(DISP_PAGE page);
void Display_FIRST_page(void);
void Display_SECOND_page(void);
void Display_THIRD_page(void);
void Display_Welcome_page(void);
void Disp_Init(void);


#endif

