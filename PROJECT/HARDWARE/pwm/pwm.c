#include"pwm.h"


void PWM_GPIO_Init1(void )
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//��ʼTIM3 ��ʱ�� ��GPIOAʱ�� ��AFIOʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_AFIO ,ENABLE);  
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�������
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}

void PWM_GPIO_Init2(void )
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//��ʼTIM3 ��ʱ�� ��GPIOAʱ�� ��AFIOʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_AFIO ,ENABLE);  
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�������
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}

void PWM_GPIO_Init3(void )
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//��ʼTIM3 ��ʱ�� ��GPIOAʱ�� ��AFIOʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB| RCC_APB2Periph_AFIO ,ENABLE);  
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�������
	GPIO_Init(GPIOB,&GPIO_InitStructure);
}

void PWM_GPIO_Init4(void )
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//��ʼTIM3 ��ʱ�� ��GPIOAʱ�� ��AFIOʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB| RCC_APB2Periph_AFIO ,ENABLE);  
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�������
	GPIO_Init(GPIOB,&GPIO_InitStructure);
}
//TIM3_CH1  -->   PA6    ���ſ���
//TIM3_CH2  -->   PA7    ƫ������
//TIM3_CH3  -->   PB0    ��������3
//TIM3_CH4  -->   PB1    �������
void PWM_Init1(u16 a)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	 PWM_GPIO_Init1();
	 
	
	TIM_TimeBaseStructure.TIM_Period = 40000;  

	TIM_TimeBaseStructure.TIM_Prescaler = 35;//��ʱ����Ϊ20ms��(35+1)/72MHZ*40000=20ms;

	TIM_TimeBaseStructure.TIM_ClockDivision = 0;

	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);

	//����ͨ�� 1
	//����ΪPWMģʽ1����ͨռ�ձ�ģʽ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse= a;//ͨ�������ı�ռ�ձ���ֵ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	//ʹ��ͨ��1
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);	 
    TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);  


	TIM_ARRPreloadConfig(TIM3, ENABLE);			 // ʹ��TIM3���ؼĴ���ARR
    TIM_Cmd(TIM3, ENABLE);                   //ʹ�ܶ�ʱ��3
}
	
void PWM_Init2(u16 a)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	 PWM_GPIO_Init2();
	 
	
	TIM_TimeBaseStructure.TIM_Period = 40000;  

	TIM_TimeBaseStructure.TIM_Prescaler = 35;//��ʱ����Ϊ20ms

	TIM_TimeBaseStructure.TIM_ClockDivision = 0;

	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);

	//����ͨ�� 2
	//����ΪPWMģʽ1����ͨռ�ձ�ģʽ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse= a;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	//ʹ��ͨ��2
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);	 
    TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);  


	TIM_ARRPreloadConfig(TIM3, ENABLE);			 // ʹ��TIM3���ؼĴ���ARR
    TIM_Cmd(TIM3, ENABLE);                   //ʹ�ܶ�ʱ��3
}
void PWM_Init3(u16 a)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	 PWM_GPIO_Init3();
	 
	
	TIM_TimeBaseStructure.TIM_Period = 40000;  

	TIM_TimeBaseStructure.TIM_Prescaler = 35;//��ʱ����Ϊ20ms

	TIM_TimeBaseStructure.TIM_ClockDivision = 0;

	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);

	//����ͨ�� 3
	//����ΪPWMģʽ1����ͨռ�ձ�ģʽ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse= a;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	//ʹ��ͨ��3
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);	 
    TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);  


	TIM_ARRPreloadConfig(TIM3, ENABLE);			 // ʹ��TIM3���ؼĴ���ARR
    TIM_Cmd(TIM3, ENABLE);                   //ʹ�ܶ�ʱ��3
}
void PWM_Init4(u16 a)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	 PWM_GPIO_Init4();
	 
	
	TIM_TimeBaseStructure.TIM_Period = 40000;  

	TIM_TimeBaseStructure.TIM_Prescaler = 35;//��ʱ����Ϊ20ms

	TIM_TimeBaseStructure.TIM_ClockDivision = 0;

	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);

	//����ͨ�� 4
	//����ΪPWMģʽ1����ͨռ�ձ�ģʽ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse= a;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	//ʹ��ͨ��4
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);	 
    TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);  


	TIM_ARRPreloadConfig(TIM3, ENABLE);			 // ʹ��TIM3���ؼĴ���ARR
    TIM_Cmd(TIM3, ENABLE);                   //ʹ�ܶ�ʱ��3
}

