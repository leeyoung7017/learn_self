#ifndef _USART_OP_H_
#define _USART_OP_H_
#include "stm32f10x.h"

typedef enum{
	STR_UNEQUALS = 0,
	STR_EQUALS,
}StrIsEquals;



#define	UART_RX_BUFF_LEN		256

typedef struct{
	unsigned char Index;
	unsigned char pushIndex;
	unsigned char commdStart;
	unsigned char Buf[256];
}USART_BufDef;

#define	USART3_TxBufLen		1024
#define USART3_TxForAND		(USART3_TxBufLen - 1)
#define USART3_ReSend_Max	3

typedef struct{
	unsigned short Index;
	unsigned short pushIndex;
	unsigned short perindex;
	unsigned char waitforRet;
	unsigned char FbFlags;
	unsigned char reSendCnt;
	unsigned char Buf[USART3_TxBufLen];
}USART_TxBufDef;

/**************************************控件地址***************************************/
typedef struct{
	unsigned int name_addr;	//产品名地址
	unsigned int max_addr;	//上限地址
	unsigned int min_addr;	//下限地址
	unsigned int corr_addr; //修正系数地址
}Widget_ADDR;

typedef struct{
	unsigned int LOG_name_addr;
	unsigned int LOG_middle_addr;
	unsigned int LOG_max_addr;
	unsigned int LOG_min_addr;
	unsigned int LOG_time_addr;
}LOG_ADDR;

typedef struct{
	unsigned int year;
	unsigned int month;
	unsigned int day;
	unsigned int hour;
	unsigned int minute;
	unsigned int second;
}TIME;
/**************************************更新后*****************************************/


extern float origin;
extern int flag_state;
extern unsigned char over_top, below_bottom;
extern uint32_t tichu_old , keep_old ;
extern int change_old;
extern float line_m,line_b;
extern  int load_old ;
extern int flag_line ;
extern float shang_old ;
extern float xia_old;
extern  int F;
extern int flag_load ;
extern  float load_amp[16];
/********************************/
extern Widget_ADDR widget_addr;
extern int	flag_data,flag_name,flag_min,flag_max,flag_time,flag_save;
extern int flag_name_read,flag_test_para;
//extern uint32_t Data[120];
//extern uint32_t Data_test_para[4];

/********************************/
extern uint8_t Rx_Deal_Str[(uint16_t)(UART_RX_BUFF_LEN*0.9)];
unsigned char commdIsRec(USART_BufDef *DataStruct);
unsigned char commdIsRec_uart1(USART_BufDef *DataS);
unsigned long int Char_To_Int(unsigned char *nums,unsigned char len);
unsigned long int HexChar_To_int(unsigned char str[],unsigned char len);
StrIsEquals	str_compare(unsigned char* str1,unsigned char* str2,unsigned char lth);
void USART_RecDeal(USART_TypeDef *USARTxD);
void str_copy(unsigned char targ[], unsigned char source[], short len);
void write_log(unsigned int num_product);
void read_time(void);
void write_time(unsigned int num_product);
#endif //_USART_OP_H_


