#include "ad7191.h"
#include "FlagDeal.h"
#include "math.h"
#include "usart_op.h"
unsigned int data;

float amp;
float amp_ad;
float amp_v;
float amp1;
float amp11;
float amp11_t;

float er=0,amp_pre=0 ,amp_pre_1 = 0,er_1=0,er_2=0;
float arr[50];

//float A_BUFF[66];
int flag_count = 1;
 int flag_t=1 ; 
	unsigned int data_1;
	unsigned char flag_temp= 0;
	float data_temp=0;
	 float  sum_s= 0;
 //int i_count=0;
 int x_count = 0;
 int A_BUFF[N];
 /*int A_BUFF[N]={9285958,9285933,9285985,9285925,9286005,9285897
,9286004
,9285900
,9286017
,9285888
,9286038
,9285901
,9286008
,9285894
,9285995
,9285958};*/
float load_amp[16];

//AD7191引脚初始化
void AD7191_gpio_Configuration()
{
 
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOA, ENABLE );//PORTB时钟使能  	 	
	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOB, ENABLE );
	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOC, ENABLE );


	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4  | GPIO_Pin_5 | GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //PB13/14/15复用推挽输出 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOB

 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  //PA5/6/7复用推挽输出 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOb
	
 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_5;//CHANNAL
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //PA5/6/7复用推挽输出 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIOb
	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//ODR1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //PA5/6/7复用推挽输出 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOb
	
	PAout(5) = 1;
}
//开启AD
void ad7191_on()
{
	pw_on;
	delay_ms(80);
}
//关闭AD
void ad7191_off()
{
	pw_down;
	delay_ms(80);
}
//AD读出数据
unsigned int read_data_from_ad7191()
{
	char i;
	unsigned int  data = 0;
	for (i = 0; i < 24; i++){
		PAout(5) = 0;
		data = data << 1;
		data |= PAin(6);
		PAout(5) = 1;
		//delay_us(1);
	}
	return data;
}
//选择AD通道
void sellect_channal(int channal)
{
	if(channal == 1)
		ad7191_channal1(0);
	else
		ad7191_channal1(1);
}
//设置AD输出速率
void set_rate(enum rate_switch rate)
{
	switch (rate){
		case rate_10://11
			ad7191_odr1(1);
			ad7191_odr2(1);
			break;
		case rate_50://01
			ad7191_odr1(0);
			ad7191_odr2(1);
			break;
		case rate_60://00
			ad7191_odr1(0);
			ad7191_odr2(0);
			break;
		case rate_120://10
			ad7191_odr1(1);
			ad7191_odr2(0);
			break;
		default://01
			ad7191_odr1(0);
			ad7191_odr2(1);
			break;
	}
}
//设置PGA增益
void set_gain(enum gain_switch gain)
{
	switch (gain){
		case  gain_1://00
			ad7191_gain1(0);
			ad7191_gain2(0);
			break;
		case gain_8://10
			ad7191_gain1(1);
			ad7191_gain2(0);
			break;
		case gain_64://01
			ad7191_gain1(0);
			ad7191_gain2(1);
			break;
		case gain_128://11
			ad7191_gain1(1);
			ad7191_gain2(1);
			break;
		default://00
			ad7191_gain1(0);
			ad7191_gain2(0);
			break;

	}
}
//内部温度传感器选择
void select_tem(unsigned char tmp_select)
{
	if(tmp_select == INPUT){
		ad7191_temp(0);
	}else if(tmp_select == TEMP){
		ad7191_temp(1);
	}else{
		ad7191_temp(0);
	}
}	


