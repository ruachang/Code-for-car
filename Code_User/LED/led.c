#include "led.h"


// ��ʼ��PA1��PA2
//-----------------------------------------------------------------------------------------
void LED_Init_JX(void)
{	
	GPIO_InitTypeDef  GPIO_InitStructure;					// ����GPIO_InitTypeDef�ͽṹ��

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	// ʹ��GPIOA�˿�ʱ��

	GPIO_InitStructure.GPIO_Pin   = GPIO_R_LED;				// LEDR--PA4
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP; 		// �������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;		// IO���ٶ�Ϊ10MHz
	GPIO_Init(LED_R_GPIO_PORT, &GPIO_InitStructure);					// 
	GPIO_SetBits(LED_R_GPIO_PORT,GPIO_R_LED);							//LEDRȡ��λ

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	// ʹ��GPIOB�˿�ʱ��
	
	GPIO_InitStructure.GPIO_Pin   = GPIO_B_LED/GPIO_G_LED;	// LEDB--PB0,LEDG--PB1
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP; 		// �������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;		// IO���ٶ�Ϊ10MHz
	GPIO_Init(LED_G_GPIO_PORT, &GPIO_InitStructure);					// 
	GPIO_SetBits(LED_G_GPIO_PORT,GPIO_B_LED/GPIO_G_LED);              //LEDB,LEDGȡ��λ
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