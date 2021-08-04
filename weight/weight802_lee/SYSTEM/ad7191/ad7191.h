#ifndef _AD7191_H_
#define	_AD7191_H_
#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include <stdlib.h>
#include <string.h>
#include "uart3.h"
//#include "uart2.h"
#include "uart1.h"
#define pw_on 		PAout(4) = 0
#define pw_down 	PAout(4) = 1
#define INPUT  	0
#define	TEMP 		1
#define INTERNAL	0
#define EXTERNAL	1
#define ADDR 0x1111
#define  A 2.00
#define	N	16
#define L 20
#define ad7191_temp(x) 	(PCout(0) = x)
#define ad7191_channal1(x) 	(PCout(1) = x)
#define ad7191_gain1(x) 	(PCout(2) = x)
#define ad7191_gain2(x) 	(PCout(3) = x)
#define ad7191_odr1(x) 	(PBout(0) = x)
#define ad7191_odr2(x) 	(PCout(5) = x)
#define ad7191_clksel(x) (PAout(0) = x)

enum rate_switch{
				rate_10,rate_50,rate_60,rate_120
};

enum gain_switch{
				gain_1,gain_8,gain_64,gain_128
};
void ad7191_config(enum rate_switch rate, enum gain_switch gain, int channal, unsigned char in_or_temp, unsigned char in_or_ex);
unsigned int read_data_from_ad7191();
float get_data_and_send_moving();
float get_data_and_send_static();
void ad7191_on();
void ad7191_off();
float data_compare();
float get_data_and_send();
void data_and_send(void);
void average_deal(void);
float filter_AD(void);
int deal_num(unsigned char *deal_tmp, unsigned char *data);
extern unsigned char initflag;

extern float amp,amp1,amp11;
extern int flag_count;
extern	unsigned int data_1;
extern unsigned int data_1;
extern unsigned char flag_temp;
extern	float data_temp;
 extern  int flag_t; 
 extern  float load_amp[16];
extern void To_zero();
extern unsigned int data;
extern unsigned char light_sensor;
extern float amp11_t;
extern float amp_v;
extern float amp_ad;
float	GetTemperature();
#endif
