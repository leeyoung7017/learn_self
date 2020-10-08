/*文件锁*/
#include <stdio.h>
#include "file_lock.h"
/*type的种类包括 F_RDLCK F_WRLCK F_UNLCK*/
int file_lock(int fd,short type)
{
	struct flock lock;
	lock.l_type = type;
	lock.l_start = 0;
	lock.l_whence = SEEK_SET;
	lock.l_len = 0;
	lock.l_pid = -1;
	
	/*获取错误*/
	if(fcntl(fd,F_GETLK,&lock) < 0)
	{
		printf("the flag gets error");
		return 1;
	}
	/*正常获取*/
	else
	{
		if(lock.l_type != F_UNLCK)/*获取上锁*/
		{
			if(lock.l_type == F_RDLCK)
			{
				printf("the file is reading by the process %d\n",lock.l_pid);
			}
			if(lock.l_type == F_WRLCK)
			{
				printf("the file is writing by the process %d\n",lock.l_pid);		
			}
		}		
		lock.l_type = type;
		fcntl(fd, F_SETLKW,&lock);
		return 0;	
	}
}

