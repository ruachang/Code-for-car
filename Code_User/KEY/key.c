#include "key.h"

// 按键初始化
//---------------------
void KEY_Init_JX(void)
{	
	GPIO_InitTypeDef  GPIO_InitStructure;				// 定义GPIO_InitTypeDef型结构体
	
	// 使能GPIOA、GPIOC端口时钟
	// RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);
	
	
	#if KEY1_EN	
	//---------------------------------------------------------------------------------
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	// 使能GPIOA时钟
	
	// 按键：KEY_1  ---- PA1 端口配置
	GPIO_InitStructure.GPIO_Pin = GPIO_KEY1_Pin;				// WKUP <==> PA_in(1)
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 			// 下拉输入
	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// 输入模式不需要设端口速度
	GPIO_Init(GPIO_KEY1_PORT, &GPIO_InitStructure);					// 根据设定参数初始化PA0
	//---------------------------------------------------------------------------------
	#endif
	
	
	#if KEY2_EN	
	//---------------------------------------------------------------------------------
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	// 使能GPIOC时钟
	
	// 按键：KEY_2  ---- PC13 端口配置
	GPIO_InitStructure.GPIO_Pin = GPIO_KEY2_Pin;				// 按键：KEY_1  ---- PC13
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 			// 上拉输入
	GPIO_Init(GPIO_KEY2_PORT, &GPIO_InitStructure);					// 根据设定参数初始化PC13
	//---------------------------------------------------------------------------------
	#endif
}
