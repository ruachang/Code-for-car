#include "key.h"

// ������ʼ��
//---------------------
void KEY_Init_JX(void)
{	
	GPIO_InitTypeDef  GPIO_InitStructure;				// ����GPIO_InitTypeDef�ͽṹ��
	
	// ʹ��GPIOA��GPIOC�˿�ʱ��
	// RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);
	
	
	#if KEY1_EN	
	//---------------------------------------------------------------------------------
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	// ʹ��GPIOAʱ��
	
	// ������KEY_1  ---- PA1 �˿�����
	GPIO_InitStructure.GPIO_Pin = GPIO_KEY1_Pin;				// WKUP <==> PA_in(1)
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 			// ��������
	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// ����ģʽ����Ҫ��˿��ٶ�
	GPIO_Init(GPIO_KEY1_PORT, &GPIO_InitStructure);					// �����趨������ʼ��PA0
	//---------------------------------------------------------------------------------
	#endif
	
	
	#if KEY2_EN	
	//---------------------------------------------------------------------------------
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	// ʹ��GPIOCʱ��
	
	// ������KEY_2  ---- PC13 �˿�����
	GPIO_InitStructure.GPIO_Pin = GPIO_KEY2_Pin;				// ������KEY_1  ---- PC13
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 			// ��������
	GPIO_Init(GPIO_KEY2_PORT, &GPIO_InitStructure);					// �����趨������ʼ��PC13
	//---------------------------------------------------------------------------------
	#endif
}
