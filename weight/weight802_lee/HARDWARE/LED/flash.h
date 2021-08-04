#ifndef _FLASH_H_
#define _FLASH_H_

#include "sys.h"
#include "uart1.h"

/*“≥20	0x0800 5000 ~ 0x0800 53FF*/
#define PAGE_ADDR ((volatile uint32_t)0x08005000)	/*pro_edit µÿ÷∑*/
#define PAGE_ADDR_LOG	((volatile uint32_t)0x08005400)			/*log µÿ÷∑*/
#define PAGE_ADDR_TEST_PARA		((volatile uint32_t)0x080051E0)	/*test_para	µÿ÷∑*/


void flash_save(uint32_t* Data,uint32_t length);
void flash_read(uint32_t* Data,uint32_t length,uint32_t addr);
void pro_edit_filled(uint32_t* Data,uint32_t length,uint16_t address);
void log_filled(uint32_t* Data,uint32_t length,uint32_t address);
void flash_read_test_para(uint32_t* Data,uint32_t length);
void flash_save_test_para(uint32_t* Data,uint32_t length);
void test_para_filled(uint32_t* Data,uint32_t length);
#endif
