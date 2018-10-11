
#ifndef _OLED_SPI_H
#define _OLED_SPI_H
#include "stm32f10x.h"
#define     OLED_DC_H                       GPIO_SetBits(GPIOA, GPIO_Pin_11)
#define	    OLED_DC_L                       GPIO_ResetBits(GPIOA, GPIO_Pin_11)
#define     OLED_RST_L                      GPIO_ResetBits(GPIOA, GPIO_Pin_12)
#define     OLED_RST_H                      GPIO_SetBits(GPIOA, GPIO_Pin_12)
#define     X_WIDTH         128
#define     Y_WIDTH         64
#define			Page						8
#define     RCC_APB2Periph_OLED_PORT        RCC_APB2Periph_GPIOA
#define     OLED_PORT                       GPIOA
#define     OLED_RST_PIN                    GPIO_Pin_12
#define  		OLED_SCK_PIN										GPIO_Pin_5
#define			OLED_SDA_PIN										GPIO_Pin_7
#define     OLED_DC_PIN                     GPIO_Pin_11

void LCD_Init(void);
void LCD_CLS(void);
void LCD_Fill(unsigned char bmp_dat);
void LCD_Set_Pos(unsigned char x, unsigned char y);
void LCD_WrCmd(unsigned char cmd);
void LCD_WrDat(unsigned char dat);
void OLED_ShowChar(int x, int y, const unsigned char *p);

void OLED_ShowChinese(int x, int y, const unsigned char *p);

void OLED_ShowInt(int x, int y,int z);

#endif
