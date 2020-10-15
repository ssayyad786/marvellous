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
   pid_t pid;

   pid = fork();

   if(pid == 0)
   {
	   execl("./p1_process_1"," ",NULL);

   }
   return 0;
}
