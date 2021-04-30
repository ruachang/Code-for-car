#ifndef	__ELUDE_H
#define __ELUDE_H

#include "stm32f10x.h"


// S_Elude_Infrared_Input�ĵ���λ�ֱ��Ӧ[PA3��PA2��PA1]��״ֵ̬
// δ�����ϰ�(δ���յ������)����Ӧ״̬ = 1
// �����ϰ�(���յ������)����Ӧ״̬ = 0
//--------------------------------------------------------------
extern u8 S_Elude_Input ;		// ����Ѱ��ģ��ķ���ֵ
//--------------------------------------------------------------


// ����������
//-----------------------------------------------------------------
#define		Not_Find_Barrier			0x07	// δ�����ϰ�
#define		Middle_Find_Barrier			0x05	// �м䷢���ϰ�
#define		Left_Find_Barrier			0x06	// ��߷����ϰ�
#define		Left_Middle_Find_Barrier	0x04	// ���в෢���ϰ�
#define		Right_Find_Barrier			0x03	// �ұ߷����ϰ�
#define		Right_Middle_Find_Barrier	0x01	// ���в෢���ϰ�

#define		Left_Right_Find_Barrier		0x05	// ���Ҳⷢ���ϰ�

#define		All_Find_Barrier			0x00	// ȫ�������ϰ�
//-----------------------------------------------------------------


void Elude_Input_Init_JX(void);		// ������ϳ�ʼ��

void Elude_detect_barrier(void);	// ������ϼ�⺯��


#endif	/* __ELUDE_H*/

