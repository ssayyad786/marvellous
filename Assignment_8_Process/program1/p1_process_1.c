/*
 1. Write a program which creates new process which is responsible to write all file
names which are present on desktop in demo.txt file which should be created newly. 
 * */
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
	char demo[10] = "demo.txt";
	char desktop_path[10] = "/home";
        int fd,ret;

	DIR *dir;
	struct dirent *entry;

	ret = creat(demo,0x777);
	if (ret<0)
        {
                 printf("\nNot able to creat demo.txt file\n");
        }
	fd =  open(demo,O_WRONLY);

	if (fd<0)
	{
		 printf("\nNot able to open demo.txt file\n");
	}


	dir = opendir(desktop_path);
	if(dir == NULL)
        {
                printf("\nNot able to open diretory\n");
        }

	
       while((entry = readdir(dir)) != NULL)
       {
		write(fd,entry->d_name,strlen(entry->d_name));
		write(fd,"  ",2);
	       //printf("\n%s\n",entry->d_name);
       }

	return 0;
}
