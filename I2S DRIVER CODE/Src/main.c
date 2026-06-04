#include "stm32f4xx.h"
#include <stdint.h>
#include "i2s.h"

int main(void)
{
	i2s_init();

	while(1)
	{
		while(1)
		{
		    i2s_transmit(0x5555);
		}
	}

}







