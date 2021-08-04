#include "flash.h"
#include "uart1.h"

void flash_save(uint32_t* Data,uint32_t length)
{
	unsigned int i;
	/* Unlock the Flash Bank1 Program Erase controller */
	FLASH_UnlockBank1();
	
	
	/* Clear All pending flags */
	FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);   
	
	if(FLASH_ErasePage(PAGE_ADDR) == FLASH_COMPLETE)
	{
		for(i = 0;i<length;i++)
		{
			FLASH_ProgramWord(PAGE_ADDR+i*4, Data[i]);
		}
		
	}

	/* Lock the Flash Bank1 Program Erase controller */
	FLASH_LockBank1();
}


void flash_read(uint32_t* Data,uint32_t length,uint32_t addr)
{
	int i;
	uint32_t d; 
	for(i=0;i<length;i++)
	{
		d = *(volatile uint32_t*)(addr+i*4);
		Data[i] = d;
		
	}/*Data数据获取数据*/
	
}

void pro_edit_filled(uint32_t* Data,uint32_t length,uint16_t address)
{
	uint32_t i;
	uint16_t addr;
	uint32_t index = (address - 0x1130)/2;
	for(i=0;i<length;i++)
	{
		addr = address+i*2;
		WRITE_HMI_Data(addr,Data[i+index]);	
		delay_ms(10);
	}
}



void log_filled(uint32_t* Data,uint32_t length,uint32_t address)
{
	uint32_t i;
	for(i=0;i<length;i++)
	{
		/*写入数据*/
 		WRITE_HMI_Data(address+i*2,Data[i]);
		delay_ms(10);
	}
}

void test_para_filled(uint32_t* Data,uint32_t length)
{
	int i;
	for(i = 0;i<length;i++)
	{
		if(i == 0) WRITE_HMI_Data(0x0010,Data[i]);	
		else if(i == 1) WRITE_HMI_Data(0x0012,Data[i]);
		else if(i == 2) WRITE_HMI_Data(0x2014,Data[i]);
		else if(i == 3)	WRITE_HMI_Data(0x2016,Data[i]);
		delay_ms(10);
	}
}

