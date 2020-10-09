#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{

	pid_t pid1,ssid;
	int fd=0;
        pid1 = fork();

        if(pid1<0)
	{
           printf("\nERROR IN FORK\n");
	}
         
	if( pid1> 0 )
	{
	    printf("\nBye from parent process id: %d\n",getpid());
	    exit(0);
	}

	printf("\nHello From Child demon: %d\n",getpid());
       
	ssid = setsid();
	
	while(1)
	{
	write(0,"\n\nHEllO FROM DEMON IN EVERY 10SEC\n\n",31);
	printf("\nHello From Child demon: %d\n",getpid());
	sleep(5);
	}
}

