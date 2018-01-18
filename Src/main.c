
#include "main.h"
#include "stm32l4xx.h"

#include "stm32l4xx_hal.h"

#include "../Basic/basic_system.h"
#include "../Basic/basic_i2c.h"
#include "../Basic/basic_led.h"
#include "../Basic/basic_usart.h"
#include "../Basic/basic_pwm.h"
#include "../App/IMU6050.h"
#include "../App/HC05.h"
#include "../App/L298N.h"
#include "../App/SERVO.h"

float accelVect[3]; 
uint8_t data[4] = "AT\r\n";
uint8_t recev[10]={0};

int main(void)
{
	int t;
  float curr_pwm=0;
	// Initialisation
	HAL_Init();
	basic_init_clock();
	basic_init_gpio();
	basic_i2c_init();
	basic_led_init();
  basic_usart2_init(9600); //38400
	basic_pwm_init();
	L298N_Init();
	SERVO_Init();
	
	//IMU6050_Init();
	//IMU6050_Test_Sensor();
	//IMU6050_Set_Scale_2g();
	//IMU6050_Get_Accel(accelVect);
	
	
	
	//basic_usart2_send(data,4);
	//HAL_Delay(2);
	//
	
	/*
	basic_pwmB_write(0);
	HAL_Delay(2000);
	basic_pwmB_write(0.5);
	HAL_Delay(2000);
	basic_pwmB_write(0.75);*/
	
	basic_pwmB_write(0.5);
	//SERVO_write(90);
	HAL_Delay(5000);
	basic_pwmB_write(0.8);
	//SERVO_write(170);
	HAL_Delay(5000);
	basic_pwmB_write(0.98);
	//SERVO_write(10);
	
  while (1)
  {
		//IMU6050_Get_Accel(accelVect);

		recev[1] =  basic_usart2_read_last();
		HAL_Delay(100);
		
		if(recev[0] != recev[1])
		{
				curr_pwm = (float)(recev[1]-127)/128;
				//L298N_write(curr_pwm);
				recev[0] = recev[1];
				//basic_usart2_send(recev,1);
		}
		
		basic_led_on();
		for(t=0;t<8000000;t++);
		basic_led_off();
		for(t=0;t<5000000;t++);
  }
}
