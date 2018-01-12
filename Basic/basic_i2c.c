#include "basic_i2c.h"

I2C_HandleTypeDef hi2c1;


void basic_i2c_init(void)
{

	hi2c1.Instance = I2C1;
	hi2c1.Init.Timing = 0xC010151E;
	hi2c1.Init.OwnAddress1 = 0;
	hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c1.Init.OwnAddress2 = 0;
	hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	HAL_I2C_Init(&hi2c1);

	HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE);

	HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0);

}



int basic_i2c_read(I2C_HandleTypeDef* I2Cx, uint8_t device_address, uint8_t register_address, uint8_t* data)
{
	if(HAL_I2C_Master_Transmit(I2Cx,(uint16_t)(device_address<<1), &register_address, 1, 1000)!=HAL_OK) return 1;
	if(HAL_I2C_Master_Receive(I2Cx, (uint16_t)(device_address<<1), data, 1, 1000)!=HAL_OK) return 1;
	else return 0;
}

int basic_i2c_write(I2C_HandleTypeDef* I2Cx, uint8_t device_address, uint8_t register_address, uint8_t data)
{
	uint8_t write_Buffer[2];
	write_Buffer[0] = register_address;
	write_Buffer[1] = data;
	
	if(HAL_I2C_Master_Transmit(I2Cx, (uint16_t)(device_address<<1), (uint8_t *)write_Buffer, 2, 1000)!=HAL_OK) return 1;
	else return 0;
}
