#include "timer.h"
#include "led.h"
#include "FlagDeal.h"
#include "ad7191.h"
#include "usart_op.h"
#include "flash.h"
//#include "usart.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
//ALIENTEKս��STM32������
//��ʱ�� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/4
//�汾��V1.1
//��Ȩ���У�����ؾ���
//Copyright(C) �������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//********************************************************************************
//V1.1 20120904
//1,����TIM3_PWM_Init������
//2,����LED0_PWM_VAL�궨�壬����TIM3_CH2����									  
//////////////////////////////////////////////////////////////////////////////////  
   	  
//ͨ�ö�ʱ��3�жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��3!



//TIM3 PWM���ֳ�ʼ�� 
//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��

//void TIM3_PWMShiftInit(void)
//{
//	GPIO_InitTypeDef  GPIO_InitStruct;
//	TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStruct;
//	TIM_OCInitTypeDef TIM_OCInitStruct;
// 
//	
//	/**********************TIM3 GPIO??*****************************/
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//	
//	//GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE); //Timer3������ӳ��  TIM3_CH2->PB5    
//	
//	
//	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
//	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA,&GPIO_InitStruct);
//	
//	/**********************???TimBase???*************************/
//	
//	
//	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
////	TIM_TimeBaseInitStruct.TIM_Period =  3599;  //??????????,Frequence = 36000000/PSC/(ARR+1);5k
//  TIM_TimeBaseInitStruct.TIM_Period =  1599;  //??????????,Frequence = 36000000/PSC/(ARR+1);11k
//	TIM_TimeBaseInitStruct.TIM_Prescaler = 1;     
//	
//	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);
//	
//	/**********************???TIM3 OC???*************************/
//	TIM_OCInitStruct.TIM_OCIdleState = TIM_OCIdleState_Set;
//	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_Toggle;
//	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
//	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
//	TIM_OCInitStruct.TIM_Pulse = 0;   //?????,CCR?CNT??????
//	//TIM_OCInitStruct.TIM_Pulse = 0;   //?????,CCR?CNT??????

//	TIM_OC1Init(TIM3,&TIM_OCInitStruct);

//	TIM_Cmd(TIM3, ENABLE);
//}

void TIM2_PWMShiftInit(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStruct;
	TIM_OCInitTypeDef TIM_OCInitStruct;
 
	
	/**********************TIM3 GPIO??*****************************/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	//GPIO_PinRemapConfig(GPIO_PartialRemap2_TIM2, ENABLE); //Timer3������ӳ��  TIM3_CH2->PB5    
	
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	/**********************???TimBase???*************************/
	
	
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period =  3599;  //??????????,Frequence = 36000000/PSC/(ARR+1);
	TIM_TimeBaseInitStruct.TIM_Prescaler = 0;     
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	
	/**********************???TIM3 OC???*************************/
	TIM_OCInitStruct.TIM_OCIdleState = TIM_OCIdleState_Set;
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_Toggle;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = 1800;   //?????,CCR?CNT??????
	
	TIM_OC2Init(TIM2,&TIM_OCInitStruct);
	
  TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;   
  TIM_OCInitStruct.TIM_Pulse = 2820;   //???? = 180*CCR/(ARR+1)     1200
	 //TIM_OCInitStruct.TIM_Pulse = 1;   //???? = 180*CCR/(ARR+1)
	TIM_OC3Init(TIM2,&TIM_OCInitStruct);
 
	TIM_Cmd(TIM2, ENABLE);
}
unsigned char average_flag = 0;
unsigned char to_get_num = 0;
void TIM2_Int_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //ʱ��ʹ��
	
	//��ʱ��TIM3��ʼ��
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λx
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM3�ж�,���������ж�

	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 4;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���


	TIM_Cmd(TIM2, ENABLE);  //ʹ��TIMx			
//	register_flag(get_data_and_send,&to_get_num);
//	register_flag(average_deal,&average_flag);
}

