#ifndef _SHM_H_
#define _SHM_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int shm_init(size_t size);

int shm_config(int shmid,int cmd,struct shmid_ds *buf);

void *shm_at_init(int shmid,int shmflg);

int shm_delat(void *shmaddr);




#endif
