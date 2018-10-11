#include "GP2Y.h"
#include "adc.h"
#include "Config.h"
void GP2Y_ADC_init()  
{  
        GPIO_InitTypeDef GPIO_InitStructure;  
 
      
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//模拟输入引脚
		GPIO_Init(GPIOB, &GPIO_InitStructure);	
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//模拟输入引脚
		GPIO_Init(GPIOB, &GPIO_InitStructure);	
	
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);  
    
        GPIO_SetBits(GPIOB, GPIO_Pin_0);//?1  
}

u16 GetGP2YAverageValue(u8 times)  
{  
    u32 temp_val=0;  
    u8 t;  
    for(t=0;t<times;t++)  
    {  
        temp_val+=GetGP2YSingleValue();  
    }  
    return temp_val/times;  
}  
  
u16 GetGP2YSingleValue(void)  
{  
        int samplingTime = 280;
//        int deltaTime = 40;
      
        uint16_t ADCVal;  
        float dustVal = 0;  
        float Voltage;  
      
        GPIO_ResetBits(GPIOB, GPIO_Pin_0);//?1  ????LED  ????????  
        delay_us(samplingTime);                     // ??LED??280us?????  

		ADCVal=Get_Adc_Average(ADC_Channel_9,5);	
      
        delay_us(40);  
        GPIO_SetBits(GPIOB, GPIO_Pin_0);//?0  
        delay_us(9680);//?????0.32ms/10ms?PWM?????????LED  
        Voltage = ADCVal * 3.3 / 4096;  
        dustVal = (Voltage + 1) * 1000 / 10;//*1000?????????ug/m3  
        return dustVal;  
}  
