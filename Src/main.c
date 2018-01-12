
#include "main.h"
#include "stm32l4xx.h"

#include "stm32l4xx_hal.h"

#include "../Basic/basic_system.h"
#include "../Basic/basic_i2c.h"
#include "../Basic/basic_led.h"
#include "../App/IMU6050.h"

float accelVect[3];

int main(void)
{
	int t;
  
	
	HAL_Init();
	basic_init_clock();
	basic_init_gpio();
	basic_i2c_init();
	basic_led_init();
	
	IMU6050_Init();
	IMU6050_Test_Sensor();
	IMU6050_Set_Scale_2g();
	
	IMU6050_Get_Accel(accelVect);
	
  while (1)
  {
		IMU6050_Get_Accel(accelVect);
		basic_led_on();
		for(t=0;t<8000000;t++);
		basic_led_off();
		for(t=0;t<5000000;t++);
  }
}
