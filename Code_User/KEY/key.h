#ifndef __KEY_H
#define __KEY_H


#include "stm32f10x.h"
#include "bit_band.h"
#include "delay.h"

// 定义为1表示使能该按键，定义为0表示失能该按键
//------------------------------------------
#define 	KEY1_EN		    1		// 使能
#define 	KEY2_EN		    1		// 使能
//------------------------------------------

// 按键宏定义
//-----------------------------------------------------
#define 	KEY1_in		    PA_in(0)	// KEY1 <==> PA_in(0)
#define 	KEY2_in		    PC_in(13)	// KEY2 <==> PC_in(13)
#define     GPIO_KEY1_Pin   GPIO_Pin_0
#define     GPIO_KEY1_PORT  GPIOA
#define     GPIO_KEY2_Pin   GPIO_Pin_13
#define     GPIO_KEY2_PORT  GPIOC

void KEY_Init_JX(void) ;


#endif	/* __KEY_H */
