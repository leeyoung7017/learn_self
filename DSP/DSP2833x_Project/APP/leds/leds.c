/*
 * leds.c
 *
 *  Created on: 2021年1月09日
 *      Author: Lee
 */
#include "leds.h"


void LED_Init(void)
{
	EALLOW;
	SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;

	//LED1
	GpioCtrlRegs.GPCMUX1.bit.GPIO68=0;//通用GPIO功能
	GpioCtrlRegs.GPCDIR.bit.GPIO68=1;//输出
	GpioCtrlRegs.GPCPUD.bit.GPIO68=0;//上拉电阻

	//LED2
	GpioCtrlRegs.GPCMUX1.bit.GPIO67=0;
	GpioCtrlRegs.GPCDIR.bit.GPIO67=1;
	GpioCtrlRegs.GPCPUD.bit.GPIO67=0;

	//LED3
	GpioCtrlRegs.GPCMUX1.bit.GPIO66=0;
	GpioCtrlRegs.GPCDIR.bit.GPIO66=1;
	GpioCtrlRegs.GPCPUD.bit.GPIO66=0;

	//LED4
	GpioCtrlRegs.GPCMUX1.bit.GPIO65=0;
	GpioCtrlRegs.GPCDIR.bit.GPIO65=1;
	GpioCtrlRegs.GPCPUD.bit.GPIO65=0;

	//LED5
	GpioCtrlRegs.GPCMUX1.bit.GPIO64=0;
	GpioCtrlRegs.GPCDIR.bit.GPIO64=1;
	GpioCtrlRegs.GPCPUD.bit.GPIO64=0;

	//LED6
	GpioCtrlRegs.GPAMUX1.bit.GPIO10=0;
	GpioCtrlRegs.GPADIR.bit.GPIO10=1;
	GpioCtrlRegs.GPAPUD.bit.GPIO10=0;

	//LED7
	GpioCtrlRegs.GPAMUX1.bit.GPIO11=0;
	GpioCtrlRegs.GPADIR.bit.GPIO11=1;
	GpioCtrlRegs.GPAPUD.bit.GPIO11=0;



	LED1_OFF;
	LED2_OFF;
	LED3_OFF;
	LED4_OFF;
	LED5_OFF;
	LED6_OFF;
	LED7_OFF;

	EDIS;
}
