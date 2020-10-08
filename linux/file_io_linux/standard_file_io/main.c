#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define max_size 1024
char *gets();
int main(void)
{
	/*标准io打开文件*/
	FILE *file;
	/*写入内容缓存*/
	char buf[max_size];

	/*清空数组缓存*/	
	memset(buf,0,sizeof(buf));	

	/*标准io打开文件*/
	file = fopen("file1.txt","w+");
	if(file == NULL)
	{
		printf("fopen file1.txt error\n");
		exit(0);	
	}

	/*标准io写入内容*/
	printf("请输入:\n");
	gets(buf);
	if(fwrite(buf,1,sizeof(buf),file) == EOF)
	{
		printf("fwrite file1.txt error\n");
		exit(0);
	}

	/*标准io读取文件*/
	if(fread(buf,1,1024,file) == EOF)
	{
		printf("fread file1.txt error\n");
		exit(0);
	}
	printf("读取的内容为:\n");
	printf("%s\n",buf);
	
	

	/*标准io关闭文件*/
	fclose(file);
			
	
	return 0;
}


