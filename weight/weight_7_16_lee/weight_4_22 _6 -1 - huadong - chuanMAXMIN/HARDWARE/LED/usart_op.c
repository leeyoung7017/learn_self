#include "sys.h"
#include "usart_op.h"
#include <string.h>
#include <stdlib.h>
#include "master.h"
#include "relay.h"
#include "ad7191.h"
#include "usart_op.h"
uint8_t Rx_Deal_Str[(uint16_t)(UART_RX_BUFF_LEN*0.9)];
float value;
float  origin;
int F=0;
unsigned short CommIndex_Star = 0,UART_RecLen = 0;


/*****************************更新数据**************************/
static unsigned int num_product=0;
unsigned int name_addr=0,max_addr=0,min_addr=0,corr_addr=0; 
/*****************************更新数据**************************/

void getStr(unsigned char *pData,unsigned char offset ,unsigned char len)
{
	unsigned char cnt;
	for(cnt = 0; cnt < len; cnt ++)
	{
		Rx_Deal_Str[cnt] = pData[offset++];
		if(offset >= UART_RX_BUFF_LEN) offset = 0;
	}
}
void str_copy(unsigned char targ[], unsigned char source[], short len)
{
	short cnt = 0;
	for(cnt = 0; cnt < len; cnt ++){
		targ[cnt] = source[cnt];
	}
}

/*未曾用到*/
unsigned char commdIsRec(USART_BufDef *DataS)
{
	while(((*DataS).Index) != (*DataS).pushIndex){
		if(((*DataS).Buf[(*DataS).Index - 1] == '\r') && ((*DataS).Buf[(*DataS).Index] == '\n')){
			if(((int16_t)((*DataS).Index) - (*DataS).commdStart) < 0){
				UART_RecLen = (*DataS).Index + 256 - (*DataS).commdStart + 1;
			}else{
				UART_RecLen = (*DataS).Index - (*DataS).commdStart + 1;
			}
			getStr((*DataS).Buf,(*DataS).commdStart,UART_RecLen);
//			if(UART_RecLen != 6){
//				TxError_cnt1 ++;
//				
//			}
			(*DataS).Index ++;
//			if(UART_RxIndex >= UART_RX_BUFF_LEN) UART_RxIndex = 0;
			(*DataS).commdStart = (*DataS).Index;
			return 1;
		}
			(*DataS).Index ++;
			//if(UART_RxIndex >= UART_RX_BUFF_LEN) UART_RxIndex = 0;
	}
	return 0;
}

unsigned char commdIsRec_uart1(USART_BufDef *DataS)
{
	static int times = 0;
	while(((*DataS).Index) != (*DataS).pushIndex)
	{
		if(((*DataS).Buf[(*DataS).Index - 1] == 0x5a) && ((*DataS).Buf[(*DataS).Index] == 0xa5))	//判断前两个字节为5aa5
		{
			if(((int16_t)((*DataS).pushIndex) - (*DataS).Index) < 0)
			{
				UART_RecLen = (*DataS).pushIndex + 256 - (*DataS).Index + 1;
			}
			else
			{
				UART_RecLen = (*DataS).pushIndex - (*DataS).Index + 1;
			}
			if(UART_RecLen >= 11)
			{
				getStr((*DataS).Buf,(*DataS).Index - 1,11);
				(*DataS).Index ++;
				return 1;
			}
			else
			{
				times++;
				if(times >= 2000)
				{
					times = 0;
					(*DataS).Index = (*DataS).pushIndex;
				}
			}
			return 0;
		}
			(*DataS).Index ++;
			//if(UART_RxIndex >= UART_RX_BUFF_LEN) UART_RxIndex = 0;
	}
	return 0;
}

 
unsigned long int Char_To_Int(unsigned char *nums,unsigned char len)
{
	unsigned long int num = 0;
	int ten = 1,cnt;
	for(cnt = len; cnt > 0  ; cnt --){
		if(nums[cnt - 1] != ' '){
			num += (nums[cnt - 1] - 0x30) * ten;
			ten *=10;
		}else
			break;
		
	}
	return num;
}
unsigned long int HexChar_To_int(unsigned char str[],unsigned char len)
{
	unsigned char cnt = 0;
	unsigned long int temp = 0;
	for(cnt = 0; cnt < len; cnt ++){
		if(str[cnt] != ' '){
			if(str[cnt] > 96){
				temp += ((str[cnt] - 87) << ((len - cnt - 1)  * 4));
			}else if(str[cnt] > 64){
				temp += ((str[cnt] - 55) << ((len - cnt - 1) * 4));
			}else{
				temp += ((str[cnt] & 0x0f) << ((len - cnt - 1) * 4));
			}
		}
	}
	return temp;
}
//接收数据判断函数
StrIsEquals	str_compare(unsigned char* str1,unsigned char* str2,unsigned char lth)
{
	unsigned char sc_index;
	for(sc_index = 0; sc_index < lth; sc_index++)
	{
//		if(str1[sc_index] == str2[sc_index]){}
//		else	{return STR_UNEQUALS;} 
		
		if(str1[sc_index] != str2[sc_index]) return STR_UNEQUALS;
	}
	return STR_EQUALS;
}
unsigned char command_1[5] = {0x5a,0xa5,0x06,0x83,0x10};//启动/停止
unsigned char command_2[6] = {0x5a,0xa5,0x08,0x83,0x00,0x10};//皮带转速设置


