#include "sys.h"
#include "usart_op.h"
#include <string.h>
#include <stdlib.h>
#include "master.h"
#include "exti.h"
#include "relay.h"
#include "ad7191.h"
#include "usart_op.h"
#include "flash.h"
#include "timer.h"
#include "hmi.h"

uint8_t Rx_Deal_Str[(uint16_t)(UART_RX_BUFF_LEN*0.9)];//230
float value;
float  origin;
int F=0;
unsigned short CommIndex_Star = 0,UART_RecLen = 0;
 float load_amp[16];

/*****************************更新数据**************************/
static unsigned int num_product=0;
unsigned int num_product1 = 0;
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
//unsigned char commdIsRec(USART_BufDef *DataS)
//{
//	while(((*DataS).Index) != (*DataS).pushIndex){
//		if(((*DataS).Buf[(*DataS).Index - 1] == '\r') && ((*DataS).Buf[(*DataS).Index] == '\n')){
//			if(((int16_t)((*DataS).Index) - (*DataS).commdStart) < 0){
//				UART_RecLen = (*DataS).Index + 256 - (*DataS).commdStart + 1;
//			}else{
//				UART_RecLen = (*DataS).Index - (*DataS).commdStart + 1;
//			}
//			getStr((*DataS).Buf,(*DataS).commdStart,UART_RecLen);
////			if(UART_RecLen != 6){
////				TxError_cnt1 ++;
////				
////			}
//			(*DataS).Index ++;
////			if(UART_RxIndex >= UART_RX_BUFF_LEN) UART_RxIndex = 0;
//			(*DataS).commdStart = (*DataS).Index;
//			return 1;
//		}
//			(*DataS).Index ++;
//			//if(UART_RxIndex >= UART_RX_BUFF_LEN) UART_RxIndex = 0;
//	}
//	return 0;
//}

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
unsigned char command_7[6] = {0x5a,0xa5,0x08,0x83,0x20,0x14};//剔除延迟
unsigned char command_8[6] = {0x5a,0xa5,0x08,0x83,0x20,0x16};//动作保持

/***************************************修改前后***********************************************/
unsigned char command_3[6] = {0x5a,0xa5,0x08,0x83,0x10,0x32};//下限
unsigned char command_4[6] = {0x5a,0xa5,0x08,0x83,0x10,0x34};//上限
unsigned char command_11[6] = {0x5a,0xa5,0x08,0x83,0x10,0x36};//修正系数
unsigned char command_13[6] = {0x5a,0xa5,0x08,0x83,0x10,0x30};//品名
unsigned char command_14[6] = {0x5a,0xa5,0x0a,0x81,0x20,0x07};//实时时间
unsigned char command_15[6] = {0x5a,0xa5,0x06,0x83,0x20,0x22};//产品编辑保存按钮
unsigned char command_16[6] = {0x5a,0xa5,0x08,0x83,0x11,0x30};//产品编辑数据获取
unsigned char command_17[6] = {0x5a,0xa5,0x06,0x83,0x05,0x00};//产品编辑数据初始化
unsigned char command_18[6] = {0x5a,0xa5,0x06,0x83,0x00,0x20};//参数设置保存按钮“确定”
/*******************************************************************************************/

unsigned char command_5[6] = {0x5a,0xa5,0x06,0x83,0x10,0x24};//清零
unsigned char command_6[6] = {0x5a,0xa5,0x08,0x83,0x10,0x18};//加载重量
unsigned char command_9[6] = {0x5a,0xa5,0x06,0x83,0x30,0x2A};//标定零点
unsigned char command_10[6] = {0x5a,0xa5,0x06,0x83,0x30,0x2C};//标加载重量
unsigned char command_12[6] = {0x5a,0xa5,0x08,0x83,0x20,0x20};//产品编号


enum state{state_on,state_off,state_ide}; 
enum speed {speed_0,speed_change};
uint32_t value_old = 0;
uint32_t tichu_old = 0;
uint32_t keep_old = 0;
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
Widget_ADDR widget_addr;
LOG_ADDR log_addr;
TIME time_now;
int	flag_data,flag_name,flag_min,flag_max,flag_time,flag_save;
int flag_name_read,flag_test_para;
int name_product;
extern uint32_t Data_pro_edit[180];
//extern uint32_t Data_test_para[4];

