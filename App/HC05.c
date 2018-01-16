#include "HC05.h"

int HC05_Test(void)
{
	uint8_t data[4] = "AT\r\n";
	basic_usart2_send(data,4);

	basic_usart2_read(data,4);
	if(data[0]==79 && data[1]==75)
	{
		return 1;
	}
	else return 0;
}

