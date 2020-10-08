#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <syslog.h>/* 守护进程出错处理将错误写入系统日志中/var/log/syslog */

int main(void)
{
	char *buf;
	int fd;
	pid_t pid;
	pid = fork();
	buf = "this is a daemon";
	openlog("daemon_syslog",LOG_PID,LOG_DAEMON);
	if(pid == 0)/*子进程*/
	{
		/*创建新的会话*/
		if(setsid() == -1)
		{
			syslog(LOG_ERR,"%s\n","setsid");
			exit(1);
		}
		
		/*更改当前工作目录*/
		if(chdir("/") == -1)
		{
			syslog(LOG_ERR,"%s\n","chdir");
			exit(1);
		}
		
		/*重设文件权限掩码*/
		if(umask(0) == -1)
		{
			syslog(LOG_ERR,"%s\n","umask");
			exit(1);
		}
		
		/*关闭文件描述符*/
		for(fd = 0; fd < getdtablesize();fd++)
		{close(fd);}
	    while(1)
		{
			if((fd=open("/tmp/daemon.log",O_CREAT|O_WRONLY|O_APPEND,0600)) < 0)
			{
				syslog(LOG_ERR,"%s\n","openfile");
				exit(1);
			}
			write(fd,buf,strlen(buf)+1);
			close(fd);
			sleep(10);
		}
		closelog();
		exit(0);
	}
	if(pid == -1)/*进程创建错误*/
	{
		printf("process creation error\n");
		exit(1);
	}
	else/*父进程*/
	{exit(0);}
}
