#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"

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



void TIM2_Int_Init(u16 arr,u16 psc);
void TIM3_PWM_Init(u16 arr,u16 psc);
void TIM3_PWMShiftInit(void);
void TIM2_PWMShiftInit(void);
extern unsigned char flag_test;

extern unsigned char average_flag ;
extern unsigned char flag_screen;
extern unsigned char to_get_num ;
#endif