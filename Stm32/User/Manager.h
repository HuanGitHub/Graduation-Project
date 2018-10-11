#ifndef __MANAGER_H
#define __MANAGER_H
#include "DHT11.h"
#include "Config.h"

typedef struct{
	uint16_t	light_data;
	DHT11_Data_TypeDef DHT11_Data;
	uint16_t		Smoke;
	uint16_t		PMdata;
	
}SHOW_DATA;

SHOW_DATA get_Show_Data(void);
u8  Make_Send_Data(SHOW_DATA *Show_data);






#endif
