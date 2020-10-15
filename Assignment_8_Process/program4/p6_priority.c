/*
 * 6. Write a program which is used to display Environment of our running process.
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

        
        printf("\nProcess PID is %d\n",getpid());
	printf("\nParent Process PID is %d\n",getppid());
	int pri=101;
	pri = getpriority(PRIO_PROCESS,0); 
        printf("\nProcess Priority is %d\n",pri);
	
return 0;
}
