#include "led.h"
#include "relay.h"
#include "delay.h"
#include "sys.h"
#include "ad7191.h"
#include "FlagDeal.h"
#include "timer.h"
#include "uart1.h"
#include "uart3.h"
#include "usart.h"
#include "master.h"
#include "usart_op.h"
#include "stdio.h"
#include "exti.h"
//unsigned char average_flag = 0;
//unsigned char to_get_num = 0;
int flag_t1=  1;

int main(void)

{	
	SystemInit();
	delay_init();	    	 //延时函数初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	RS485_Init();//硬件层通讯使能
	uart_init(9600);  //电脑通讯
	RELAY_Init();	
	flag_sys_init();
	delay_init();	    	 //延时函数初始化	 
	uart1_init(115200);
	uart3_init(115200);
	TIM2_Int_Init(719,49);//1ms 定时器		72000 000/ (719*49)=2000Hz  0.5ms
	ad7191_config(rate_120,gain_128,2,INPUT,INTERNAL);//AD7191配置
	EXTIX_Init();
			//delay_ms(100);
	
	while(1)
	{ 	
	
			
	}
}	
