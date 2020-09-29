#include<stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
 char f_name[100];
 int pos;

	printf("\nEnter name of file from which you want to read 20 bytes: ");
	scanf("%s",f_name);
        printf("\nEnter position number from where you want to read: ");
	scanf("%d",&pos);
int fd=0,ret=0,rd=0;
        fd = open(f_name,O_RDONLY);
	if(fd==-1){
		printf("\nNot able to open file/not present\n");
		return -1;
	}

	ret = lseek(fd,20,SEEK_SET);
//	printf("\nret: %d\n",ret);

	char buffer[21];

        rd = read(fd,buffer,20);
        if(rd==-1){
                printf("\nNot able to read or maybe does not contain respective data to return\n");
                return -1;
        }
	else{
		 printf("\n\n20 bytes are from position [%d] : %s\n\n",pos,buffer);
	}


	return 0;
}
