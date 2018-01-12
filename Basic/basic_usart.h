/**
	*	UART2 control functions.
	*	Reception is made by interruption, and stored until new reception.
	*	Trasmission is made by giving a data array like uint8_t data = "Hello", with a length of 5.
	*
	* Warning : The .c file contains UART2_IRQnHandler()
	*/

#ifndef BSP_USART
#define BSP_USART

#include <stm32l4xx_hal.h>

#define READ_BUFFER_SIZE 10

/**
	* Initialize the USART2.
	*	RX : PA_3
	*	TX : PA_2
	*/
void basic_usart2_init(int baudrate);


/**
	* Send data by UART2
	*	@param data Data array. Example : data="Hello"
	*	@param count Length of array to send. Example : 5
	*/
void basic_usart2_send(uint8_t* data, uint16_t count);

/**
	* Send data by UART2
	*	@param data Data array
	*	@param count Length of array to send
	*/
void basic_usart2_read(uint8_t* data, uint16_t count);



#endif