/***************************************修改前后***********************************************/
unsigned char command_3[6] = {0x5a,0xa5,0x08,0x83,0x10,0x32};//下限
unsigned char command_4[6] = {0x5a,0xa5,0x08,0x83,0x10,0x34};//上限
unsigned char command_11[6] = {0x5a,0xa5,0x08,0x83,0x10,0x36};//修正系数
unsigned char command_13[6] = {0x5a,0xa5,0x08,0x83,0x10,0x30};//品名
/*******************************************************************************************/

unsigned char command_5[6] = {0x5a,0xa5,0x06,0x83,0x10,0x24};//清零
unsigned char command_7[6] = {0x5a,0xa5,0x08,0x83,0x20,0x14};//剔除延迟
unsigned char command_8[6] = {0x5a,0xa5,0x08,0x83,0x20,0x16};//动作保持
unsigned char command_6[6] = {0x5a,0xa5,0x08,0x83,0x10,0x18};//加载重量
unsigned char command_9[6] = {0x5a,0xa5,0x06,0x83,0x30,0x2A};//标定零点
unsigned char command_10[6] = {0x5a,0xa5,0x06,0x83,0x30,0x2C};//标加载重量
unsigned char command_12[6] = {0x5a,0xa5,0x08,0x83,0x20,0x20};//产品编号

enum state{state_on,state_off,state_ide}; 
enum speed {speed_0,speed_change};
int value_old = 0;
int tichu_old = 0;
int keep_old = 0;
int flag_state=0;
float line_m=0.0,line_b=0.0;
int load_old = 0;
int flag_line =0;
int flag_load = 0;
int change_old = 0;
unsigned char over_top = 0, below_bottom = 0;
static int Rx_flag = 0;
float shang_old = 0;
float xia_old= 0;
float sum_b=0,sum_m= 0;

int i_b=0,i_m= 0;

