#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
int main()
{

 int  read_count=0;
 char dir_name[200];
 char msg1[50] = "\nEnter directory name or path: ";
        write(1,msg1,sizeof(msg1));
        read_count=read(0,dir_name,sizeof(dir_name));

	if(dir_name[read_count-1]=='\n')
	{
		dir_name[read_count-1] = 0;
	}

//change dir
/*int status;
	status = chdir(dir_name);
        if(status == -1)
	{
		printf("Check Directory Path or Directory not present\n");
		return -1;
	}
*/

DIR *dir;
struct dirent  *entry;

struct stat buffer;

        dir = opendir(dir_name);
	if(dir == NULL)
	{
		printf("\nNot able to open diretory\n");
	}

	printf("Content of file are:");
//chnage location
	int status;
        status = chdir(dir_name);
        if(status == -1)
        {
                printf("Check Directory Path or Directory not present\n");
                return -1;
        }

int file_size=0;
char name_large[200];

	while((entry = readdir(dir)) != NULL)
	{
		//printf("%s : ",entry->d_name);
		if (stat(entry->d_name, &buffer) < 0)
		{	
		printf("Error while retriving statistics of file\n");
		return -1;
		}
		//check file type
		if (S_ISREG(buffer.st_mode))
		{
			if(file_size <(int)buffer.st_size)
			{
				file_size = (int)buffer.st_size;
				strcpy(name_large,entry->d_name);
			}

		}
	}
	 printf("\nLargest File Name: %s Size:%d(bytes)\n",name_large,file_size);

  	
	
}


