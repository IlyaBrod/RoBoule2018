#include "basic_led.h"

void basic_led_init(void)
{
	//Init user LED3 on PB13
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	GPIOB->MODER = (GPIOB->MODER & 0xFFFFFF3F) | 0x00000040;
	GPIOB->OTYPER &= 0xFFFFFFF7;
	GPIOB->OSPEEDR &= 0xFFFFFF3F;
	GPIOB->PUPDR &= 0xFFFFFF3F;
	GPIOB->ODR &= 0xFFFFFFF7;
}

void basic_led_on(void)
{
	GPIOB->ODR |= 0x00000008;
}

void basic_led_off(void)
{
	GPIOB->ODR &= 0xFFFFFFF7;
}
