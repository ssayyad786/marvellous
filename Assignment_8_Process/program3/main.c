#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include <fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main()
{
        int status; 	
	pid_t p1;

	if((p1 =fork()) == 0)
	{
		execl("./file_rename_all_indir","",NULL);
	}
	wait(&status);

return 0;
}
