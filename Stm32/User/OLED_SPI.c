#include "OLED_SPI.h"

void SPI_Configuration(void)
{
	  SPI_InitTypeDef  SPI_InitStructure;
	  GPIO_InitTypeDef GPIO_InitStructure;
	  RCC_APB2PeriphClockCmd( RCC_APB2Periph_SPI1 | RCC_APB2Periph_OLED_PORT, ENABLE);

	  SPI_SSOutputCmd(SPI1, ENABLE);

	  GPIO_InitStructure.GPIO_Pin = OLED_SCK_PIN | OLED_SDA_PIN ;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_Init(OLED_PORT, &GPIO_InitStructure);


	  GPIO_InitStructure.GPIO_Pin = OLED_RST_PIN | OLED_DC_PIN | GPIO_Pin_4 ;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_Init(OLED_PORT, &GPIO_InitStructure);

	
	  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
	  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
	  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;
	  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	  SPI_InitStructure.SPI_CRCPolynomial = 7;
	  SPI_Init(SPI1, &SPI_InitStructure);
	  /* Enable SPI1 */
	  SPI_Cmd(SPI1, ENABLE);
}
void OLED_WB(uint8_t data)
{
 
    while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);

    SPI_I2S_SendData(SPI1, data);
}
void LCD_WrDat(unsigned char dat)
{
    OLED_DC_H;
	OLED_WB(dat);
}

void LCD_WrCmd(unsigned char cmd)
{
    OLED_DC_L;
    OLED_WB(cmd);
}

void LCD_Set_Pos(unsigned char x, unsigned char y)
{

	LCD_WrCmd((0xb0+(y&0x0f)));  
    LCD_WrCmd((((x & 0xf0)>>4)|0x10));			//设置OLED水平坐标的高4位
    LCD_WrCmd((x & 0x00));   								//设置OLED水平坐标的低4位
}
void OLED_ShowChar(int x, int y, const unsigned char *p)			//显示字符
 {
   int i = 0;
	LCD_Set_Pos(x, y);													//首先确定开始的坐标
  for(i = 0; i < 16; i+=2)										//
   {
      LCD_WrDat(p[i]);												//每次显示一个字节		每个char占用16个x像素
    }
   
   LCD_Set_Pos(x, y+1);												//转到下一页显示剩下字节
    for(i = 1; i < 16; i+=2)
    {
        LCD_WrDat(p[i]);
     }
}

void OLED_ShowChinese(int x, int y, const unsigned char *p)
 {
    int i = 0;
    LCD_Set_Pos(x, y);
    for(i = 0; i < 32; i+=2)
    {
         LCD_WrDat(p[i]);
     }
	LCD_Set_Pos(x, y+1);
     for(i = 1; i < 32; i+=2)
    {
         LCD_WrDat(p[i]);
     }

 }
void LCD_DLY_ms(unsigned int ms)
{
    unsigned int a;
    while(ms)
    {
        a=1335;
        while(a--);
        ms--;
    }
    return;
}
void LCD_Fill(unsigned char bmp_dat)
{
	unsigned char y,x;

    LCD_WrCmd(0x20);//-Set Page Addressing Mode (0x00/0x01/0x02)
    LCD_WrCmd(0x00);//

	LCD_WrCmd(0x21);//-Set Column Address
	LCD_WrCmd(0x00);
	LCD_WrCmd(0x7f);

	LCD_WrCmd(0x22);//-Set Page Address
	LCD_WrCmd(0x00);
	LCD_WrCmd(0x07);

	LCD_DLY_ms(1);
    for(y=0;y<Page;y++)
    {
    	for(x=0;x<X_WIDTH;x++)
    	{
    		LCD_WrDat(bmp_dat);
    	}
    }
}

/*********************清屏函数***********************/
void LCD_CLS(void)
{
	unsigned char y,x;
	for(y=0;y<8;y++)
	{
		LCD_WrCmd(0xb0+y);
		LCD_WrCmd(0x01);
		LCD_WrCmd(0x10);
		for(x=0;x<X_WIDTH;x++)
		LCD_WrDat(0);
		LCD_DLY_ms(200);
	}
}

void LCD_Init(void)
{
		SPI_Configuration();
		OLED_RST_L;
		LCD_DLY_ms(50);
		OLED_RST_H;
	//从上电到下面开始初始化要有足够的时间，即等待RC复位完毕

    LCD_WrCmd(0xae);//--turn off oled panel

    LCD_WrCmd(0xa8);//--set multiplex ratio(1 to 64)
    LCD_WrCmd(0x3f);//--1/64 duty
    LCD_WrCmd(0xd3);//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
    LCD_WrCmd(0x00);//-not offset
    LCD_WrCmd(0x40);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
    LCD_WrCmd(0xa0);//--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
    LCD_WrCmd(0xc0);//Set COM/Row Scan Direction   0xc0上下反置 0xc8正常
    LCD_WrCmd(0xda);//--set com pins hardware configuration
    LCD_WrCmd(0x12);
    LCD_WrCmd(0x81);//--set contrast control register
    LCD_WrCmd(0xcf); // Set SEG Output Current Brightness
    LCD_WrCmd(0xa4);// Disable Entire Display On (0xa4/0xa5)
    LCD_WrCmd(0xa6);// Disable Inverse Display On (0xa6/a7)
    LCD_WrCmd(0xd5);//--set display clock divide ratio/oscillator frequency
    LCD_WrCmd(0x80);//--set divide ratio, Set Clock as 100 Frames/Sec
    LCD_WrCmd(0x8d);//--set Charge Pump enable/disable
    LCD_WrCmd(0x14);//--set(0x10) disable
    LCD_WrCmd(0xaf);//--turn on oled panel

    LCD_WrCmd(0xd9);//--set pre-charge period
    LCD_WrCmd(0xf8);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock

    LCD_WrCmd(0xdb);//--set vcomh
    LCD_WrCmd(0x40);//Set VCOM Deselect Level
		
    LCD_Fill(0x00);  //初始清屏
}
