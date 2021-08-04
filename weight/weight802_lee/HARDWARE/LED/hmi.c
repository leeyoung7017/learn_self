#include "hmi.h"
#include "flash.h"
#include "uart1.h"

void HMI_Init(void)
{
	int i;
	for(i = 0;i<8;i++)
	{
		WRITE_HMI_Data(0x2111+i*0x100,0);
		delay_ms(10);
	}
	WRITE_HMI_Data(0x2B11,0);
	delay_ms(10);
	WRITE_HMI_Data(0x2020,0);
	delay_ms(10);
	
}

