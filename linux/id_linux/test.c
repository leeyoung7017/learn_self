#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    printf("uid is %d\n", getuid());
	printf("guid is %d\n", getgid());
	printf("euid is %d\n", geteuid());
	printf("egid is %d\n", getegid());
	return 0;

}
