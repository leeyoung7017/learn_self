#include "shm.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int shm_init(size_t size)
{
	int shmid;
	
	/*开辟 size 的空间*/
	if((shmid = shmget(IPC_PRIVATE,size,IPC_CREAT|IPC_EXCL|0666)) < 0)
	{
		perror("shmget failed...\n");
		exit(1);
	}
	return shmid;
}

/*映射空间*/
/*shmflg = 0 默认为共享空间可以被读写*/
void *shm_at_init(int shmid,int shmflg)
{
	
	void *shmaddr;
	
	if((shmaddr = shmat(shmid,NULL,shmflg)) < 0)
	{
		perror("shmat failed...\n");
		exit(1);
	}
	
	return shmaddr;
}


/*对空间的操作*/
/*删除共享内存*//*cmd = IPC_RMID*/
/*获取共享内存结构体信息*//*IPC_STAT*/
/*struct shmid_ds *buf*/
int shm_config(int shmid,int cmd,struct shmid_ds *buf)
{
	
	shmctl(shmid,cmd,buf);
}



/*解除空间映射*/
int shm_delat(void *shmaddr)
{
	int shmdt_ret;
	if(shmdt_ret = shmdt(shmaddr) < 0)
	{
		perror("shmdt failed...\n");
		exit(1);
	}
	return shmdt_ret;
}

