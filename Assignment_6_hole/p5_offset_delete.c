#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	char f_name[50];
	int  offset=0;
	char string[50] = "After this 1kb size hole will be created";

	printf("\nEnter name of file you want to open: ");
	scanf("%s",f_name);

	printf("\nEnter offset of file you want to delete: ");
        scanf("%d",&offset);
 
	int fd = open(f_name,O_RDWR);
	if(fd == -1)
	{
            printf("\nNot able to open file!!!\n");
	}
//	lseek(fd,offset,SEEK_SET);
	int ret = 0; 
	ret = ftruncate(fd,offset);

	printf("\nDeleted after offset\n");


	return 0;
}
