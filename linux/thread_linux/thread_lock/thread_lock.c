#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*线程1*/
void thread1(void)
{
	//pass
	pthread_exit(0);
}

/*线程2*/
void thread2(void)
{
	//pass
	pthread_exit(0);
}

/*进程*/
/*为了防止两个线程同时进行产生系统崩溃，就采用互斥锁的形式进行加锁解锁*/
int main(void)
{
	pthread_t thread_id1,thread_id2;
	int ret;
	
	ret = pthread_create(&thread_id1,NULL,&thread1,NULL);
	if(!ret)
	{
		printf("pthread_create failed...\n");
	}
	ret = pthread_create(&thread_id2,NULL,&thread2,NULL);
	if(!ret)
	{
		printf("pthread_create failed...\n");
	}
	pthread_join(thread_id1,NULL);
	pthread_join(thread_id2,NULL);
	return ret;
}

pthread_mutex_init();/*在线程入口前使用*/
pthread_mutex_lock();/*在线程函数中实现功能前*/
pthread_mutex_unlock();/*在线程函数中实现功能完毕后*/
pthread_mutex_trylock();/*在线程函数中加锁之前查询*/
