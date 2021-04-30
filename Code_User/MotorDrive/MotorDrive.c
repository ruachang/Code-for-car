#include "MotorDrive.h"

// ��ǰ��
//**************************************
// ��ǰ��=ǰת(�ٶ� = speed%)
//------------------------------------
void Motor_LF_forward(u8 speed)
{
	PA9_Out_PP;
	PA_out(9) = 0;

	PA8_AF_PP;
	TIM_SetCompare1(TIM1, speed);
}
//------------------------------------

// ��ǰ��=��ת(�ٶ� = -speed%)
//------------------------------------
void Motor_LF_backward(u8 speed)
{
	PA8_Out_PP;
	PA_out(8) = 0;

	PA9_AF_PP;
	TIM_SetCompare2(TIM1, speed);
}
//------------------------------------


// ��ǰ��=ֹͣ(Ϩ��/ɲ��)
// Wheel_STOP = 0��Ϩ��	1��ɲ��
//------------------------------------
void Motor_LF_Stop(u8 Wheel_STOP)
{
	if( Wheel_STOP == 0 )	// Ϩ��
	{
		PA8_Out_PP;
		PA_out(8) = 0;
	
		PA9_Out_PP;
		PA_out(9) = 0;
	}
	
	else//if(Wheel_STOP==1)	// ɲ��
	{
		PA8_Out_PP;
		PA_out(8) = 1;
	
		PA9_Out_PP;
		PA_out(9) = 1;
	}
}
//------------------------------------
//**************************************


// �����
//**************************************
// �����=ǰת(�ٶ� = speed%)
//----------------------------------
void Motor_LB_forward(u8 speed)
{
	PA11_Out_PP;
	PA_out(11) = 0;
	
	PA10_AF_PP;
	TIM_SetCompare3(TIM1, speed);
}
//----------------------------------

// �����=��ת(�ٶ� = -speed%)
//----------------------------------
void Motor_LB_backward(u8 speed)
{
	PA10_Out_PP;
	PA_out(10) = 0;
	
	PA11_AF_PP;
	TIM_SetCompare4(TIM1, speed);
}
//----------------------------------


// �����=ֹͣ(Ϩ��/ɲ��)
// Wheel_STOP = 0��Ϩ��	1��ɲ��
//----------------------------------
void Motor_LB_Stop(u8 Wheel_STOP)
{
	if( Wheel_STOP == 0 )	// Ϩ��
	{
		PA10_Out_PP;
		PA_out(10) = 0;
	
		PA11_Out_PP;
		PA_out(11) = 0;
	}
	
	else//if(Wheel_STOP==1)	// ɲ��
	{
		PA10_Out_PP;
		PA_out(10) = 1;
	
		PA11_Out_PP;
		PA_out(11) = 1;
	}
}
//----------------------------------
//**************************************


// ��ǰ��
//**************************************
// ��ǰ��=ǰת(�ٶ� = speed%)
//----------------------------------
void Motor_RF_forward(u8 speed)
{
	PB7_Out_PP;
	PB_out(7) = 0;
	
	PB6_AF_PP;
	TIM_SetCompare1(TIM4, speed);
	
}
//----------------------------------

// ��ǰ��=��ת(�ٶ� = -speed%)
//----------------------------------
void Motor_RF_backward(u8 speed)
{
	PB6_Out_PP;
	PB_out(6) = 0;
	
	PB7_AF_PP;
	TIM_SetCompare2(TIM4, speed);
	
}
//----------------------------------


// ��ǰ��=ֹͣ(Ϩ��/ɲ��)
// Wheel_STOP = 0��Ϩ��	1��ɲ��
//----------------------------------
void Motor_RF_Stop(u8 Wheel_STOP)
{
	if( Wheel_STOP == 0 )	// Ϩ��
	{
		PB6_Out_PP;
		PB_out(6) = 0;
	
		PB7_Out_PP;
		PB_out(7) = 0;
	}
	
	else//if(Wheel_STOP==1)	// ɲ��
	{
		PB6_Out_PP;
		PB_out(6) = 1;
	
		PB7_Out_PP;
		PB_out(7) = 1;
	}
}
//----------------------------------
//**************************************



// �Һ���
//**************************************
// �Һ���=ǰת(�ٶ� = speed%)
//----------------------------------
void Motor_RB_forward(u8 speed)
{
	PB9_Out_PP;
	PB_out(9) = 0;
	
	PB8_AF_PP;
	TIM_SetCompare3(TIM4, speed);
	
}
//----------------------------------

// �Һ���=��ת(�ٶ� = -speed%)
//----------------------------------
void Motor_RB_backward(u8 speed)
{
	PB8_Out_PP;
	PB_out(8) = 0;
	
	PB9_AF_PP;
	TIM_SetCompare4(TIM4, speed);
	
}
//----------------------------------


// ��ǰ��=ֹͣ(Ϩ��/ɲ��)
// Wheel_STOP = 0��Ϩ��	1��ɲ��
//----------------------------------
void Motor_RB_Stop(u8 Wheel_STOP)
{
	if( Wheel_STOP == 0 )	// Ϩ��
	{
		PB8_Out_PP;
		PB_out(8) = 0;
	
		PB9_Out_PP;
		PB_out(9) = 0;
	}
	
	else//if(Wheel_STOP==1)	// ɲ��
	{
		PB8_Out_PP;
		PB_out(8) = 1;
	
		PB9_Out_PP;
		PB_out(9) = 1;
	}
}
//----------------------------------
//**************************************




// С���˶����
//**************************************
// С��=ֹͣ(Ϩ��/ɲ��)
// Wheel_STOP = 0��Ϩ��	1��ɲ��
//---------------------------------
void Car_Stop(u8 Wheel_STOP)
{
	if( Wheel_STOP == 0 )	// Ϩ��
	{
		Motor_LF_Stop(0);
		Motor_LB_Stop(0);
		Motor_RF_Stop(0);
		Motor_RB_Stop(0);
	}
	
	else//if(Wheel_STOP==1)	// ɲ��
	{
		Motor_LF_Stop(1);
		Motor_LB_Stop(1);
		Motor_RF_Stop(1);
		Motor_RB_Stop(1);
	}
}
//---------------------------------


// С����ǰ(�ٶ� = speed%)
//---------------------------------
void Car_forward(u8 speed)
{
	Motor_LF_forward(speed);
	Motor_LB_forward(speed);
			
	Motor_RF_forward(speed);
	Motor_RB_forward(speed);
}
//---------------------------------


// С�����(�ٶ� = -speed%)
//---------------------------------
void Car_backward(u8 speed)
{
	Motor_LF_backward(speed);
	Motor_LB_backward(speed);
					
	Motor_RF_backward(speed);
	Motor_RB_backward(speed);
}
//---------------------------------



// С����ת
// ��೵�����ת(�ٶ� = -speed%)
// �Ҳ೵����ǰת(�ٶ� = speed%)
//---------------------------------
void Car_Turn_Left(u8 speed)
{
	Motor_LF_backward(speed);
	Motor_LB_backward(speed);
			
	Motor_RF_forward(speed);
	Motor_RB_forward(speed);
}
//---------------------------------


// С����ת
// �Ҳ೵�����ת(�ٶ� = -speed%)
// ��೵����ǰת(�ٶ� = speed%)
//---------------------------------
void Car_Turn_Right(u8 speed)
{
	Motor_LF_forward(speed);
	Motor_LB_forward(speed);
			
	Motor_RF_backward(speed);
	Motor_RB_backward(speed);
}
//---------------------------------

