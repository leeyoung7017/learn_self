#ifndef __EXTI_H
#define __EXIT_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板
//外部中断 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/3
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   	

/***********************************修改后****************************************/
typedef struct{						//区间数量显示
	unsigned int quantity_area1;
	unsigned int quantity_area2;
	unsigned int quantity_area3;
}Quantity_Area;

typedef struct{						//区间质量显示
	unsigned int quality_area1;
	unsigned int quality_area2;
	unsigned int quality_area3;
}Quality_Area;

/********************************************************************************/

void EXTIX_Init(void);//外部中断初始化		 					    
#endif

