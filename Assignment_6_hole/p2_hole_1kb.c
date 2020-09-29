#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	char f_name[50];
	char string[50] = "After this 1kb size hole will be created";

	printf("\nEnter name of file you want to create: ");
	scanf("%s",f_name);

	int cr =0;
//create empty file
	cr = creat(f_name,O_RDWR);

	if (cr == -1)
	{
		printf("\nNot able to create file\n");
		return -1;
	}
//add data in start
        int ret=0;
	ret = write(cr,string,sizeof(string));
	if (ret == -1)
        {
                printf("\nNot able to write in file\n");
                return -1;
        }
// get size before hole

	struct stat buffer;
	if (stat(f_name,&buffer) < 0)
	{
		printf("\nError while retriving statistics of file\n");
                return -1;
	}
        printf("\nSize of file before hole is: %d\n",(int)buffer.st_size);

// move 1000 location , and write
        lseek(cr,1000,SEEK_SET);

	write(cr,"EOF",3);


// size now 
        struct stat buffer1;
        if (stat(f_name,&buffer1) < 0)
        {
                printf("\nError while retriving statistics of file\n");
                return -1;
        }
        printf("\nSize of file after hole is: %d\n",(int)buffer1.st_size);
	


	return 0;
}
