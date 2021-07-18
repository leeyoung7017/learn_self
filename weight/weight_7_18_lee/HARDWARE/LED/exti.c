#include "exti.h"
#include "ad7191.h"
#include "timer.h"
#include "usart_op.h"
//�ⲿ�ж�0�������
void EXTIX_Init(void)
{
	//PA6 ADshuchu
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

   	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//ʹ�ܸ��ù���ʱ��

    //GPIOE.2 �ж����Լ��жϳ�ʼ������   �½��ش���
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource6);

  	EXTI_InitStructure.EXTI_Line=EXTI_Line6;	//KEY2
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���

  	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//ʹ�ܰ���WK_UP���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2�� 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//�����ȼ�3
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure); 

	//PB14  guanggan
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14); //PB14

  	EXTI_InitStructure.EXTI_Line=EXTI_Line14;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);		//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
	
	
   	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;			//ʹ�ܰ���WK_UP���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2�� 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//�����ȼ�1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
	NVIC_Init(&NVIC_InitStructure);
}


//�ⲿ�ж�0������� 
int mms_temp = 0;
int flag_moving= 0;
enum {T,W}state_TW;
int once=1,flag_zero= 0;
int i_zero=0;
float  a_zero[2500];
float sum_zero = 0;
int amp_zero= 0;
/********************************update parameter*********************************/
static Quantity_Area quantity_area;
static Quality_Area quality_area;	//�Ƿ���Ҫ��̬����/							/*������λ�ȡ*/
/*********************************************************************************/
/*****************************************
	*	@brief	�ⲿ�ж���ʵ����'���ݵĻ�ȡ'��'���ݵĴ���'
******************************************/
void EXTI9_5_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line6)!= RESET)//yes or no inter interrupt   pa6------DOUT/RDY 
	{
		state_TW = W;
		amp_ad = get_data_and_send();
	
		 flag_count = 0;
		 mms_temp++;
		 if((flag_state == 2)&&(flag_moving==1))	//��̬��ȡ�����ݴ���
		 {
			//amp11 =get_data_and_send_moving();
			// amp11=amp;
			// amp11_t = amp_ad-data_temp+change_old;
			amp11_t = amp_ad-data_temp+change_old;		
			flag_screen = 1;
			if(flag_screen == 1)
			{
				PCout(0) = 1;
				state_TW =T;
				data_temp = GetTemperature();
				state_TW = W;
				PCout(0) = 0;
				flag_temp= 0;	 
			}

/**************************************************�޸�ǰ��*****************************************************/
			//������־λ
			if((amp11_t>2)&&(amp11_t<xia_old))//
			{
				over_top = 1;
				//������޴���
				WRITE_HMI(0x111D,quantity_area.++quantity_area1);//д�봮����
			}
			if(amp11_t>shang_old)
			{
				below_bottom  = 1;
				//������޴���
				WRITE_HMI(0x1119,quantity_area.++quantity_area3);//д�봮����
			}
			else
			{
				//��Ӻϸ����
				WRITE_HMI(0x1115,quantity_area.++quantity_area2);//д�봮����
			}
/**************************************************************************************************************/			
			flag_moving=0;
		 }
		 else
			 {
				// amp11 = get_data_and_send_static();
				//amp = get_data_and_send_static();
				if(mms_temp>1000)
			 {
				  PCout(0) = 1;
				 state_TW =T;
				 data_temp = GetTemperature();
				 state_TW = W;
				 PCout(0) = 0;
				flag_temp= 0;
				 mms_temp=0;
			 }
		 }
			
		
	 
		 
	 }
	
	 EXTI_ClearITPendingBit(EXTI_Line6); //���LINE0�ϵ��жϱ�־λ  
}
 
void EXTI15_10_IRQHandler(void)
{
		if(EXTI_GetITStatus(EXTI_Line14)!= RESET)//yes or no inter interrupt	PB14	��������
 {
	 flag_moving=1;
		
		
 }
	
		
	EXTI_ClearITPendingBit(EXTI_Line14); //���LINE0�ϵ��жϱ�־λ  
}
 