//选择时钟来源（外部或内部）
void select_IN_OR_EX(unsigned char in_or_ex_select)
{
	if(in_or_ex_select == INTERNAL){
		ad7191_clksel(1);
	}else if(in_or_ex_select == EXTERNAL){
		ad7191_clksel(0);
	}else{
		ad7191_clksel(1);
	}
}
//开机前取平均
float average = 0;
unsigned char initflag = 0;
float average_ad()
{	
	unsigned	int data;
	static float amp = 0;
	static int i = 0;
	if(i < 100){
		while(PAin(6) == 1){
			;
		}
		data = read_data_from_ad7191();
		amp +=(float)((data)-8388608)*4.82/(128*8388608)*1000;
		i++;
		return 0;
	}else{
		amp /= 100;
		return amp;
	}
}
void average_deal(void)
{
	if( (average = average_ad()) != 0)
			initflag = 1;
}

//限幅滤波法
float filter_AD()
{
  float new_value;
	new_value = read_data_from_ad7191();	
  if ((new_value>1)&&(((new_value - amp)>=A)||((amp - new_value)>=A)) )
		return amp;
	else 
		return new_value;
}


//平均值内滤波法
unsigned long	GetValueMidTui()
{
	/*static int sum_s= 0;
  static int data1 =0;
	static int i_icount=0;
	static int  a[N];
	static int b[N];
	static int j1=0;
	static int  d =0 ;
	
	while(PAin(6) == 1){
		;
	}
  data1 = read_data_from_ad7191();

	if (flag_count==1)
	{
			for(i_icount=0;i_icount < N;i_icount++)				
						{
									a[i_icount] = data1;
								sum_s = sum_s + data1;	
															
								}

			}
				
	else 
		{	
				
				//b[j1] = a[j1];
			sum_s = sum_s-a[j1] + data1;
				a[j1] = data1;
				j1 = (j1+1)%N;
		}	

	
//d = sum_s/N;
//return  data1;
return (sum_s/(N));*/
}
//temperature drift
 float	GetTemperature()
{
	  static int   data_te=0;
    static float  data_t= 0;
	delay_ms(100);
	data_te = read_data_from_ad7191();
	if(0x008C00000<data_te<0x008D0000)
	{data_t = (float)(data_te - 8388608)/2815-273;
	data_t= data_t;
	data_t = (data_t -28)*0.00017;
	data_t= 2865.33*data_t;
	data_t= data_t;
	flag_t = 0;
	return  data_t;}
}

//求数据长度
int deal_num(unsigned char *deal_tmp, unsigned char *data)
{
	int i = 0;
	while(*data != 0x00){  //未结束
		if((i % 2) == 0)
			deal_tmp[i++] = 0X00;
		else{
			deal_tmp[i] = *data;
			i++;    
			data++;//指向下个字符数组
		}
	}
	return i;
}
void ad7191_config(enum rate_switch rate, enum gain_switch gain, int channal, unsigned char in_or_temp, unsigned char in_or_ex)
{
	ad7191_off();
	ad7191_on();
	AD7191_gpio_Configuration();
	sellect_channal(channal);
	set_rate(rate);
	select_tem(in_or_temp);
	select_IN_OR_EX(in_or_ex);
	set_gain(gain);
	//delay_ms(450);
}


