#ifndef __CONFIG_H
#define __CONFIG_H
#include "stm32f10x.h"
#include "stdio.h"
#include "SysTick.h"
#include "adc.h"
#include "oled.h"
#include "flash.h"
#include "UART.h"
#include "UI.h"
#include "BELL.h"
#include "MQ-2.h"
#include "DHT11.h"
#include "myiic.h"
#include "BH1750.h"
#include "TIME.h"
#include "GP2Y.h"
#include "Exinterrupt.h"
#include "Display.h"
#include "Manager.h"
#define	set_flg(n)	n=1
#define	rset_flg(n)	n=0
#define MQ2_VALUE 2000
//char BELL_WARNING = 0;
void System_init(void);
#define SAVEINFO	0x800F000	//信息保存Flash地址

#define True	1
#define Flase	0
typedef	char	Flag_Bit;
#endif
