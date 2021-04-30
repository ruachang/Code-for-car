#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"


// 宏定义
//--------------------------------------------------
#define LED_Green	PB_out(0)	// LED1(LED_GREEN)
#define LED_Blue	PB_out(1)	// LED2(LED_BLUE)
#define LED_Red 	PA_out(4)	// LED2(LED_RED)
#define LED_B_GPIO_PORT        GPIOB
#define LED_G_GPIO_PORT        GPIOB
#define LED_R_GPIO_PORT        GPIOA
#define GPIO_B_LED             GPIO_Pin_1 // LED_BLUE->PB1
#define GPIO_R_LED             GPIO_Pin_4 // LED_RED->PA4
#define GPIO_G_LED             GPIO_Pin_0 // LED_GREEN->PB0 
#define GPIO_BEEP_PORT         GPIOA
#define GPIO_BEEP_Pin          GPIO_Pin_3 // BEEP->PA3

// 初始化PA1、PA2
//--------------------------------------------------
void LED_Init_JX(void);		// PA1、PA2设为推挽输出高
void BEEP_Init(void);
void BEEP_Control(unsigned char x);


#endif	/* __LED_H */
