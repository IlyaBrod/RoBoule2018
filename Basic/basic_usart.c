#include "basic_usart.h"

UART_HandleTypeDef usart2;

uint8_t buffer[READ_BUFFER_SIZE];
int bufferCounter=0;

void basic_usart2_init(int baudrate)
{
	
	
	//Configure USART2 pins as ALTERNATE FUNCTION : PA_2 and PA_3
	RCC->AHB2ENR |= 1;
	GPIOA->MODER = (GPIOA->MODER & 0xFFFFFF5F) | 0x000000A0;
	GPIOA->OTYPER &= 0xFFFFFFF3;	//push pull config
	GPIOA->OSPEEDR = (GPIOA->OSPEEDR & 0xFFFFFF0F) | 0x000000F0;; //High speed config
	GPIOA->PUPDR = (GPIOA->PUPDR & 0xFFFFFFAF) | 0x00000050;
	GPIOA->ODR &= 0xFFFFFFF3;
	
	//Initialize USART2 pheripheral
	// No parity bit
	RCC->APB1ENR1 |= 0x00020000; //clock
	usart2.Instance = USART2;
  usart2.Init.BaudRate = baudrate;
  usart2.Init.WordLength = UART_WORDLENGTH_8B;
  usart2.Init.StopBits = UART_STOPBITS_1;
  usart2.Init.Parity = UART_PARITY_NONE;
  usart2.Init.Mode = UART_MODE_TX_RX;
  usart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  usart2.Init.OverSampling = UART_OVERSAMPLING_16;
  usart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  usart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  USART2->CR1 |= USART_CR1_RXNEIE; //receive interrupt enable
	HAL_UART_Init(&usart2);
	
	//Interrupt enable
	
	//USART_ITConfig();
	NVIC_EnableIRQ(USART2_IRQn);
	
}

void basic_usart2_send(uint8_t* data, uint16_t count)
{
		HAL_UART_Transmit(&usart2,data,count,1000);

}

void basic_usart2_read(uint8_t* data, uint16_t count)
{
	int k;
	for(k=0;k<count;k++)
	{
		data[(bufferCounter-k)%READ_BUFFER_SIZE] = buffer[(bufferCounter-k)%READ_BUFFER_SIZE];
	}
}


void USART2_IRQHandler(void)
{
	//if interrupt because reception
	if(USART2->ISR & USART_ISR_RXNE)
	{
		HAL_UART_Receive(&usart2,buffer+bufferCounter,1,1000);
		if (bufferCounter < READ_BUFFER_SIZE)
			bufferCounter ++;
		else bufferCounter = 0;
		//HAL_UART_Receive_IT(&usart2,buffer+bufferCounter,1);
		
	}
	
	//__HAL_UART_CLEAR_IT(&usart2);
	//HAL_NVIC_ClearPendingIRQ(USART2_IRQn);
}


uint8_t basic_usart2_read_last(void)
{
	return buffer[(bufferCounter-1)%READ_BUFFER_SIZE];
}


