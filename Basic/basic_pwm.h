/**
	*	PWM Module control.
	*	TIM1 : PB_1
	*	TIM2 : PA_1
	*
	*/


#ifndef BSP_PWM
#define BSP_PWM

#include <stm32l4xx_hal.h>

#define PWM_PERIOD 10000

/**
	*	Initialize the pwm on pins PA_1 and PB_1
	*
	*/
void basic_pwm_init(void);


/**
	*	Change the cyclic rate of PWM on pin PA_1
	*/
void basic_pwmA_write(float rate);

/**
	*	Change the cyclic rate of PWM on pin PB_1
	*/
void basic_pwmB_write(float rate);



#endif


