#include "SERVO.h"


void SERVO_Init(void)
{
	basic_pwmB_write(0.52);
	
}

void SERVO_write(int deg)
{
	deg = deg%180;
	basic_pwmB_write(deg/180+0.5);
}
