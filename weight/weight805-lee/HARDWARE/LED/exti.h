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
//����������ʾ
typedef struct{						
	 int quantity_area1;
	 int quantity_area2;
	 int quantity_area3;
}Quantity_Area;

//����������ʾ
typedef struct{						
	 float quality_area1;
	 float quality_area2;
	 float quality_area3;
}Quality_Area;

extern Quantity_Area quantity_area;
extern Quality_Area quality_area;	
/********************************************************************************/

void EXTIX_Init(void);//�ⲿ�жϳ�ʼ��		 					    
#endif

