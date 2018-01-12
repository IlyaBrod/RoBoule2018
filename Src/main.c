
#include "main.h"
#include "stm32l4xx.h"

#include "stm32l4xx_hal.h"

#include "../Basic/basic_system.h"
#include "../Basic/basic_i2c.h"
#include "../Basic/basic_led.h"
#include "../Basic/basic_usart.h"
#include "../App/IMU6050.h"
#include "../App/HC05.h"

float accelVect[3]; 
uint8_t data[4] = "AT\r\n";
uint8_t recev[10]={0};

int main(void)
{
	int t;
  
	
	HAL_Init();
	basic_init_clock();
	basic_init_gpio();
	basic_i2c_init();
	basic_led_init();
	basic_usart2_init(38400);
	
	//IMU6050_Init();
	//IMU6050_Test_Sensor();
	//IMU6050_Set_Scale_2g();
	
	//IMU6050_Get_Accel(accelVect);
	/*
	if(HC05_Test()==0)
	{
		basic_led_on();
		while(1);
	}*/
	
	
	basic_usart2_send(data,4);
	HAL_Delay(2);
	basic_usart2_read(recev,10);
	
  while (1)
  {
		//IMU6050_Get_Accel(accelVect);
		
		
		basic_led_on();
		for(t=0;t<8000000;t++);
		basic_led_off();
		for(t=0;t<5000000;t++);
  }
}
