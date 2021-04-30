#include "pwm.h"





// TIM1_PWM�����ʼ�� 
// TIM1_CH1 = PA8
// TIM1_CH2 = PA9
// TIM1_CH3 = PA10
// TIM1_CH4 = PA11

// TIM1_Reload_Num			= TIM1�Զ���װֵ
// TIM1_Frequency_Divide	= ʱ��Ԥ��Ƶ��
//-----------------------------------------------------------------------------------------------------------------
void TIM1_PWM_Init_JX(void)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);			// ʹ��TIM1ʱ��	
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  			// ʹ��GPIOBʱ��
			
    // ����IOģʽ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  				// �����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);							// ��ʼ��PA8��PA9��PA10��PA11
	
	
   //��ʼ��TIM1�ļ���ģʽ����Ƶֵ����װ��ֵ��
	TIM_TimeBaseStructure.TIM_Period = TIM1_Reload_Num; 			// ������һ�������¼���װ���Զ���װ�ؼĴ�����ֵ
	TIM_TimeBaseStructure.TIM_Prescaler =TIM1_Frequency_Divide; 	// ����TIM3ʱ��Ԥ��Ƶֵ 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 					// ����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	// ���ϼ���ģʽ
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); 				// ���ݲ�����ʼ��TIM1
	
	//��ʼ��TIM1_CH1-4��PWM
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 				// ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	// �Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputState_Disable;	// �Ƚ����N��ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0;								
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 		// �������:TIM����Ƚϼ��Ը�
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCPolarity_High;		
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset ;
	
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);  						// ����ʼ��TIM1_OC1	
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);						// ����ʼ��TIM1_OC2
	TIM_OC3Init(TIM1, &TIM_OCInitStructure);						// ����ʼ��TIM1_OC3
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);						// ����ʼ��TIM1_OC4
	
	
	TIM_ARRPreloadConfig(TIM1,ENABLE);								// ʹ��TIM1���Զ���װ�ؼĴ���
	
	TIM_CtrlPWMOutputs(TIM1,ENABLE);								// �����ʹ��
	
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);  				// ʹ��TIM1��OC1�ϵ�Ԥװ�ؼĴ���
	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);				// ʹ��TIM1��OC2�ϵ�Ԥװ�ؼĴ���
	TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);				// ʹ��TIM1��OC3�ϵ�Ԥװ�ؼĴ���
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);				// ʹ��TIM1��OC4�ϵ�Ԥװ�ؼĴ���
	
	TIM_Cmd(TIM1, ENABLE);  										// ʹ��TIM1
	
}
//-----------------------------------------------------------------------------------------------------------------


// TIM4_PWM�����ʼ�� 
// TIM4_CH1 = PB6
// TIM4_CH2 = PB7
// TIM4_CH3 = PB8
// TIM4_CH4 = PB9

// TIM4_Reload_Num			= TIM1�Զ���װֵ
// TIM4_Frequency_Divide	= ʱ��Ԥ��Ƶ��
//-----------------------------------------------------------------------------------------------------------------
void TIM4_PWM_Init_JX(void)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);			// ʹ��TIM4ʱ��
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  			// ʹ��GPIOBʱ��
	
	// ����IOģʽ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  				// �����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);							
 
	
	//��ʼ��TIM4�ļ���ģʽ����Ƶֵ����װ��ֵ��
	TIM_TimeBaseStructure.TIM_Period = TIM4_Reload_Num; 			// ������һ�������¼���װ���Զ���װ�ؼĴ�����ֵ
	TIM_TimeBaseStructure.TIM_Prescaler =TIM4_Frequency_Divide; 	// ����TIM4ʱ��Ԥ��Ƶֵ 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 					// ����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	// ���ϼ���ģʽ
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); 				// ���ݲ�����ʼ��TIM4�ļ�����ʽ
	
	
	//��ʼ��TIM4_CH1-4��PWM
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 				// ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	// �Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 		// �������:TIM����Ƚϼ��Ը�
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  						
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);
	

	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);  				// ʹ��TIM4��OC1�ϵ�Ԥװ�ؼĴ���
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);				// ʹ��TIM4��OC2�ϵ�Ԥװ�ؼĴ���
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);				// ʹ��TIM4��OC3�ϵ�Ԥװ�ؼĴ���
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);				// ʹ��TIM4��OC4�ϵ�Ԥװ�ؼĴ���
 
	TIM_Cmd(TIM4, ENABLE);											// ʹ��TIM4
}
//-----------------------------------------------------------------------------------------------------------------


