#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
pid_t pid[2];
int i;
//int count =100;
	for(i=0;i<2;i++)
	{
		if ( (pid[i]=fork()) == 0)
		{
			printf("\n\nThis is child process no: %d and pid is: %d and parent pid is: %d \n\n",i,getpid(),getppid());
			sleep(5);
			exit(100+i);
		}
	}//end 



int ret;
	for(i=0;i<2;i++)
        {
		pid_t child_pid = waitpid(pid[i],&ret,0);
		if(WIFEXITED(ret))  //WIFEXITED(status): child exited normally
		{
	 	printf("\n\nChild process returned : %d exit code is %d \n\n",child_pid, WEXITSTATUS(ret));
		}
	}//end for loop
	


	printf("\n\n*******This is Parent process:%d******* \n\n",getpid());
	printf("\n\n *******Last to execute****** \n\n");
return 0;
}