//串口接收数据处理
void USART_RecDeal(USART_TypeDef *USARTxD)
{	
	static unsigned char cnt = 0;
	unsigned char cnt_bl = 0;
//	static uint8_t i=0;
	static int i = 0;
	
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
			static uint32_t value_current = 0;
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
		if(str_compare(&Rx_Deal_Str[cnt],command_4,6)==STR_EQUALS )//上限xia
		{ 
//			static float xia_old1 = 0;
			xia_old = (Rx_Deal_Str[9]<<8)|Rx_Deal_Str[10];
/************************************修改后***************************************************/
//			if(xia_old != xia_old1)
//			{
				/*需要实现数据上传*/
				WRITE_HMI_Data(0x2711,xia_old);
				delay_ms(10);
//				xia_old1 = xia_old;
//			}
			flag_max = 1;
/*********************************************************************************************/
			
		}
		if(str_compare(&Rx_Deal_Str[cnt],command_3,6)==STR_EQUALS )//下限shang
		{
//			static float shang_old1 = 0;
			shang_old = (Rx_Deal_Str[9]<<8)|Rx_Deal_Str[10];
/************************************修改后***************************************************/
//			if(shang_old != shang_old1)
//			{				
				/*需要实现数据上传*/
				WRITE_HMI_Data(0x2811,shang_old);
				delay_ms(10);
//				shang_old1 = shang_old;
//			}
			flag_min = 1;
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
			static uint32_t tichu_current = 0;
			tichu_current = Rx_Deal_Str[10];
			if(tichu_current != tichu_old){
			  
				tichu_old = tichu_current ;
				}
			tichu_old = tichu_current;
				tichu_old = tichu_old*10;
				
				
				
		}
		
		if(str_compare(&Rx_Deal_Str[cnt],command_8,6)==STR_EQUALS )
		{
			static uint32_t keep_current = 0;
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
			if(change_current != change_old)
			{
				change_old = change_current ;
			}
			change_old = change_current;
			
			change_old = change_old-100;
			change_old =change_old;
			flag_name = 1;
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
			num_product = Rx_Deal_Str[10];			//载入产品号数据
			/*实现判断产品号是否更新*/
			if(num_product1 != num_product)
			{
				char i;
				flag_data = 1;
				flag_time = 1;
				
				/*切换产品号将数据显示清零*/
				for(i = 0;i<6;i++)
				{
					WRITE_HMI_Data(0x2111+i*0x100,0);
					delay_ms(10);
				}
				/***********************************************/
				/*存储编号、时间与数量*/
				if(num_product1!=0)
				{
					write_log(num_product1);/*写编号、数量*/	
				}

				/************************************************/
				
			} 
			
			widget_addr.name_addr = (num_product-1)*8+0x1130;	//品名地址
			widget_addr.min_addr = (num_product-1)*8+0x1130+2;	//下限地址
			widget_addr.max_addr = (num_product-1)*8+0x1130+4;	//上限地址
			widget_addr.corr_addr = (num_product-1)*8+0x1130+6;	//修正系数地址

			//更新地址
			command_3[4]=(widget_addr.min_addr>>8)&0xFF;//下限
			command_3[5]=widget_addr.min_addr&0xFF;

			command_4[4]= (widget_addr.max_addr>>8)&0xFF;//上限
			command_4[5]=widget_addr.max_addr&0xFF;
			
			command_11[4]=(widget_addr.corr_addr>>8)&0xFF;//修正系数
			command_11[5]=widget_addr.corr_addr&0xFF;
			
			command_13[4]=(widget_addr.name_addr>>8)&0xFF;//品名
			command_13[5]=widget_addr.name_addr&0xFF;
			
		}
		if((flag_name_read==0)&&(str_compare(&Rx_Deal_Str[cnt],command_13,6)==STR_EQUALS))/*品名*/
		{
			
			flag_name = 1;
			name_product = (Rx_Deal_Str[9]<<8)|Rx_Deal_Str[10];
			//品名上位机传输
			WRITE_HMI_Data(0X2B11,name_product);
			delay_ms(10);
		}
		if(str_compare(&Rx_Deal_Str[cnt],command_14,6)==STR_EQUALS)/*时间*/
		{
			time_now.year = Rx_Deal_Str[6];
			time_now.month = Rx_Deal_Str[7];
			time_now.day = Rx_Deal_Str[8];
			time_now.hour = Rx_Deal_Str[10];
			if(num_product1 !=0)
			{
				write_time(num_product1);
				/*清空数量与重量*/
				quality_area.quality_area1 = 0;
				quality_area.quality_area2 = 0;
				quality_area.quality_area3 = 0;
				quantity_area.quantity_area1 = 0;
				quantity_area.quantity_area2 = 0;
				quantity_area.quantity_area3 = 0;	
			}
			num_product1 = num_product;
		}
		if(str_compare(&Rx_Deal_Str[cnt],command_15,6)==STR_EQUALS)/*保存按钮*/
		{
			 
			//按钮按下进入
			//实现读取功能；使用标志位
			if(Rx_Deal_Str[8] == 0x01)
			{
				/*添加标志位，使得在特定情况下进行数据保存*/
					flag_name_read = 1;
					index_edit = 0;
					command_16[4] = 0x11;
					command_16[5] = 0x30;
	
	
			}	
		}

		if((flag_name_read)&&(str_compare(&Rx_Deal_Str[cnt],command_16,6)==STR_EQUALS))/*产品编辑保存*/
		{
			int index;
			int addr_pro_edit;
			if(index_edit == 0)
			{
				memset(Data_pro_edit,0,180);
			}
			addr_pro_edit = (command_16[4]<<8)+command_16[5]+2;
			command_16[4] = (addr_pro_edit>>8)&0xff;
			command_16[5] = addr_pro_edit&0xff;
			Data_pro_edit[index_edit] = (Rx_Deal_Str[7]<<24)|(Rx_Deal_Str[8]<<16)|(Rx_Deal_Str[9]<<8)|(Rx_Deal_Str[10]);
			index_edit++;
			if(index_edit == 120)
			{
				i = 0;
				flag_name_read = 0;
				index_edit = 0;
				command_16[4] = 0x11;
				command_16[5] = 0x30;
				/*速度保存*/
				Data_pro_edit[120] = value_old;
				/*剔除时间保存*/
				Data_pro_edit[122] = (uint32_t)tichu_old/10;
				/*保持时间保存*/
				Data_pro_edit[123] = (uint32_t)keep_old/10;
				/*数据存储数据*/
				flash_save(Data_pro_edit,180);
				/*需要在串口屏上显示数据保存完成*/
				Beep_Config(100);/*蜂鸣器1s*/
			}

		}
		
		if(str_compare(&Rx_Deal_Str[cnt],command_17,6)==STR_EQUALS)/*产品编辑初始化*/
		{
			static uint32_t flag1 = 1,flag2 = 1,flag3 = 1,flag4 = 1,flag5 = 1,flag6 = 1,flag7 = 1;
			
			if((Rx_Deal_Str[8] == 0x01)&&flag1)
			{
				pro_edit_filled(Data_pro_edit,20,0x1130);
				flag1 = 0;
			}
			else if((Rx_Deal_Str[8] == 0x02)&&flag2)
			{
				pro_edit_filled(Data_pro_edit,20,0x1158);
				flag2 = 0;
			}
			else if((Rx_Deal_Str[8] == 0x03)&&flag3)
			{
				pro_edit_filled(Data_pro_edit,20,0x1180);
				flag3 = 0;
			}
			else if((Rx_Deal_Str[8] == 0x04)&&flag4)
			{
				pro_edit_filled(Data_pro_edit,20,0x11A8);
				flag4 = 0;

			}
			else if((Rx_Deal_Str[8] == 0x05)&&flag5)
			{
				pro_edit_filled(Data_pro_edit,20,0x11D0);
				flag5 = 0;

			}
			else if((Rx_Deal_Str[8] == 0x06)&&flag6)
			{
				pro_edit_filled(Data_pro_edit,20,0x11F8);
				flag6 = 0;
			}
			else if((Rx_Deal_Str[8] == 0x07)&&flag7)
			{
				static int i = 1;
				log_filled(Data_pro_edit+116+i*8,8,0x1212+i*0x10);
				if(i%7 == 0)
				{
					flag7 = 0;
				}
				i++;
			}
		}
		if(str_compare(&Rx_Deal_Str[cnt],command_18,6)==STR_EQUALS)/*写入检测参数*/
		{
			if(Rx_Deal_Str[8] == 0x01)
			{
				static int i = 1;
				if(i)
				{
					test_para_filled(Data_pro_edit+120,4);
					i=0;
				}
			}	
		}
/***************************************修改后*******************************************************/
	}
}

	
void write_log(unsigned int num_product)
{
	int i;
	
	/*日志控件地址*/
	log_addr.LOG_name_addr = (num_product-1)*0x10+0x1222;
	log_addr.LOG_middle_addr = (num_product-1)*0x10+0x122C;
	log_addr.LOG_min_addr = (num_product-1)*0x10+0x122E;
	log_addr.LOG_max_addr = (num_product-1)*0x10+0x1230;
	
	
	
	
	WRITE_HMI_Data(log_addr.LOG_name_addr,name_product);
	delay_ms(10);
	WRITE_HMI_Data(log_addr.LOG_middle_addr,quantity_area.quantity_area2);//合格
	delay_ms(10);	
	WRITE_HMI_Data(log_addr.LOG_min_addr,quantity_area.quantity_area1);//不合格1
	delay_ms(10);	
	WRITE_HMI_Data(log_addr.LOG_max_addr,quantity_area.quantity_area3);//不合格2
	delay_ms(10);
	
	
	i = (num_product - 1)*8 + 124;
	Data_pro_edit[i] = name_product;
	Data_pro_edit[i+5] = quantity_area.quantity_area2;
	Data_pro_edit[i+6] = quantity_area.quantity_area1;
	Data_pro_edit[i+7] = quantity_area.quantity_area3;
}

