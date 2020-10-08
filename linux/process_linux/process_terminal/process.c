#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	FILE *file;
	char *buf;
	pid_t process_ID1,process_ID2;
	/*创建进程*/
	process_ID1 = fork();
	
	/*清空数组缓存*/
	memset(buf,1,strlen(buf));
	
	if(process_ID1 == 0)/*子进程*/
	{
		printf("this is subprocess1 pid:%d \n",getpid());
		buf = "subprocess1 is running pid:\n" ;
		sleep(10);
		/*将信息写入文件*/
		file = fopen("subprocess1.txt","w+");
		fwrite(buf,1,strlen(buf),file);
		fclose(file);
		return 0;
		
	}
	if(process_ID1 == -1)/*进程出错*/
	{
		printf("process1 error");
		
		buf = "process1 creation error\n";
		
		file = fopen("error.txt","w+");
		fwrite(buf,1,strlen(buf),file);
		fclose(file);
		return 0;
	}
	else /*父进程*/
	{
		waitpid(process_ID1,NULL,0);
		process_ID2 = fork();
		if(process_ID2 == 0)/*子进程*/
		{
			printf("this is subprocess2 pid:%d \n",getpid());
			buf = "subprocess2 is running pid:\n" ;
			sleep(10);
			/*将信息写入文件*/
			file = fopen("subprocess2.txt","w+");
			fwrite(buf,1,strlen(buf),file);
			fclose(file);

			return 0;
			
		}
		if(process_ID2 == -1)/*进程出错*/
		{
			printf("process2 error");
			
			buf = "process2 creation error\n";
			
			file = fopen("error.txt","w+");
			fwrite(buf,1,strlen(buf),file);
			fclose(file);
			return 0;
		}
		else
		{	
			do{
				process_ID2 = waitpid(process_ID2,NULL,WNOHANG);
				if(process_ID2 == 0)
				{
					sleep(1);
					printf("subprocess2 is running pid:\n");
				}
			}while(process_ID2 == 0);
			printf("this is parents process ppid:%d \n",getpid());
			buf = "parents_process is running\n";
			
			file = fopen("parents_process.txt","w+");
			fwrite(buf,1,strlen(buf),file);
			fclose(file);
			return 0;
		}
	}
}
