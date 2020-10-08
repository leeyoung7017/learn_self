#include "ipc.h"

int ipc(int flag)
{	
	int pid;
	char* buf = "lishuyang";
	char buf1[MAX_Size]={0};
	int size = 0;
	int fd[2];
	switch(flag)
	{
		case pipe_opera:
			if(pipe(fd) < 0)/*创建匿名管道*/
			{
					printf("pipe failed ...\n");
					return -1;
			}
			pid = fork();
			if(pid == 0)/*子进程*/
			{
				close(fd[0]);
				
				/*子进程写管道*/
				if((size = write(fd[1],buf,strlen(buf))) != -1)
				{
					printf("subprocess wrote %d bytes: %s\n",size,buf);
					close(fd[1]);
				}
				else 
				{
					printf("write failed ...\n");
					close(fd[1]);
					return -1;
				}
				sleep(1);
			}
			else if(pid > 0)/*父进程*/
			{ 
				/*等待子进程结束*/
				if(waitpid(pid,NULL,0) == -1)
				{
					printf("waitpid failed ...\n");
					close(fd[0]);
					close(fd[1]);
					return -1;
				}
				close(fd[1]);
				
				/*父进程读管道*/
				if(read(fd[0],buf1,MAX_Size) !=-1)
				{
					printf("read  : %s\n",buf1);
				}
				else
				{
					printf("read failed ...\n");
					close(fd[0]);
					return -1;
				}
			}
			else/*进程创建失败*/
			{
				printf("fork failed ...\n");
				close(fd[0]);
				close(fd[1]);
				return -1;
			}
			break;
		case fifo_opera_write:
			if(access(fifo_path,F_OK)==-1)
			{
				if(mkfifo(fifo_path,0777) == -1)
				{
					printf("mkfifo failed ...\n");
					exit(-1);
				}
			}
			
			fd[1] = open(fifo_path,O_WRONLY);
			if(fd[1] == -1)
			{
				printf("opening myfifo failed ...\n");
				exit(-1);
			}
			if((size=write(fd[1],buf,strlen(buf))) == -1)
			{
				printf("writing myfifo failed ...\n");
				exit(-1);
			}
			else{printf("write %d bytes:%s\n",size,buf);}
			close(fd[1]);
			break;
			
		case fifo_opera_read:
			if(access(fifo_path,F_OK)==-1)/*判断文件是否存在*/
			{
				if(mkfifo(fifo_path,0777) == -1)
				{
					printf("mkfifo failed ...\n");
					exit(-1);
				}
			}
			
			fd[0] = open(fifo_path,O_RDONLY);
			if(fd[0] == -1)
			{
				printf("opening myfifo failed ...\n");
				exit(-1);
			}
			if(read(fd[0],buf1,MAX_Size) != -1)
			{
				printf("read : %s\n",buf1);
			}
			else
			{
				printf("reading myfifo failed ...\n");
				exit(-1);
			}
			close(fd[0]);
			break;
			
		default:
			break;
	}
	return 0;
}
