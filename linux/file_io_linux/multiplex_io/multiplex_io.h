#ifndef MULTIPLEX_IO_H
#define MULTIPLEX_IO_H




#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <errno.h>

#define max_size 1024




int multiplex_io(void);


 #endif


// /*

// int multiplex_io(void)
// {
	// int fd[2],max_fd,i;
	// char buf[max_size];
	// fd_set  return_fd;
	// int  return_select;
	// struct timeval time;
	// memset(buf,1,strlen(buf));
// //	memset(return_fd,1,strlen(return_fd));
	
	// /*设置等待时间*/
	// time.tv_sec = 10;
	
	// if(fd[0] = open("file0.txt",O_CREAT|O_RDONLY,0600) < 0)
	// {
		// perror("open file0.txt error");
		// exit(1);
	// }
	// if(fd[1] = open("file1.txt",O_CREAT|O_RDONLY,0600) < 0)
	// {
		// perror("open file1.txt error");
		// exit(1);
	// }
	
	// /*需要监视的文件描述符最大值*/
	// max_fd = fd[0] > fd[1]?fd[0]:fd[1];
	
	// /*需要监视的读文件描述符集合*/
	// for(i = 0;i <= arraylen(fd);i++)
	// {
		// FD_SET(fd[i],&return_fd);
	// }
	
	// /*监视函数配置*/
	// return_select = select(max_fd,&return_fd,NULL,NULL,&time);
	
	// while(1)
	// {
		
		// if(return_select == 0)
		// {
			// printf("time is over\n");
			// exit(0);
		// }
		// if(return_select == -1)
		// {
			// printf("select error\n");
			// exit(1);
		// }
		// else
		// {
			// for(i = 0;i <= arraylen(fd);i++)
			// {
				// if(read(fd[i],buf,max_size) < 0)
				// {
					// printf("read error");
					// exit(1);
				// }
				// else
				// {
					// printf("%s\n",buf);
					// close(i);
					// exit(0);
				// }
			// }
		// }
	// }
// }
// */


