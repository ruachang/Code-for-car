#ifndef __ADC_H
#define __ADC_H

#include "stm32f10x.h"

void  Adc_Init(void);	
unsigned int Get_Adc_Average(unsigned char ch,unsigned char times);
unsigned int Get_Battery(void);
#endif	
