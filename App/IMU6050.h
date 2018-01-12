/**
	* IMU6050 sensor control functions by I2C.
	* The default adress is 0x68 (or 0x69 if A0 pin is HIGH).
	*/

#ifndef APP_IMU6050
#define APP_IMU6050

//+-2G scale for accelerometer
#define ACCEL_SCALE 2

#include <stm32l4xx_hal.h>
#include "../Basic/basic_i2c.h"
#include "./IMU6050_registers.h"


/**
	* Initialize the sensor by removing sleep mode.
	*/
void IMU6050_Init(void);

/**
	* Set the scale of the sensor to +-2g
	*/
void IMU6050_Set_Scale_2g(void);


/**
	* Test if the sensor is connected by reading WHO_I_AM register.
	* This register contains 0x68 which is the I2C adress of the sensor.
	* return 1 if no error, 0 if else.
	*/
int IMU6050_Test_Sensor(void);

/**
	* Read X,Y,Z acceleration and store inside the vector.
	*/
void IMU6050_Get_Accel(float vector[3]);


#endif
