#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	char f_name[20];

	printf("\nEnter file name: ");
	scanf("%s",f_name);

//open file
	int fd,dup_fd,ret;
	fd = open(f_name,O_CREAT | O_APPEND | O_WRONLY);
//0 std input
//1 std output
	dup_fd=dup2(fd,1);

	if(dup_fd == -1)
	{
		printf("\n\ndup2 failed");
	}
	printf("\nThis Line will be re-directed to file\n");

	return 0;
}
