#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h> 

int main()
{
	pid_t pid1,pid2,pid3;

	

	if((pid1=fork()) == 0)
	{
		 if((pid2=fork()) == 0)
		 {
			 printf("\nChild process : 2 pid : %d\n",getpid());
			 if((pid3=fork()) == 0)
			 {
				 printf("\nChild process : 3 pid : %d\n",getpid());
			 }//end if pid3
			 else
			 {
				  wait(NULL);
			 }
		 }//end if pid2
		 else
		 {
			printf("\nChild process : 1 pid : %d\n",getpid());
			wait(NULL);

		 }
	}//end if pid1
	else
	{int child_status;

		child_status = wait(NULL);  //time will come when parent will execute first it will see wait call then let child complete then parent will continue its tasks
		printf("\nHello from parent, parent pid: %d\n",getpid());
		printf("\nHello from parent, 1st child pid was : %d\n", child_status);
	}
       
	return 0;
}
/* Sample output
Child process : 1 pid : 2553
Child process : 2 pid : 2554

Child process : 3 pid : 2555

Hello from parent, parent pid: 2552

Hello from parent, 1st child pid was : 2553*/
