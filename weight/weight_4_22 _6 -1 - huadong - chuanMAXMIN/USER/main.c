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
	delay_init();	    	 //��ʱ������ʼ��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	RS485_Init();//Ӳ����ͨѶʹ��
	uart_init(9600);  //����ͨѶ
	RELAY_Init();	
	flag_sys_init();
	delay_init();	    	 //��ʱ������ʼ��	 
	uart1_init(115200);
	uart3_init(115200);
	TIM2_Int_Init(719,49);//1ms ��ʱ��		72000 000/ (719*49)=2000Hz  0.5ms
	ad7191_config(rate_120,gain_128,2,INPUT,INTERNAL);//AD7191����
	EXTIX_Init();
			//delay_ms(100);
	
	while(1)
	{ 	
	
			
	}
}	
