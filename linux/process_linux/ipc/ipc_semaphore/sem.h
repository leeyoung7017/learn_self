#ifndef SEM_H
#define SEM_H

int P(int semid,int semnums,int value);
int V(int semid,int semnums,int value);
int sem_init();int sem_init(int semnums,int value);
int sem_del(int semid);

#endif