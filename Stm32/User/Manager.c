#include "Manager.h"
uint8_t SendData[10];
SHOW_DATA get_Show_Data()
{	
	SHOW_DATA temp_Show_data;
//	DHT11_Data_TypeDef DHT11_Data;
	temp_Show_data.light_data = 0;
	temp_Show_data.PMdata = 0;
	temp_Show_data.Smoke = 0;
	Read_DHT11(&temp_Show_data.DHT11_Data);
	temp_Show_data.light_data = BH_Read_Data()/1.2;
	temp_Show_data.PMdata = GetGP2YAverageValue(5);
	temp_Show_data.Smoke = Get_MQ2_Average();
	Read_DHT11(&temp_Show_data.DHT11_Data);


	return temp_Show_data;
}

u8 Make_Send_Data(SHOW_DATA *Show_data)
{
	
	SendData[0] = 0x88;
	SendData[1] = Show_data->DHT11_Data.humi_int;
	SendData[2] = Show_data->DHT11_Data.humi_deci;
	SendData[3] = Show_data->DHT11_Data.temp_int;
	SendData[4] = Show_data->DHT11_Data.temp_deci;
	SendData[5] = Show_data->PMdata;
	SendData[6] = (Show_data->Smoke >> 8)& 0xff;
	SendData[7] = Show_data->Smoke & 0xff;
	SendData[8] = Show_data->light_data & 0x00ff;  //6d 14  0110 1110 0001 0100
	SendData[9] = (Show_data->light_data >> 8) & 0x00ff;
	SendData[10] = 0x0A;
	SendData[11] = 0x0d;
	//printf("%d,%d,%d,%d",Show_data->DHT11_Data.humi_int,Show_data->DHT11_Data.humi_deci,Show_data->DHT11_Data.temp_int,Show_data->DHT11_Data.temp_deci);
	return True;



}


