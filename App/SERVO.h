/**
	*	Servomotor control module.
	*	PWM : PB_1
	*/
	
#ifndef APP_SERVO
#define APP_SERVO

#include <stm32l4xx_hal.h>
#include "../Basic/basic_pwm.h"

void SERVO_Init(void);

void SERVO_write(int deg);



#endif
