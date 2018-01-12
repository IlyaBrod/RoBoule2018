/**
	* Fichier de contrôle i2c.
	* Attention : HAL_I2C_XX(&ic2, Adress <<1 ... Il faut shift l'adresse de 1. D'après la datasheet de la lib.
	* OMG !
	*
*/

#ifndef BSP_I2C
#define BSP_I2C

#include <stm32l4xx_hal.h>

extern I2C_HandleTypeDef hi2c1;


/**
 * Init I2C module with the stm32l4 as master.
 * Standard mode
 * Speed : 100kHz
 * Analog Filter : Enable
 */
void basic_i2c_init(void);

/**
	* Read a register value and store inside buffer[]
	* @param &I2Cx The i2c HAL handler
	*	@param device_adress Adress of the I2C slave device
	* @param register_adress Adress of the register to be read
	* @param data Pointer to a data array, to store the readen values.
	* @return 0 : No error, 1 : Error
	*/
int basic_i2c_read(I2C_HandleTypeDef* I2Cx, uint8_t device_address, uint8_t register_address, uint8_t* data);

/**
	* Read a register value and store inside buffer[]
	* @param &I2Cx The i2c HAL handler
	*	@param device_adress Adress of the I2C slave device
	* @param register_adress Adress of the register to be written
	* @param data 8bits value to store in the register.
	* @return 0 : No error, 1 : Error
	*/
int basic_i2c_write(I2C_HandleTypeDef* I2Cx, uint8_t device_address, uint8_t register_address, uint8_t data);


#endif




