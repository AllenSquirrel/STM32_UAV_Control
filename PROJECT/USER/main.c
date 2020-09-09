
#include "stm32f10x.h"
#include"pwm.h"
#include"key.h"

void gpio_key(void);
void delay(void);
void delay1(void);
int check_key(void);
void PWM_GPIO_Init1(void);
void PWM_GPIO_Init2(void);
void PWM_GPIO_Init3(void);
void PWM_GPIO_Init4(void);

void PWM_Init1(u16 a);
void PWM_Init2(u16 a);
void PWM_Init3(u16 a);
void PWM_Init4(u16 a);


//      //���� throttle
//			 PWM_Init1(2200);break;//5.5%
//			 PWM_Init1(2400);break;//6%
//			 PWM_Init1(2600);break;//6.5%
//			 PWM_Init1(2800);break;//7%
//			 PWM_Init1(3000);break;//7.5%����
//			 PWM_Init1(3200);break;//8%
//			 PWM_Init1(3400);break;//8.5%
//			 PWM_Init1(3600);break;//9%
//			 PWM_Init1(3800);break;//9.5%
//			
//			//ƫ�� yaw
//			 PWM_Init2(2200);break;//5.5%
//			 PWM_Init2(2400);break;//6%
//			 PWM_Init2(2600);break;//6.5%
//			 PWM_Init2(2800);break;//7%
//			 PWM_Init2(3000);break;//7.5%����
//			 PWM_Init2(3200);break;//8%
//			 PWM_Init2(3400);break;//8.5%
//			 PWM_Init2(3600);break;//9%
//			 PWM_Init2(3800);break;//9.5%
//			
//			//���� pitch
//			 PWM_Init3(2200);break;//5.5%
//			 PWM_Init3(2400);break;//6%
//			 PWM_Init3(2600);break;//6.5%
//			 PWM_Init3(2800);break;//7%
//			 PWM_Init3(3000);break;//7.5%����
//			 PWM_Init3(3200);break;//8%
//			 PWM_Init3(3400);break;//8.5%
//			 PWM_Init3(3600);break;//9%
//			 PWM_Init3(3800);break;//9.5%
//			
//			
//			//��� row
//			 PWM_Init4(2200);break;//5.5%
//			 PWM_Init4(2400);break;//6%
//			 PWM_Init4(2600);break;//6.5%
//			 PWM_Init4(2800);break;//7%
//			 PWM_Init4(3000);break;//7.5%����
//			 PWM_Init4(3200);break;//8%
//			 PWM_Init4(3400);break;//8.5%
//			 PWM_Init4(3600);break;//9%
//			 PWM_Init4(3800);break;//9.5%

void hover()
{
	//��ͣ
	 PWM_Init1(3000);//50%����
	
}

void Up_throttle()
{
	
	//����	
	PWM_Init1(3080);//55%���ţ�ƽ���������ֵ
	
	PWM_Init1(3000);
}

void Down_throttle()
{
	
	//����
	PWM_Init1(2920);//45%���ţ�ƽ���½����ֵ
	
	PWM_Init1(3000);
}

void Forward_pitch()
{
	
	//��ǰ
	PWM_Init3(3200);
	
	PWM_Init3(3000);
	
}

void Back_pitch()
{
	
	//���
	PWM_Init3(2800);
	
	PWM_Init3(3000);
	
	
}


void Left_row()
{
	//����
	PWM_Init4(3200);
	
	PWM_Init4(3000);
}


void Right_row()
{
	//����
	PWM_Init4(2800);
	
	PWM_Init4(3000);
}


int main()
{
	gpio_key();
  PWM_GPIO_Init1();
	PWM_GPIO_Init2();
	PWM_GPIO_Init3();
	PWM_GPIO_Init4();
	while(1)
	{
//		switch(check_key())
//		{
//		  //��40000�ȷ�Ϊ�Ķ�����ĸ������ź�ʹ�ãg�ı�pwm_Init(a)����a��ֵ��ʵ��pwmռ�ձȴ�5.5%-9.5%�仯
//			//����
//			case 1: PWM_Init1(2200);break;//5.5%
//			case 2: PWM_Init1(2400);break;//6%
//			case 3: PWM_Init1(3200);break;//7.5%����
//			case 4: PWM_Init1(3400);break;//8.5%
//			
//			//ƫ��
//			case 5: PWM_Init2(2200);break;
//			case 6: PWM_Init2(2400);break;
//			case 7: PWM_Init2(3200);break;
//			case 8: PWM_Init2(3400);break;
//			
//			//����
//			case 9: PWM_Init3(2200);break;
//			case 10:PWM_Init3(2400);break;
//			case 11:PWM_Init3(3200);break;
//			case 12:PWM_Init3(3800);break;
//			
//			
//			//���
//			case 13:PWM_Init4(2200);break;
//			case 14:PWM_Init4(2733);break;
//			case 15:PWM_Init4(3266);break;
//			case 16:PWM_Init4(3800);break;	
//		}
	}
}


