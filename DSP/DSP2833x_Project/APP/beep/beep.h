/*
 * Beep.h
 *
 *  Created on: 2021Äê1ÔÂ10ÈÕ
 *      Author: Lee
 */

#ifndef BEEP_H_
#define BEEP_H_


#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"

void Beep_Init(void);

#define BEEP_UP (GpioDataRegs.GPASET.bit.GPIO6 = 1)
#define BEEP_DOWN (GpioDataRegs.GPACLEAR.bit.GPIO6 = 1)
#define BEEP_TOGGLE (GpioDataRegs.GPATOGGLE.bit.GPIO6 = 1)

#endif /* BEEP_H_ */
