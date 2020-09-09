
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


//      //油门 throttle
//			 PWM_Init1(2200);break;//5.5%
//			 PWM_Init1(2400);break;//6%
//			 PWM_Init1(2600);break;//6.5%
//			 PWM_Init1(2800);break;//7%
//			 PWM_Init1(3000);break;//7.5%归中
//			 PWM_Init1(3200);break;//8%
//			 PWM_Init1(3400);break;//8.5%
//			 PWM_Init1(3600);break;//9%
//			 PWM_Init1(3800);break;//9.5%
//			
//			//偏航 yaw
//			 PWM_Init2(2200);break;//5.5%
//			 PWM_Init2(2400);break;//6%
//			 PWM_Init2(2600);break;//6.5%
//			 PWM_Init2(2800);break;//7%
//			 PWM_Init2(3000);break;//7.5%归中
//			 PWM_Init2(3200);break;//8%
//			 PWM_Init2(3400);break;//8.5%
//			 PWM_Init2(3600);break;//9%
//			 PWM_Init2(3800);break;//9.5%
//			
//			//俯仰 pitch
//			 PWM_Init3(2200);break;//5.5%
//			 PWM_Init3(2400);break;//6%
//			 PWM_Init3(2600);break;//6.5%
//			 PWM_Init3(2800);break;//7%
//			 PWM_Init3(3000);break;//7.5%归中
//			 PWM_Init3(3200);break;//8%
//			 PWM_Init3(3400);break;//8.5%
//			 PWM_Init3(3600);break;//9%
//			 PWM_Init3(3800);break;//9.5%
//			
//			
//			//横滚 row
//			 PWM_Init4(2200);break;//5.5%
//			 PWM_Init4(2400);break;//6%
//			 PWM_Init4(2600);break;//6.5%
//			 PWM_Init4(2800);break;//7%
//			 PWM_Init4(3000);break;//7.5%归中
//			 PWM_Init4(3200);break;//8%
//			 PWM_Init4(3400);break;//8.5%
//			 PWM_Init4(3600);break;//9%
//			 PWM_Init4(3800);break;//9.5%

void hover()
{
	//悬停
	 PWM_Init1(3000);//50%油门
	
}

void Up_throttle()
{
	
	//加油	
	PWM_Init1(3080);//55%油门，平稳上升最佳值
	
	PWM_Init1(3000);
}

void Down_throttle()
{
	
	//减油
	PWM_Init1(2920);//45%油门，平稳下降最佳值
	
	PWM_Init1(3000);
}

void Forward_pitch()
{
	
	//向前
	PWM_Init3(3200);
	
	PWM_Init3(3000);
	
}

void Back_pitch()
{
	
	//向后
	PWM_Init3(2800);
	
	PWM_Init3(3000);
	
	
}


void Left_row()
{
	//向左
	PWM_Init4(3200);
	
	PWM_Init4(3000);
}


void Right_row()
{
	//向右
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
//		  //将40000等分为四段配合四个按键信号使用改变pwm_Init(a)参数a的值，实现pwm占空比从5.5%-9.5%变化
//			//油门
//			case 1: PWM_Init1(2200);break;//5.5%
//			case 2: PWM_Init1(2400);break;//6%
//			case 3: PWM_Init1(3200);break;//7.5%归中
//			case 4: PWM_Init1(3400);break;//8.5%
//			
//			//偏航
//			case 5: PWM_Init2(2200);break;
//			case 6: PWM_Init2(2400);break;
//			case 7: PWM_Init2(3200);break;
//			case 8: PWM_Init2(3400);break;
//			
//			//俯仰
//			case 9: PWM_Init3(2200);break;
//			case 10:PWM_Init3(2400);break;
//			case 11:PWM_Init3(3200);break;
//			case 12:PWM_Init3(3800);break;
//			
//			
//			//横滚
//			case 13:PWM_Init4(2200);break;
//			case 14:PWM_Init4(2733);break;
//			case 15:PWM_Init4(3266);break;
//			case 16:PWM_Init4(3800);break;	
//		}
	}
}