static u8 i=0;
int ms = 0;
//int mms_temp = 0;
unsigned char flag_test = 0;
unsigned char flag_screen= 0;
unsigned int valve = 0, valve_keep=0,valve1 = 0,valve_return=0;
/**********************************************/
unsigned int pro_edit_addr;
unsigned int index_edit;
/**********************************************/
void TIM2_IRQHandler(void)   //TIM2�ж�
{
	static unsigned int cnt = 0,time_buf = 0,sec_2= 0;
	

	
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)  //���TIM3�����жϷ������
	{
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);  //���TIMx�����жϱ�־ 
		cnt++;
		ms++;
	//	mms_temp++;
		if(initflag == 0)
		{
			if((cnt % 100) == 0)	//100�����к�average_flagֵ1
				average_flag = 1;		//to caculate average 100/s only once from init
		}
		else if(cnt >= 4)
		{
			sec_2++;
			if(sec_2 == 2)
			{
				sec_2 = 0;
				to_get_num = 1;				//4*2=8,mei >8 ms jin yici ,zhi xing yici get_data_ad_send;
			}
			cnt = 0;
		}
	/**************************************************************************************************/	
		if(ms >= 500)		//mei ge 100ms du chuankou ping de zhuangtai
		{
			flag_test = 1;
			ms = 0;
			if((flag_state != 2))
			{
				amp11_t = data_compare();
				//amp11_t =1000 ;
				data_and_send();
			}
		}
		if(flag_screen == 1)//��̬��ʾ
		{
//			amp11 =get_data_and_send_moving();
//			// amp11=amp;
//			amp11 = amp-data_temp+change_old;
			
			data_and_send();//���ݴ��䵽��
			flag_screen= 0;
		}
/**********************kong zhi lai hui bo dong**************************************************/
		if (over_top == 1)
		{
			valve++;
			if (valve >= tichu_old)
			{
				GPIO_ResetBits(GPIOC,GPIO_Pin_7);// start
			} 
			valve_keep++;
			
			if (valve_keep >=(keep_old+tichu_old)) 
			{
				GPIO_SetBits(GPIOC,GPIO_Pin_7); //return
				over_top = 0;
				valve = 0;
				valve_keep=0;
			}
		}
				
		if (below_bottom == 1)
		{
			valve1++;
			if (valve1 >= tichu_old)
			{
				GPIO_ResetBits(GPIOA,GPIO_Pin_11);
			} 
			valve_return++;
		  if (valve_return >= (keep_old+tichu_old)) 
		  {
				GPIO_SetBits(GPIOA,GPIO_Pin_11); 
			  
				below_bottom = 0;
				valve1 = 0;
				valve_return=0;
				//GPIO_SetBits(GPIOA,GPIO_Pin_11);  
			}
		}
/************************kong zhi lai hui bo dong************************************************/
/************************chuankou ping du qu shuju************************************************/		
		if(flag_test == 1)
		{
			flag_test = 0;
			
			//��ȡ������ָ��
			READ_HMI(0X1000,0X01);//����������/��ֹͣ��״̬		5a a5 06 83 10 00 01 00 01/02/03
			
			READ_HMI(0X0010,0X02);//����Ƥ��ת�١�״̬			5a a5 08 83 00 10 02 xx xx xx xx
			
			READ_HMI(0X0020,0X01);//������д��
/******************************************�޸�ǰ��****************************************************/
			/*��ȡ��Ʒ�༭����*/
			READ_HMI(0x0500,0x01);						//5a a5 06 83 05 00 

			READ_HMI(0X2022,0x01);
			
			READ_HMI(0X2020,0x02);	//��������1���ж�
/*��Ӧ����Щ����*/
														if(flag_data)
														{
//															flag_data = 0;
															READ_HMI(widget_addr.name_addr,0x02);	//Ʒ��	
														}
														if(flag_name)
														{
//															flag_name = 0;
															READ_HMI(widget_addr.min_addr,0x02);	//��ȡ����
														}
														if(flag_min)
														{
//															flag_min = 0;
															READ_HMI(widget_addr.max_addr,0x02);	//��ȡ����
														}
														if(flag_max)
														{
//															flag_max = 0;
															READ_HMI(widget_addr.corr_addr,0x02);	//��ȡ����ϵ��
														}
			

			if(flag_name_read)
			{
				int addr = 0x1130+index_edit*2;
				READ_HMI(addr,0x02);	//Ʒ��	/*40����*//*80���ֽ�*//*240������*/
			}
			if(flag_time)
			{
				flag_time = 0;
				read_time();
			}
/****************************************************************************************************/
			
			READ_HMI(0X1034,0X02);//�����������㡱״̬
			
			READ_HMI(0X2014,0X02);//���޳��ӳ�
			
			READ_HMI(0X2016,0X02);//����������
			
			READ_HMI(0X1018,0X02);//�������궨
			
			READ_HMI(0X302A,0X02);//�궨���
			
			READ_HMI(0X302C,0X02);//���������
			
			READ_HMI(0X302E,0X02);//���������
		}

	}
}


					