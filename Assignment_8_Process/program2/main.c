#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include <fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main()
{int fd,status;
 
	fd = creat("count.txt",0x777);

	pid_t p1,p2;

	if((p1 =fork()) == 0)
	{
		execl("./process_1","",NULL);
	}
	wait(&status); // else any one process over wtites other // need fix

	if((p2 =fork()) == 0)
        {
		execl("./process_2","",NULL);
        }

	close(fd); //we dont mind order of closing it 



return 0;
}
