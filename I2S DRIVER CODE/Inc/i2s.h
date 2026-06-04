/*
 * i2s.h
 *
 *  Created on: Jun 4, 2026
 *      Author: sanja
 */

#ifndef I2S_H_
#define I2S_H_

#include <stdint.h>

void i2s_init(void);
void i2s_transmit(uint16_t data);



#endif /* I2S_H_ */