unsigned char light_sensor = 0;
//AD值处理和发送
float get_data_and_send()
{
//	static int sum_s= 0;
  static int data1 =0;
	static int i_icount=0;
	static int ptr = 0,ptr_d= 0;
	static int over_flag= 0;
	static int j1=0;
	static int  d =0 ;
	static int data1_max[10] ,data1_min[10] ;
	static int data_sum= 0,sum_min =0,sum_max=0,sum_sum=0;
	static int i_max=0,i_min= 0,i_sum = 0,i_iamp = 0;
	static int i_amp= 0;
	static int flag_amp=0;
	static float sum_amp = 0;
		static int pre_m= 0,pre_n = 0,data_t=0;	
	while(PAin(6) == 1){
		;
	}
  data1 = read_data_from_ad7191();
	A_BUFF[ptr] = data1;
	
		ptr++;
	if(ptr == N) {
		ptr = 0;
		over_flag = 1;
	}
	if(over_flag == 1)
	{	

		for(ptr_d= 0;ptr_d<N-2;ptr_d++)
		{
			if((A_BUFF[ptr_d]>A_BUFF[ptr_d+1])&&(A_BUFF[ptr_d+1]<A_BUFF[ptr_d+2]))
					{
						data1_min[i_min]=A_BUFF[ptr_d+1];
						i_min++;
						
					}
			else if((A_BUFF[ptr_d]<A_BUFF[ptr_d+1])&&(A_BUFF[ptr_d+1]>A_BUFF[ptr_d+2]))
					{
						data1_max[i_max]=A_BUFF[ptr_d+1];
						i_max++;
						//i_max=i_max;
					
					}
				}
					
		
		if((i_min<=2)||(i_max<=2))
		{	
			for(pre_m= 0;pre_m<N;pre_m++)
			
											{	for(pre_n=0;pre_n<32-pre_m;pre_n++)
													{if(arr[pre_n]>arr[pre_n+1])
													 {
													 data_t=A_BUFF[pre_n];
													 A_BUFF[pre_n]=A_BUFF[pre_n+1];
													 A_BUFF[pre_n+1]=data_t;
													 }}}
			sum_sum =A_BUFF[0]+A_BUFF[15];
			data_sum = sum_sum/2;
		}
		else{	
				if(i_min<i_max)
						{i_sum = i_min;}
				else{i_sum = i_max;}
					for(i_min= 0;i_min<i_sum;i_min++)
					{
						sum_min= data1_min[i_min]+sum_min;
					}
					for(i_max= 0;i_max<i_sum;i_max++)
					{
						sum_max= data1_max[i_max]+sum_max;
					}
					data_sum = (sum_max+sum_min)/(2*(i_sum));
				}
		
		amp1 =(float)((data_sum)-8388608)*5.00*1000/(128*8388608);
			load_amp[i_amp] = amp1;//biao ding
			i_amp++;
			if(i_amp >= 16) {
				i_amp = 0;
				flag_amp = 1;
					}
			/*if(flag_amp==1)
			{for(i_iamp = 0;i_iamp<5;i_iamp++)
				{
					sum_amp= sum_amp+load_amp[i_iamp];
					
				}
				flag_amp = 0;
				i_iamp = 0;
			}
			amp1 = 		sum_amp/5;*/
	if(flag_load == 1)
		{
			amp_v = (2000/(line_m-line_b))*(amp1-line_b);
			//flag_load = 0;
			flag_load = 0;
		}	
		else 
		{
			amp_v= 2792.906*amp1 -11216.03;//传感器拟合直线_lasting
		}
		over_flag= 0;
		ptr_d= 0;
		i_max= 0;
		i_min= 0;
		sum_min = 0;
		sum_max= 0;
		i_sum=0;
		sum_amp=0;
		sum_sum = 0;
		data_sum =0;
		//memset(A_BUFF, 0, sizeof(int) * N);
	}
		return amp_v;
}
							
float get_data_and_send_moving()
{
	static int i_m =0;
		static int m=0;
  static int n = 0;
	static float t = 0;
	static float sum_jj= 0;
//			for(i_m = 0;i_m<32;i_m++)
//	{
//		arr[i_m] = A_BUFF[i_m];
//		
//	}
	
//								for(m=0;m<32;m++) 
//											{	for(n=0;n<32-m;n++)
//													{if(arr[n]>arr[n+1])
//													 {
//													 t=arr[n];
//													 arr[n]=arr[n+1];
//													 arr[n+1]=t;
////													 }}}
//												for(n=0;n<32;n++)
//														{ sum_jj+=arr[n];}
//												amp = sum_jj/32;
//													sum_jj=0;
//							amp =  sum_s/16;		
//						sum_s= 0;

						return amp;
							

	}
