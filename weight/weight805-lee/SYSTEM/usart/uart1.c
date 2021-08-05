#include "sys.h"
#include "stdio.h"
#include "uart1.h"	
#include "usart.h"	
#include "ad7191.h"
#include "usart_op.h"
#include"master.h"
 unsigned char 	USART1SendBuf[256];
 unsigned char	USART1SendBufLen = 0;
 unsigned char  USART1RecieveBuf[256];     	//���ջ���
 unsigned char	USART1RecieveBufLen = 0; 	//���յ������ݳ���	  
 USART_BufDef USART1_Tx;
 USART_BufDef USART1_Rec;


void uart1_init(u32 bound){
    //GPIO�˿�����
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(USART_APBCLK|RCC_APB2Periph_GPIOA, ENABLE);	//ʹ��USART1��GPIOAʱ��
 	USART_DeInit(USART1);  //��λ����1
  //USART1_TX   PA.9
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
	GPIO_Init(GPIOA, &GPIO_InitStructure); //��ʼ��PA9
 
	//USART1_RX	  PA.10
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
	GPIO_Init(GPIOA, &GPIO_InitStructure);  //��ʼ��PA10

  //Usart1 NVIC ����
	NVIC_InitStructure.NVIC_IRQChannel = USARTx_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
  
   //USART ��ʼ������

	USART_InitStructure.USART_BaudRate = bound;//һ������Ϊ9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ

	USART_Init(USARTx1, &USART_InitStructure); //��ʼ������
	USART_ITConfig(USARTx1, USART_IT_RXNE, ENABLE);//�����ж�
	USART_Cmd(USARTx1, ENABLE);                    //ʹ�ܴ��� 

}



//����1���ͺ���
void USART1_Push(unsigned char* str,unsigned char lth) 
{
	unsigned char push_index = 0;
	for(push_index = 0; push_index < lth; push_index++){
		USART1_Tx.Buf[USART1_Tx.pushIndex++] = str[push_index];
	}
	USART_ITConfig(USARTx1,USART_IT_TC,ENABLE);
}

//���������洢����ַ����
void READ_HMI(u16 address,u8 lenth)
{
	USART1SendBuf[0]=0x5a;
	USART1SendBuf[1]=0xa5;
	USART1SendBuf[2]=0x04;
	USART1SendBuf[3]=0x83;
	
	//2�ֽڵĵ�ַ	
	USART1SendBuf[4]=((address>>8)&0xff);
	USART1SendBuf[5]=(address&0xff);
	
	//��ȡ���� �ֳ���
	USART1SendBuf[6]=lenth;//01
	USART1_Push(USART1SendBuf,7);
	delay_ms(10);
//	free(USART1SendBuf);
}

/************************************�޸ĺ�*****************************************/
/*���ݴ��䵽������*/
void WRITE_HMI(uint16_t address,float data,int hex)
{	
	unsigned char *printbuf;
	unsigned char *data_print;
	unsigned char *pp;
	int length = 0;
	float data_st;
	data_st = data;

	printbuf = (unsigned char *) calloc (40,sizeof(unsigned char));
	data_print = (unsigned char *) calloc (20,sizeof(unsigned char));
	pp = (unsigned char *) calloc (40,sizeof(unsigned char));

/************************�ж�data�Ƿ�Ϊ����***************************/
	if((data == (int)data)&&(hex == 0))
	{
		sprintf((char *)data_print,"%d\r\n",(int)data);
	}
	else if((data == (float)data)&&(hex == 0))
	{
		sprintf((char *)data_print,"%.1f\r\n",data_st);
	}
	else if(hex)
	{
		sprintf((char *)data_print,"%x\r\n",data);
	}
/*****************************��ʵ����********************************/

	length = deal_num(pp,data_print);
//	USART3_Push(data_print,length);       //���Դ���
	printbuf[0] = 0x5a;
	printbuf[1] = 0xa5;
	printbuf[2] = length + 3;
	printbuf[3] = 0x82;//82
	printbuf[4] = (address & 0xff00) >> 8;
	printbuf[5] = (address & 0x00ff);
	memcpy((printbuf + 6),pp,length);
	USART1_Push(printbuf,length + 6);    //RS232��������
	free(data_print);
	free(printbuf);
	free(pp);
}

void WRITE_HMI_Data(uint16_t address,uint32_t data)
{
	unsigned char *printbuf;
	
	printbuf = (unsigned char *) calloc (40,sizeof(unsigned char));
	
	printbuf[0] = 0x5a;
	printbuf[1] = 0xa5;
	printbuf[2] = 7;
	printbuf[3] = 0x82;//82
	printbuf[4] = (address & 0xff00) >> 8;
	printbuf[5] = (address & 0x00ff);
	printbuf[6] = (data>>24)&0xff;
	printbuf[7] = (data>>16)&0xff;
	printbuf[8] = (data>>8)&0xff;
	printbuf[9] = data&0xff;
	USART1_Push(printbuf,10);    //RS232��������

	free(printbuf);
}

void Beep_Config(unsigned int time_10ms)
{

	USART1SendBuf[0]=0x5a;
	USART1SendBuf[1]=0xa5;
	USART1SendBuf[2]=0x03;
	USART1SendBuf[3]=0x80;
	
	//2�ֽڵĵ�ַ	
	USART1SendBuf[4]=0x02;
	USART1SendBuf[5]=time_10ms;
	
	USART1_Push(USART1SendBuf,6);
//	free(USART1SendBuf);/*????????*/
}

/*******************************************************************************************/


//����1�жϷ������
void USARTx_IRQHandler(void)                	//����1�жϷ������
{
		
	if(USART_GetITStatus(USARTx1, USART_IT_RXNE) != RESET)  //�����ж�(���յ������ݱ�����0x0d 0x0a��β)
	{
		USART1_Rec.Buf[USART1_Rec.pushIndex++] =USART_ReceiveData(USARTx1);//(USART1->DR);	//��ȡ���յ�������				USART1_Rec.pushIndex++		
			
	
		if(commdIsRec_uart1(&USART1_Rec) == 1)
		{
			TIM_Cmd(TIM2,DISABLE);
			USART_RecDeal(USART1);   //���ݴ���
			TIM_Cmd(TIM2,ENABLE);
		}
//		USART_ClearITPendingBit(USARTx1,USART_IT_RXNE);	
	}
	if(USART_GetFlagStatus(USARTx1,USART_FLAG_ORE) != RESET)
	{
		USART_ReceiveData(USARTx1);
		USART_ClearFlag(USARTx1,USART_FLAG_ORE);
	}
	if(USART_GetITStatus(USARTx1,USART_IT_TC) != RESET)
	{
//		USART_ClearITPendingBit(USARTx1,USART_IT_TC);	
		if(USART1_Tx.Index != USART1_Tx.pushIndex)
		{
			USART_SendData(USARTx1,USART1_Tx.Buf[USART1_Tx.Index++]);	
		}
		else
		{                                                
			USART_ITConfig(USARTx1,USART_IT_TC,DISABLE);
		}
	

	}
	

}
			
				






