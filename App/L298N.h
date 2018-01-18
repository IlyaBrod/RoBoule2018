/**
	*	L298N Motor control module.
	*	IN 1 : PA_12
	*	IN 2 : PA_11
	*	PWM : PA_1
	*/


#ifndef APP_L298N
#define APP_L298N

#include <stm32l4xx_hal.h>
#include "../Basic/basic_pwm.h"

void L298N_Init(void);

/**
	* Move the motor in two directions.
	*	@param rate PWM value, >0 one direction <0 other direction.
	*/
void L298N_write(float rate);


#endif


