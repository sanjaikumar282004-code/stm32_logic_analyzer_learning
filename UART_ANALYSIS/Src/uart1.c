/*
 * uart.c
 *
 *  Created on: May 9, 2026
 *      Author: sanja
 */
#include "stm32f4xx.h"

#define GPIOAEN (1U<<0)
#define LED     (1U<<5)
#define PERIPHCLK 16000000
#define BAUDRATE 115200

void uart_init()
{
	//Enable clock for GPIOA AND GPIOC
		RCC->AHB1ENR |= GPIOAEN;

		//set pa2 to alternate function mode
		GPIOA->MODER |= (1U<<19);
		GPIOA->MODER &= ~(1U<<18);

		RCC->APB2ENR |= (1U<<4);

		GPIOA->AFR[1] &= ~(1U<<7);
		GPIOA->AFR[1] |= (1U<<6);
		GPIOA->AFR[1] |= (1U<<5);
		GPIOA->AFR[1] |= (1U<<4);

		USART1->BRR = (PERIPHCLK + (BAUDRATE/2))/BAUDRATE;

		USART1->CR1 |= (1U<<13);
		USART1->CR1 |= (1U<<3);
}

void uart_write(int ch)
{
	while((USART1->SR & (1U<<7))==0){}

	USART1->DR = (ch & 0xff);

}

int __io_putchar(int ch)
{
	uart_write(ch);
	return ch;
}
