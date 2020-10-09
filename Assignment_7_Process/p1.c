#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h> 

int main()
{
	pid_t pid;

	

	if((pid=fork()) == 0)
	{
		printf("\nHello from child pid : %d\n",getpid());
	}
	else
	{int child_status;

		printf("\nHello from parent, parent pid: %d\n",getpid());
		child_status = wait(NULL);  //time will come when parent will execute first it will see wait call then let child complete then parent will continue its tasks
		printf("\nHello from parent, child pid: %d\n", child_status);
	}
       
	return 0;
}
