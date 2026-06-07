#include "stm32f4xx.h"
#include "uart1.h"

#define GPIOBEN   (1U<<1)

#define RS485_DIR (1U<<0)

void rs485_init(void)
{
    RCC->AHB1ENR |= GPIOBEN;

    /* PB0 Output Mode */
    GPIOB->MODER &= ~(1U<<1);
    GPIOB->MODER |=  (1U<<0);

    /* Default Receive Mode */
    GPIOB->ODR &= ~RS485_DIR;
}

void rs485_tx_enable(void)
{
    GPIOB->ODR |= RS485_DIR;
}

void rs485_rx_enable(void)
{
    GPIOB->ODR &= ~RS485_DIR;
}

void rs485_send_char(char ch)
{
    rs485_tx_enable();

    uart_write(ch);

    /* Wait until transmission complete */
    while(!(USART1->SR & (1U<<6)));

    rs485_rx_enable();
}

void delay(void)
{
    for(volatile uint32_t i=0;i<500000;i++);
}
