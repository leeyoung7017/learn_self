#ifndef __EXTI_H
#define __EXIT_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//�ⲿ�ж� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/3
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   	

/***********************************�޸ĺ�****************************************/
typedef struct{						//����������ʾ
	unsigned int quantity_area1;
	unsigned int quantity_area2;
	unsigned int quantity_area3;
}Quantity_Area;

typedef struct{						//����������ʾ
	unsigned int quality_area1;
	unsigned int quality_area2;
	unsigned int quality_area3;
}Quality_Area;

/********************************************************************************/

void EXTIX_Init(void);//�ⲿ�жϳ�ʼ��		 					    
#endif

