#include "BH1750.h"
#include "myiic.h"
#include "SysTick.h"
void BH1750_Init(void)
{
	BH_Send_Data(BHPowOn);
	BH_Send_Data(BHReset);
	BH_Send_Data(BHModeH2);
}
void BH_Send_Data(u8 command)
{
    do{
    IIC_Start();
    IIC_Send_Byte(BHAddWrite);
	}while(IIC_Wait_Ack());
	IIC_Send_Byte(command);
	IIC_Wait_Ack();
	IIC_Stop();
}

u16 BH_Read_Data(void)
{
	u16 buf;
	IIC_Start();
	IIC_Send_Byte(BHAddRead);
	IIC_Wait_Ack();
	buf=IIC_Read_Byte(1);
	buf=buf<<8;
	buf+=0x00ff&IIC_Read_Byte(0);
	IIC_Stop();
	return buf;
}