#include "IMU6050.h"


void IMU6050_Init(void)
{
	basic_i2c_write(&hi2c1,MPU6050_DEFAULT_ADDRESS,MPU6050_RA_PWR_MGMT_1,0x00);
}

int IMU6050_Test_Sensor(void)
{

	uint8_t value=0;
	
	if(HAL_I2C_IsDeviceReady(&hi2c1, MPU6050_DEFAULT_ADDRESS<<1, 2,5)!=HAL_OK)
	{
		return 0;
	}
	
	basic_i2c_read(&hi2c1,MPU6050_DEFAULT_ADDRESS,MPU6050_RA_WHO_AM_I,&value);
	
	if(value==0x68) return 1;
	else return 0;
	
}


void IMU6050_Set_Scale_2g(void)
{
	
	basic_i2c_write(&hi2c1,MPU6050_DEFAULT_ADDRESS,MPU6050_RA_ACCEL_CONFIG,MPU6050_ACCEL_FS_2);
	
}

void IMU6050_Get_Accel(float vector[3])
{
	uint16_t value = 0;
	uint8_t buffer = 0;
	
	//Get X value
	basic_i2c_read(&hi2c1,MPU6050_DEFAULT_ADDRESS,MPU6050_RA_ACCEL_XOUT_H,&buffer);
	value = buffer;
	value = value<<8;
	basic_i2c_read(&hi2c1,MPU6050_DEFAULT_ADDRESS,MPU6050_RA_ACCEL_XOUT_L,&buffer);
	value = value+buffer;
	vector[0] = (float)(value*ACCEL_SCALE*2/65536.0);
	
	//Get Y value
	basic_i2c_read(&hi2c1,MPU6050_DEFAULT_ADDRESS,MPU6050_RA_ACCEL_YOUT_H,&buffer);
	value = buffer;
	value = value<<8;
	basic_i2c_read(&hi2c1,MPU6050_DEFAULT_ADDRESS,MPU6050_RA_ACCEL_YOUT_L,&buffer);
	value = value+buffer;
	vector[1] = (float)(value*ACCEL_SCALE*2/65536.0);
	
	//Get Z value
	basic_i2c_read(&hi2c1,MPU6050_DEFAULT_ADDRESS,MPU6050_RA_ACCEL_ZOUT_H,&buffer);
	value = buffer;
	value = value<<8;
	basic_i2c_read(&hi2c1,MPU6050_DEFAULT_ADDRESS,MPU6050_RA_ACCEL_ZOUT_L,&buffer);
	value = value+buffer;
	vector[2] = (float)(value*ACCEL_SCALE*2/65536.0);
	
}
