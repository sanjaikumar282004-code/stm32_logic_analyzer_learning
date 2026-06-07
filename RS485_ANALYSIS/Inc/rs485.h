/*
 * rs485.h
 *
 *  Created on: Jun 7, 2026
 *      Author: sanja
 */

#ifndef RS485_H_
#define RS485_H_

void rs485_init(void);
void rs485_tx_enable(void);
void rs485_rx_enable(void);
void rs485_send_char(char ch);
void delay(void);

#endif /* RS485_H_ */
