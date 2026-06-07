/*
 * uart.h
 *
 *  Created on: May 9, 2026
 *      Author: sanja
 */

#ifndef UART1_H_
#define UART1_H_

void uart_init();
void uart_write(int ch);
int __io_putchar(int ch);

#endif /* UART1_H_ */
