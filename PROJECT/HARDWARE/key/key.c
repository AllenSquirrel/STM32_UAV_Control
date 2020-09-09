#include"key.h"


void gpio_key(void)
{
	GPIO_InitTypeDef GPIO_InitStr;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC,ENABLE);//列c，4321
	GPIO_InitStr.GPIO_Pin  =GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11;
	GPIO_InitStr.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_InitStr.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOB, &GPIO_InitStr);
	
	GPIO_InitStr.GPIO_Pin  = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;//行r,1234
	GPIO_InitStr.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStr.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOB, &GPIO_InitStr);
//	GPIO_ResetBits(GPIOC, GPIO_Pin_9);
	GPIO_ResetBits(GPIOC, GPIO_Pin_9);
} 
	
void delay(void)
{
	int i,j;
	for(i=100;i>0;i--)
	{
		for(j=0;j<10000;j++);
	}
}
int check_key(void)
{
	int key_value=0;
	GPIO_Write(GPIOB, GPIOB->ODR & 0x0fff|0xf000);//PB12,13,14,15输出高  行
	if((GPIOB->IDR&0x0f00)==0x0000)//PB8,9,10,11为低，无按键按下
	{
		key_value = -1;
//		return key_value;
	}
	else
	{
		delay();
		if((GPIOB->IDR&0x0f00)==0x0000)//再次检测
		{
			key_value = -1;
//			return key_value;
		}
	}
	GPIO_Write(GPIOB, GPIOB->ODR & 0x0fff|0x1000);//PB15.14.13.12取0001
	switch(GPIOB->IDR&0x0f00)
	{
		case 0x0100:key_value=4;break;
		case 0x0200:key_value=3;break;
		case 0x0400:key_value=2;break;	
		case 0x0800:key_value=1;break;
	}
	GPIO_Write(GPIOB, GPIOB->ODR & 0x0fff|0x2000);//PB15.14.13.12取0010
	switch(GPIOB->IDR&0x0f00)
	{
		case 0x0100:key_value=8;break;
		case 0x0200:key_value=7;break;
		case 0x0400:key_value=6;break;
		case 0x0800:key_value=5;break;			
	}
	GPIO_Write(GPIOB, GPIOB->ODR & 0x0fff|0x4000);//PB15.14.13.12取0100
	switch(GPIOB->IDR&0x0f00)
	{
		case 0x0100:key_value=12;break;
		case 0x0200:key_value=11;break;
		case 0x0400:key_value=10;break;
		case 0x0800:key_value=9;break;			
	}
	GPIO_Write(GPIOB, GPIOB->ODR & 0x0fff|0x8000);//PB15.14.13.12取1000
	switch(GPIOB->IDR&0x0f00)
	{
		case 0x0100:key_value=16;break;
		case 0x0200:key_value=15;break;
		case 0x0400:key_value=14;break;
		case 0x0800:key_value=13;break;			
	}
	return key_value;
}
