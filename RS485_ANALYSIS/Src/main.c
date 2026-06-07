#include "stm32f4xx.h"
#include "uart1.h"
#include "rs485.h"
#include <stdio.h>


int main(void)
{
    uart_init();

    rs485_init();

    while(1)
    {
        //rs485_send_char('U');

    	rs485_tx_enable();

		printf("Hello\r\n");

		/* Wait until transmission complete */
		while(!(USART1->SR & (1U<<6)));

		rs485_rx_enable();

        delay();
    }
}
