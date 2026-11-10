/*
	高电平点亮LED-通用推挽输出
	PA0->电阻->LED正极->LED负极->GND
	闪烁周期：高电平（200ms）+低电平（800ms）
	闪烁频率：1Hz
	2026-11-1
*/
#include "stm32f10x.h"
#include "delay.h"

int main(void)
{
	// 开启GPIOA时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	// 初始化IO引脚 PA0 通用输出推挽模式 2MHz
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	while(1)
	{
		// 输出高电平，有电流，亮
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		Delay(200);
		// 输出低电平，无电流，不亮
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		Delay(800);
	}
}
