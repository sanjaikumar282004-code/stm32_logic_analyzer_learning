#include "stm32f4xx.h"
#include "uart1.h"
#include <stdio.h>

int main()
{
	uart_init();

	while(1)
	{
	    printf("HELLO");
	}





}
