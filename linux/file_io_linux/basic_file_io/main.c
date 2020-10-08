#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "file_lock.h"

#define max_size 1024

int main()
{
	int fd;
	char buf[max_size];
	char buf1[max_size];
	/*清空数组缓存*/
	memset(buf,0,max_size);
	/*创建并打开文件*/
	if((fd = open("file1.txt",O_CREAT|O_RDWR,644)) < 0)
	{
		printf("the file1 creation error ");
		return -1;
		
	}
	/*写文件*/
	file_lock(fd,F_WRLCK);

	printf("please input what you need:\n ");
	scanf("%s",buf);
	if(write(fd,buf,max_size) < 0)
	{
		printf("the file1 writting error");
		return -1;
	} 
	file_lock(fd,F_UNLCK);
	/*移动光标*/
	lseek(fd,0,SEEK_SET);

	file_lock(fd,F_RDLCK);
	/*读取文件内容*/
	if(read(fd, buf1,max_size) < 0)
	{
		printf("the file1 reading error");
		return -1;
	}
	else printf("读取的内容为：\n %s \n",buf1);
	
	/*关闭文件*/
	close(fd);
	return 0;
	
}
/****************************************************************************************
*read函数中：
*	void* buf：是指为获取的数据开辟的空间；
*			而 char* buf 只是一个指针变量，并未数据开辟一块空白空间
*			而 char buf[i] 数组则开辟了一块空间，用于存储数据
 ****************************************************************************************/