/*5A A5 03 81 20 07*/
void read_time(void)
{
	USART1SendBuf[0]=0x5a;
	USART1SendBuf[1]=0xa5;
	USART1SendBuf[2]=0x03;
	USART1SendBuf[3]=0x81;
	
	//2字节的地址	
	USART1SendBuf[4]=0x20;
	USART1SendBuf[5]=0x07;
	
	USART1_Push(USART1SendBuf,6);
}	
void write_time(unsigned int num_product)
{
	unsigned char *printbuf;
	uint32_t data;
	int i = 0,j=0;
	uint32_t addr = (num_product-1)*16+0x1224-2;
	
	printbuf = (unsigned char *) calloc (40,sizeof(unsigned char));	
	

	printbuf[0] = 0x5a;
	printbuf[1] = 0xa5;
	printbuf[2] = 0x07;
	printbuf[3] = 0x82;//82
	
	j = (num_product-1)*8 +124;
	for(i=0;i<4;i++)
	{
		addr += 2;
		printbuf[4] = (addr & 0xff00) >> 8;
		printbuf[5] = (addr & 0x00ff);				
		switch(i)
		{
			case 0:
				data = time_now.year - (uint32_t)((time_now.year>>4)*6);
				break;
			case 1:
				data = time_now.month - (uint32_t)((time_now.month>>4)*6);
				break;
			case 2:
				data = time_now.day - (uint32_t)((time_now.day>>4)*6);
				break;
			case 3:
				data = time_now.hour - (uint32_t)((time_now.hour>>4)*6);
				break;
			default:
				break;
		}	
		printbuf[6] = (data>>24)&0xff;
		printbuf[7] = (data>>16)&0xff;
		printbuf[8] = (data>>8)&0xff;
		printbuf[9] = data&0xff;
		USART1_Push(printbuf,10);    //RS232给串口屏
		delay_ms(10);
		Data_pro_edit[j+i+1] = data;
	}

	
	free(printbuf);
}
