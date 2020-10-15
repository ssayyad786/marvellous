/*
 * 4.Write a program which is used to print priority of current process.
 */
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include <fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include <sys/resource.h>

int main()
{
	int pri=2;
//	nice(-5);
	pri = getpriority(PRIO_PROCESS,0);
	printf("\nPriority is %d\n",pri);
return 0;
}
