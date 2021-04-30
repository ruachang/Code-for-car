#ifndef __KEY_H
#define __KEY_H


#include "stm32f10x.h"
#include "bit_band.h"
#include "delay.h"

// ����Ϊ1��ʾʹ�ܸð���������Ϊ0��ʾʧ�ܸð���
//------------------------------------------
#define 	KEY1_EN		    1		// ʹ��
#define 	KEY2_EN		    1		// ʹ��
//------------------------------------------

// �����궨��
//-----------------------------------------------------
#define 	KEY1_in		    PA_in(0)	// KEY1 <==> PA_in(0)
#define 	KEY2_in		    PC_in(13)	// KEY2 <==> PC_in(13)
#define     GPIO_KEY1_Pin   GPIO_Pin_0
#define     GPIO_KEY1_PORT  GPIOA
#define     GPIO_KEY2_Pin   GPIO_Pin_13
#define     GPIO_KEY2_PORT  GPIOC

void KEY_Init_JX(void) ;


#endif	/* __KEY_H */
