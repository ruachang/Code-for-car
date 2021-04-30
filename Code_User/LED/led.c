#include "led.h"


// 初始化PA1、PA2
//-----------------------------------------------------------------------------------------
void LED_Init_JX(void)
{	
	GPIO_InitTypeDef  GPIO_InitStructure;					// 定义GPIO_InitTypeDef型结构体

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	// 使能GPIOA端口时钟

	GPIO_InitStructure.GPIO_Pin   = GPIO_R_LED;				// LEDR--PA4
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP; 		// 推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;		// IO口速度为10MHz
	GPIO_Init(LED_R_GPIO_PORT, &GPIO_InitStructure);					// 
	GPIO_SetBits(LED_R_GPIO_PORT,GPIO_R_LED);							//LEDR取高位

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	// 使能GPIOB端口时钟
	
	GPIO_InitStructure.GPIO_Pin   = GPIO_B_LED/GPIO_G_LED;	// LEDB--PB0,LEDG--PB1
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP; 		// 推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;		// IO口速度为10MHz
	GPIO_Init(LED_G_GPIO_PORT, &GPIO_InitStructure);					// 
	GPIO_SetBits(LED_G_GPIO_PORT,GPIO_B_LED/GPIO_G_LED);              //LEDB,LEDG取高位
}
//-----------------------------------------------------------------------------------------

void BEEP_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitStructure.GPIO_Pin    = GPIO_BEEP_Pin;
	GPIO_InitStructure.GPIO_Mode   = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_10MHz;
	GPIO_Init(GPIO_BEEP_PORT, &GPIO_InitStructure);
	GPIO_ResetBits(GPIO_BEEP_PORT,GPIO_BEEP_Pin);
}

void BEEP_Control(unsigned char x)
{
	if(x == 0)
	{
		GPIO_ResetBits(GPIO_BEEP_PORT,GPIO_BEEP_Pin);	
	}
	if(x == 1)
	{
		GPIO_SetBits(GPIO_BEEP_PORT,GPIO_BEEP_Pin);	
	}

}