#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "sem.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
               int              val;    /* Value for SETVAL */
               struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
               unsigned short  *array;  /* Array for GETALL, SETALL */
               struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
           };


/*创建信号量集，初始化内部信号量*/
		   /*value-1 值就是指可以同时（value-1）个进程操作*/
int sem_init(int semnums,int value)
{
	int semid;//创建信号量集
	semid = semget(IPC_PRIVATE,semnums,IPC_CREAT|IPC_EXCL|0777);
	if(semid < 0 )
	{
		perror("semget failed...\n");
		exit(1);
	}
	union semun sem_union;
	/*为信号量集数据开辟空间*/
	sem_union.array = calloc(semnums,sizeof(unsigned short));

/*初始化信号量集内部信号量的初始值*/
	int i;
	for(i=0;i<semnums;i++)
	{
		sem_union.array[i]= value;
	}
	/*初始化信号量集中信号量的初始值*/
	if(semctl(semid,0,SETALL,sem_union) < 0)
	{
		perror("semctl failed...\n");
		exit(1);
	}
	return semid;
}


/*对信号量进行P操作*/
int P(int semid,int semnums,int value)
{
	struct sembuf sops;

	sops.sem_num = semnums;
	sops.sem_op = -value;
	sops.sem_flg = SEM_UNDO;
	
	if(semop(semid,&sops,1) < 0)
	{
		perror("semop failed...\n");
		exit(1);
	}
	return 0;
	
}
int V(int semid,int semnums,int value)
{
	struct sembuf sops;

	sops.sem_num = semnums;
	sops.sem_op = value;
	sops.sem_flg = SEM_UNDO;
	
	if(semop(semid,&sops,1) < 0)
	{
		perror("semop failed...\n");
		exit(1);
	}
	return 0;	
}

int sem_del(int semid)
{
	if(semctl(semid,0,IPC_RMID,NULL) < 0)
	{
		perror("semctl failed...\n");
		exit(1);
	}
	return 0;
}