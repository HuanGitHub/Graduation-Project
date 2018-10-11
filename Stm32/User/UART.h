#ifndef __UART_H
#define __UART_H
#include "Stm32f10x.h"
#include <stdio.h>
#include "Config.h"

#define DATA_SIZE	12
int fputc(int ch, FILE *f);
void UsartSend(uint8_t ch);
void send_Four_data(u16 Val);
void USART_init(void);

void send_Normal_data(void);



#endif
