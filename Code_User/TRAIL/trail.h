#ifndef	__TRAIL_H
#define __TRAIL_H

#include "stm32f10x.h"


// S_Trail_Input�ĵ���λ�ֱ��Ӧ[PB5��PB4��PB3]��״ֵ̬
// δ��������(���յ������)����Ӧ״̬ = 0
// ��������(δ���յ������)����Ӧ״̬ = 1
//-----------------------------------------------------
extern u8 S_Trail_Input ;		// ����Ѱ��ģ��ķ���ֵ
//-----------------------------------------------------


// ����Ѱ�����
//---------------------------------------------------------------------
#define		Not_Find_Black_Line				0x00	// δ���ֺ���
#define		Middle_Find_Black_Line			0x02	// �м䷢�ֺ���
#define		Left_Find_Black_Line			0x01	// ��෢�ֺ���
#define		Left_Middle_Find_Black_Line		0x03	// ���в෢�ֺ���
#define		Right_Find_Black_Line			0x04	// �Ҳ෢�ֺ���
#define		Right_Middle_Find_Black_Line	0x06	// ���в෢�ֺ���

#define		Left_Right_Find_Black_Line		0x05	// ���Ҳ෢�ֺ���

#define		All_Find_Black_Line				0x07	// ȫ�����ֺ���
//---------------------------------------------------------------------


void Trail_Input_Init_JX(void);		// ����Ѱ����ʼ��

void Trail_black_line(void);		// ����Ѱ������


#endif	/* __TRAIL_H*/

