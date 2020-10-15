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
 int fd;
 int count=0;
 char letter[1];
	fd = open("hello.txt",O_RDONLY);
	
	while(read(fd,letter,1))
	{
		if((letter[0] >= 'A') && (letter[0] <= 'Z'))
			count++;
	}
//	printf("%d\n",count);

int ret;
char buff[100];
struct stat fileStat;

       stat("count.txt",&fileStat);
       printf("Number of Links : \t%d\n",(int)fileStat.st_nlink);

       ret = open("count.txt",O_WRONLY);
       lseek(ret,0,SEEK_END);
       sprintf(buff,"Process 2 pid: %d Capitel later count: %d\n",getpid(),count);
       write(ret,buff,strlen(buff));
       close(ret);


return 0;
}
