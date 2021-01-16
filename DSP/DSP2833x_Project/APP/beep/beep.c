/*
 * beep.c
 *
 *  Created on: 2021年1月10日
 *      Author: Lee
 */

#include "beep.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"

void Beep_Init(void)
{
	EALLOW;

	SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;    // GPIO input clock

	GpioCtrlRegs.GPAQSEL1.bit.GPIO6 = 0;	//通用IO口
	GpioCtrlRegs.GPADIR.bit.GPIO6 = 1;		//输出
	GpioCtrlRegs.GPAPUD.bit.GPIO6 = 1;		//上拉电阻

	BEEP_UP;

	EDIS;
}
