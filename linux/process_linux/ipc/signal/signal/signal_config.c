#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "signal_config.h"
#include <sys/types.h>
#include <unistd.h>


void sigtstp_hander(int signo)
{
	printf("SIGTSTP___SIGTSTP___SIGTSTP___SIGTSTP\n");
}


int signal_config()
{
	if(signal(SIGTSTP,SIG_DFL) == SIG_ERR){
		printf("SIGTSTPERR___SIGTSTPERR___SIGTSTPERR___SIGTSTPERR\n");
	}

	int i = 0;
	for(i=0;i<30;i++){
		printf("%d运行%d次\n",getpid(),i+1);
		sleep(2);
	}
	exit(0);
	return 0;
}
