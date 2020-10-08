#include "multiplex_io.h"


/*实现IO多路转接*/

int multiplex_io(void)
{
	int fd[3], select_ret,max_fd;
	char buf[max_size];
	fd_set fdset_read ,fdset_write;
	struct timeval time_delay;
	time_delay.tv_sec = 0;
	time_delay.tv_usec = 0;

	
	/*清空缓存*/
	memset(buf, 0, strlen(buf));
	
/*打开各个文件*/
	fd[0]= open("lee.txt",O_RDONLY|O_CREAT|O_NONBLOCK,0666);
	if(fd[0] == -1)
	{
		perror("open lee.txt failed ...\n");
		exit(1);
	}

	fd[1]= open("young.txt",O_RDONLY|O_CREAT|O_NONBLOCK,0666);
	if(fd[1] == -1)
	{
		perror("open young.txt failed ...\n");
		exit(1);
	}

	fd[2]= open("tree.txt",O_WRONLY|O_CREAT|O_NONBLOCK,0666);
	if(fd[2] == -1)
	{
		perror("open tree.txt failed ...\n");
		exit(1);
	}

/*文件描述符中的最大值*/
	max_fd = fd[0]>fd[1]?fd[0]:fd[1];
	max_fd = max_fd>fd[2]?max_fd:fd[2];
/*将写和读的文件描述符分别加入集合中*/
	FD_SET(fd[0], &fdset_read);
	FD_SET(fd[1], &fdset_read);
	FD_SET(fd[2], &fdset_write);
	

	while(FD_ISSET(fd[0], &fdset_read) || FD_ISSET(fd[1], &fdset_read) || FD_ISSET(fd[2], &fdset_write))
	{
	/*监控*/
		select_ret = select(max_fd+1,&fdset_read,&fdset_write,NULL,&time_delay);
	/*监控下的操作*/
		if(select_ret == -1)
		{
			perror("select failed ...\n");
			exit(1);
		}
		if(select_ret == 0)
		{
			printf("time is over ...\n");
			exit(0);
		}
		else
		{
			if(select_ret == fd[0] || select_ret == fd[1])
			{
				if(read(select_ret,buf,max_size) == -1)
				perror("read select_ret failed ...\n");
			
			else
				printf("%s",buf);
			}
			else
			{
				printf("please write what you need:");
				gets(buf);
				if((buf[0] == "q")||(buf[0] == "Q"))
					return 0;
				if(write(select_ret,buf,max_size) == -1)
					perror("write select_ret failed ...\n");
			
				else
					{
						printf("read : %s\n",buf);
						memset(buf,0, max_size);
					}
			}
		}
	}
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	exit(0);
	return 0;
}

