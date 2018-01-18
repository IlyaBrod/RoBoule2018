#include "L298N.h"

void L298N_Init(void)
{
	
	//Init GPIO
	RCC->AHB2ENR |= 1;
	GPIOA->MODER = (GPIOA->MODER & 0xFC3FFFFF) | 0x01400000;
	GPIOA->OTYPER &= 0xFFFFE7FF;	//push pull config
	GPIOA->OSPEEDR &= 0xFC3FFFFF;; //High speed config
	GPIOA->PUPDR = (GPIOA->PUPDR & 0xFC3FFFFF) | 0xF28FFFFF;
	GPIOA->ODR &= 0xFFFFE7FF;
	
	//Setup PWM values
	basic_pwmA_write(0);
}



void L298N_write(float rate)
{
	
	if(rate>=0)
	{
		GPIOA->ODR = (GPIOA->ODR & 0xFFFFE7FF) | 0x00000800;
		basic_pwmA_write(rate);
		
	}
	else
	{
		GPIOA->ODR = (GPIOA->ODR & 0xFFFFE7FF) | 0x00001000;
		basic_pwmA_write(-rate);
	}
	
	
}