float get_data_and_send_static()
{
	static long sum = 0;
	static int count = 0;
	static float damp;
	static int i_con=0;
	
	static int i_count=0;
  static int j = 0;
  static float sum_j = 0,sum_jj= 0;
	static int m=0;
  static int n = 0;
	static float t = 0;
	static int i_pre=0;
	static int i_i=0;
	static float amp_comp;
	amp_comp =amp_ad- origin;
	
//		for(i_i = 0;i_i<64;i_i++)
//	{
//		arr[i_i] = A_BUFF[i_i];
//	}
			
//								for(m=0;m<64;m++) 
//											{	for(n=0;n<64-m;n++)
//													{if(arr[n]>arr[n+1])
//													 {
//													 t=arr[n];
//													 arr[n]=arr[n+1];
//													 arr[n+1]=t;
//													 }}}
//												for(n=0;n<64;n++)
//														{ sum_jj+=arr[n];}
//												amp = sum_jj/64;
//													sum_jj=0;
												
					return amp_comp;
												}						
			
								
							//	return  amp;}
											//	sum_j = 0;
float data_compare()		
{
	static int i_pre=0;
		amp = get_data_and_send_static();
		//amp= 1000;
					if(amp>3)
									{
										
										if(i_pre<1)
										{amp_pre=amp;
											i_pre++;
										}else{i_pre = 0;}
									if(i_pre==0)
									{
									er_2= amp-amp_pre ;
									er_1 = amp_pre-amp_pre_1;
									
									er=amp-amp_pre_1 ;
									if(((er_1>=0.5)&&(er_2>=0.5))||((er_1<=-0.5)&&(er_2<=-0.5)))
										{
											amp_pre_1=amp;
											return  amp;
										}
									else if(((er_1>=0.5)&&(0.5>er_2>0))||((er_1<=-0.5)&&(-0.5<er_2<0)))	
										{
												amp_pre_1 =amp_pre;
												return  amp_pre;
										}
									else if(((0.5>er_1>0)&&(0.5>er_2>=0))||((-0.5<er_1<0)&&(-0.5<er_2<=0)))	
										{
												if(fabs(er)<=0.5)
													{
														return  amp_pre_1;
													
													}
													else{
														amp_pre_1 = amp;
														return  amp;
														}
						
													
										}
										else {return  amp_pre_1;}
										
									
									}
									else 
												{return  amp_pre_1;}
								}
							else
									{
										amp=0;
										return  amp;
												
												
										}
									
			}

void data_and_send(void)
{
	unsigned char *printbuf;
	 unsigned char *data_print;
	 unsigned char *pp;
	 	int length = 0;

			printbuf = (unsigned char *) calloc (40,sizeof(unsigned char));
			data_print = (unsigned char *) calloc (20,sizeof(unsigned char));
			pp = (unsigned char *) calloc (40,sizeof(unsigned char));

	amp11_t= amp11_t-data_temp;
	if(amp11_t<0)
	{amp11_t=0;}
	sprintf((char *)data_print,"%.1f\r\n",amp11_t);
			length = deal_num(pp,data_print);
			USART3_Push(data_print,length);       //调试串口
			printbuf[0] = 0x5a;
			printbuf[1] = 0xa5;
			printbuf[2] = length + 3;
			printbuf[3] = 0x82;
			printbuf[4] = (ADDR & 0xff00) >> 8;
			printbuf[5] = (ADDR & 0x00ff);
			memcpy((printbuf + 6),pp,length);
			USART1_Push(printbuf,length + 6);    //RS232给串口屏
			free(data_print);
			free(printbuf);
			free(pp);
}
//AD配置函数
/*void ad7191_config(enum rate_switch rate, enum gain_switch gain, int channal, unsigned char in_or_temp, unsigned char in_or_ex)
{
	ad7191_off();
	ad7191_on();
	AD7191_gpio_Configuration();
	sellect_channal(channal);
	set_rate(rate);
	select_tem(in_or_temp);
	select_IN_OR_EX(in_or_ex);
	set_gain(gain);
	//delay_ms(450);
}*/

