#include "elude.h"

u8 S_Elude_Input = 0 ;		// �����������ģ��ķ���ֵ


// ������ϳ�ʼ��(��PA1��PA2��PA3��ʼ��Ϊ��������)
// Elude_�� -- PA1
// Elude_�� -- PA2
// Elude_�� -- PA3
//----------------------------------------------------------------------------------------------
void Elude_Input_Init_JX(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);			// GPIOBʱ��ʹ��
	
	
	// ���ϣ�Elude--PA1��PA2��PA3
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;	// Elude--PA1��PA2��PA3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 					// ��������
	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;				// ����ģʽ����Ҫ��˿��ٶ�
	GPIO_Init(GPIOA, &GPIO_InitStructure);							// ��ʼ��PA1��PA2��PA3
	
}
//----------------------------------------------------------------------------------------------


// ������ϼ�⺯��
// S_Elude_Input�ĵ���λ�ֱ��Ӧ[PA3��PA2��PA1]��״ֵ̬
// δ�����ϰ�(δ���յ������)����Ӧ״̬ = 1
// �����ϰ�(���յ������)����Ӧ״̬ = 0
//-------------------------------------------------------------
void Elude_detect_barrier(void)
{
	S_Elude_Input = 0 ;
	
	S_Elude_Input = (((u8)GPIOA->IDR) & 0x0E)>>1;
}
//-------------------------------------------------------------

