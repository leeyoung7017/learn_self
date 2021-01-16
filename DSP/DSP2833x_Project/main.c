/*
 * main.c
 *
 *  Created on: 2021Äê1ÔÂ09ÈÕ
 *      Author: Lee
 */


#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "leds.h"
#include "beep.h"


void delay(void)
{
    Uint16 		i;
	Uint32      j;
	for(i=0;i<32;i++)
		for (j = 0; j < 100000; j++);
}


void main()
{
	InitSysCtrl();

	LED_Init();
	Beep_Init();

	LED1_ON;
	LED2_ON;
	LED3_ON;
	LED4_ON;
	LED5_ON;
	LED6_ON;
	LED7_ON;

	while(1)
	{
		BEEP_TOGGLE;
		delay();
	}

}

