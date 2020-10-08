#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void my_func(int signo)
{
	printf("the signal SIGINT is coming\n");
}





int main(void)
{
	int i = 0;
	struct sigaction act , oldact;
	sigset_t sa_mask_my;
	act.sa_handler = my_func;
	act.sa_flags = SA_ONESHOT;
	act.sa_mask = sa_mask_my;
	
	sigaction(SIGINT,&act,&oldact);
	for(i = 0;i < 10;i++)
	{
		printf("%d:running %d\n",getpid(),i+1);
		sleep(2);
	}
	return 0;
}
