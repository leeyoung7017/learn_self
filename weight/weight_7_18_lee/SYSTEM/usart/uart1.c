#include "sys.h"
#include "stdio.h"
#include "uart1.h"	
#include "usart.h"	
#include "usart_op.h"
#include"master.h"
 unsigned char 	USART1SendBuf[256];
 unsigned char	USART1SendBufLen = 0;
 unsigned char  USART1RecieveBuf[256];     	//接收缓冲
 unsigned char	USART1RecieveBufLen = 0; 	//接收到的数据长度	  
 USART_BufDef USART1_Tx;
 USART_BufDef USART1_Rec;


void uart1_init(u32 bound){
    //GPIO端口设置
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(USART_APBCLK|RCC_APB2Periph_GPIOA, ENABLE);	//使能USART1，GPIOA时钟
 	USART_DeInit(USART1);  //复位串口1
  //USART1_TX   PA.9
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
	GPIO_Init(GPIOA, &GPIO_InitStructure); //初始化PA9
 
	//USART1_RX	  PA.10
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
	GPIO_Init(GPIOA, &GPIO_InitStructure);  //初始化PA10

  //Usart1 NVIC 配置
	NVIC_InitStructure.NVIC_IRQChannel = USARTx_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
  
   //USART 初始化设置

	USART_InitStructure.USART_BaudRate = bound;//一般设置为9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式

	USART_Init(USARTx1, &USART_InitStructure); //初始化串口
	USART_ITConfig(USARTx1, USART_IT_RXNE, ENABLE);//开启中断
	USART_Cmd(USARTx1, ENABLE);                    //使能串口 

}



//串口1发送函数
void USART1_Push(unsigned char* str,unsigned char lth) 
{
	unsigned char push_index = 0;
	for(push_index = 0; push_index < lth; push_index++){
		USART1_Tx.Buf[USART1_Tx.pushIndex++] = str[push_index];
	}
	USART_ITConfig(USARTx1,USART_IT_TC,ENABLE);
}

//读串口屏存储器地址函数
void READ_HMI(u16 address,u8 lenth)
{
	USART1SendBuf[0]=0x5a;
	USART1SendBuf[1]=0xa5;
	USART1SendBuf[2]=0x04;
	USART1SendBuf[3]=0x83;
	
	//2字节的地址	
	USART1SendBuf[4]=((address>>8)&0xff);
	USART1SendBuf[5]=(address&0xff);
	
	//读取长度 字长度
	USART1SendBuf[6]=lenth;//01
	USART1_Push(USART1SendBuf,7);
}

/************************************修改后*****************************************/
/*数据传输到串口屏*/
void WRITE_HMI(u16 address,float data)
{	
	unsigned char *printbuf;
	unsigned char *data_print;
	unsigned char *pp;
	int length = 0;

	printbuf = (unsigned char *) calloc (40,sizeof(unsigned char));
	data_print = (unsigned char *) calloc (20,sizeof(unsigned char));
	pp = (unsigned char *) calloc (40,sizeof(unsigned char));

	sprintf((char *)data_print,"%.1f\r\n",data);
	length = deal_num(pp,data_print);
	USART3_Push(data_print,length);       //调试串口
	printbuf[0] = 0x5a;
	printbuf[1] = 0xa5;
	printbuf[2] = length + 3;
	printbuf[3] = 0x82;
	printbuf[4] = (address & 0xff00) >> 8;
	printbuf[5] = (address & 0x00ff);
	memcpy((printbuf + 6),pp,length);
	USART1_Push(printbuf,length + 6);    //RS232给串口屏
	free(data_print);
	free(printbuf);
	free(pp);
}
/*******************************************************************************************/


//串口1中断服务程序
void USARTx_IRQHandler(void)                	//串口1中断服务程序
{
		
	if(USART_GetITStatus(USARTx1, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
{
		USART1_Rec.Buf[USART1_Rec.pushIndex++] =USART_ReceiveData(USARTx1);//(USART1->DR);	//读取接收到的数据				USART1_Rec.pushIndex++		
			
	
		if(commdIsRec_uart1(&USART1_Rec) == 1)
		{
			USART_RecDeal(USART1);   //数据处理
		}
//		while(USART_GetFlagStatus(USARTx1,USART_FLAG_TXE ) != SET );
//			USART_SendData(USARTx1,USART1_Tx.Buf[USART1_Tx.Index++]);
//		while(USART_GetFlagStatus(USARTx1,USART_FLAG_TC ) != SET );
			
		}
	if(USART_GetITStatus(USARTx1,USART_IT_TC) != RESET){
		if(USART1_Tx.Index != USART1_Tx.pushIndex){
			USART_SendData(USARTx1,USART1_Tx.Buf[USART1_Tx.Index++]);
	
			
		}else{                                                
			USART_ITConfig(USARTx1,USART_IT_TC,DISABLE);
		}
	
	}

}
			
				

 //void USART1_Receive(unsigned char *buf,unsigned char *len)
//{
//	u8 rxlen= USART1RecieveBufLen;
//	u8 i=0;
//	*len=0;				//默认为0
//	delay_ms(10);		//等待10ms,连续超过10ms没有接收到一个数据,则认为接收结束
//	if(rxlen==USART1RecieveBufLen&&rxlen)//接收到了数据,且接收完成了
//	{
//		for(i=0;i<rxlen;i++)
//		{
//			buf[i]=USART1RecieveBuf[i];	
//		}		
//		*len=USART1RecieveBufLen;	//记录本次数据长度
//		USART1RecieveBufLen=0;		//清零
//	}
//}






