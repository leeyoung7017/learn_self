#ifndef IPC_H
#define IPC_H

#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>

#define pipe_opera 0	/*具有亲缘关系的IPC*/

#define fifo_opera_write 1	/*两个互不相关的IPC*//*只能依次按顺序输入输出，不能使用lseek函数*/

#define fifo_opera_read 2

#define MAX_Size 1024

#define fifo_path "/tmp/myfifo"

int ipc(int flag);		/*Internet Processing Connection*/
int ipc_release(void);



#endif

/**************************************************************************
*	int pipe(int fd[2]);
*					每个进程不能同时使用两个fd，故只能用于不同进程间的通信
*					return：	0/1;
*					被赋值：	fd[0]  :open for reading pipe	
*								fd[1]  :open for writing pipe 
***************************************************************************/
/*管道：	无名管道；		————只用在有亲属关系的进程之间
		pipe			关闭用不到的fd
		


		有名管道FIFO；	————用在没有关系的进程之间
	   	mkfifo:			就可以直接使用基本的文件IO函数*///	access确定文件权限