//串口接收数据处理
void USART_RecDeal(USART_TypeDef *USARTxD)
{	
	static unsigned char cnt = 0;
	unsigned char cnt_bl = 0;
	
	//串口2为485		检测到噪音、帧错误或校验错误
	if(USARTxD == USART2)
	{
		if(UART_RecLen > 7)			//UART_RecLen	接收数据长度
		{
			for(cnt = 0; cnt < UART_RecLen - 8; cnt ++)
			{
				if(str_compare(&Rx_Deal_Str[cnt],"CMD=",4)==STR_EQUALS ){	}
			}
		}	
	}
	
	if(USARTxD == USART1)
	{
		//变频器开启停止保持状态处理
		if(str_compare(&Rx_Deal_Str[cnt],command_1,5)==STR_EQUALS )
		{
			static enum state state_now,state_old = state_ide;
					
				//enum state state_now,state_old = state_ide;
			if(Rx_Deal_Str[8] == 0x01)
			{
			  state_now = state_off;
				flag_state = 1;
			}else if (Rx_Deal_Str[8] == 0x02){

				state_now = state_on;
				flag_state = 2;
			}else if (Rx_Deal_Str[8] == 0x00){
				state_now = state_ide;
				flag_state = 3;
			}
			if(state_now != state_old)
			{
				switch(state_now)
				{
					case state_on:
						WRITE_CF(0x31);
						break;
					case state_off:
						WRITE_CF(0x30);
						break;
					case state_ide:
						break;
					default:
						break;
				}	
			}
			state_old = state_now;
		}	
	//变频器转速处理
		if(str_compare(&Rx_Deal_Str[cnt],command_2,6)==STR_EQUALS )
		{  
			static int value_current = 0;
			value_current = Rx_Deal_Str[10];			//value_current 为int型，所占为32位，
			if(value_current != value_old)
			{
				if(Rx_Deal_Str[10] != 0x00){WRITE_CF_HZ(Rx_Deal_Str[10]);}
				else if(Rx_Deal_Str[10] == 0x00){}
				value_old = value_current ;
			}
			value_old = value_current;
		}
		
	//电磁阀动作处理
		if(str_compare(&Rx_Deal_Str[cnt],command_3,6)==STR_EQUALS )//上限xia
			{ 
				xia_old = (Rx_Deal_Str[9]<<8)|Rx_Deal_Str[10];
/************************************修改后***************************************************/
				/*需要实现数据上传*/
				WRITE_HMI(0x1123,xia_old);
/*********************************************************************************************/
				
			}
		if(str_compare(&Rx_Deal_Str[cnt],command_4,6)==STR_EQUALS )//下限shang
		{
			shang_old = (Rx_Deal_Str[9]<<8)|Rx_Deal_Str[10];
/************************************修改后***************************************************/
				/*需要实现数据上传*/
				WRITE_HMI(0x1125,shang_old);
/*********************************************************************************************/
		}
				
		//静态清零处理
		if(str_compare(&Rx_Deal_Str[cnt],command_5,6)==STR_EQUALS )
		{  if(Rx_Deal_Str[8]==0x01)
			 { 
				 origin = amp11_t;	 
			 }
		}
	//剔除延迟
		if(str_compare(&Rx_Deal_Str[cnt],command_7,6)==STR_EQUALS )
		{
			static int tichu_current = 0;
			tichu_current = Rx_Deal_Str[10];
			if(tichu_current != tichu_old){
			  
				tichu_old = tichu_current ;
				}
			tichu_old = tichu_current;
				tichu_old = tichu_old*10;
				
		}
		if(str_compare(&Rx_Deal_Str[cnt],command_8,6)==STR_EQUALS )
		{
			static int keep_current = 0;
			keep_current = Rx_Deal_Str[10];
			if(keep_current != keep_old){
			 
				keep_old = keep_current ;
				}
			keep_old = keep_current;
				keep_old=keep_old*10;
				
		}
		F= keep_old+tichu_old;
	
		//修正系数
		if(str_compare(&Rx_Deal_Str[cnt],command_11,6)==STR_EQUALS )
		{
			static int change_current = 0;
			change_current = Rx_Deal_Str[10];
			if(change_current != change_old){
			 
				change_old = change_current ;
				}
				change_old = change_current;
//				if(change_old>=100)
//				{change_old = change_old-100;}
//				else{change_old = 100-change_old;
//					change_old = -change_old;
//						}
				change_old = change_old-100;
				change_old =change_old;
			
	}

	
	
		//加载重量，校准曲线
		if(str_compare(&Rx_Deal_Str[cnt],command_9,6)==STR_EQUALS )
		{  
			if(Rx_Deal_Str[6]==0x01)
			{
				flag_line = 1;
				if (amp1 < 4.1)
				{
					while(i_b<16)
					{
						sum_b= load_amp[i_b]+sum_b;
						i_b++;
						
					}
					line_b = sum_b/16;
					
					sum_b= 0;
					i_b = 0;
				}
			}
		}
		if(str_compare(&Rx_Deal_Str[cnt],command_6,6)==STR_EQUALS )
		{

			static int load_weight = 0;
			
			load_weight = Rx_Deal_Str[10];
			if(load_weight != load_old)
			{
				load_old = load_weight ;
			}
			load_old = load_weight;
		}
		if(str_compare(&Rx_Deal_Str[cnt],command_10,6)==STR_EQUALS )
		{
					while(i_m<16)
					{
						sum_m= load_amp[i_m]+sum_m;
						i_m++;
					}
					line_m = sum_m/16;
				
					sum_m=0;
					i_m=0;
					flag_load = 1;
		}
/***************************************修改后*******************************************************/
		/*载入产品*/
		if(str_compare(&Rx_Deal_Str[cnt],command_12,6)==STR_EQUALS )/*编号*/
		{
						
			num_product = Rx_Deal_Str[10];			//载入产品号地址
			name_addr = (num_product-1)*8+0x1130;	//品名地址
			min_addr = (num_product-1)*8+0x1130+2;	//下限地址
			max_addr = (num_product-1)*8+0x1130+4;	//上限地址
			corr_addr = (num_product-1)*8+0x1130+6;	//修正系数地址

			//下限
			command_3[4]=(min_addr>>8)&0xFF;;
			command_3[5]=min_addr&0xFF;
			//上限
			command_4[4]= (max_addr>>8)&0xFF;	
			command_4[5]=max_addr&0xFF;
			//修正系数
			command_11[4]=(corr_addr>>8)&0xFF;		
			command_11[5]=corr_addr&0xFF;
			//品名
			command_13[4]=(name_addr>>8)&0xFF;
			command_13[5]=name_addr&0xFF;
			
			if(num_product<=25)
			{
				/*获取所在产品名、上限、下限、修正系数*/
				READ_HMI(name_addr,0x02);	//品名
				READ_HMI(min_addr,0x02);	//读取下限
				READ_HMI(max_addr,0x02);	//读取上限
				READ_HMI(corr_addr,0x02);	//读取修正系数
			}
		}
		if(str_compare(&Rx_Deal_Str[cnt],command_13,6)==STR_EQUALS)/*品名*/
		{
			int name_product;
			name_product = (Rx_Deal_Str[9]<<8)|Rx_Deal_Str[10];
			//品名上位机传输
			WRITE_HMI(0x111F,name_product);
		}
		
	}
/***************************************修改后*******************************************************/
}
	
	
