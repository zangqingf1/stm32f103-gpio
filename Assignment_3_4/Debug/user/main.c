#include "stm32f10x.h"
#include "delay.h"

volatile int a = 0;
volatile int b = 2;
volatile int c = 2;

int main(void)
{
	while(1)
	{
		a = b * c;
		Delay(100);
		c++;
	}
}
