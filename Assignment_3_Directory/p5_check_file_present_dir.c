#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
int main()
{

 int  read_count=0;
 char dir_name[200];
 char file_name[200];
 char msg1[50] = "\nEnter directory name or path: ";
 char msg2[50] = "\nEnter file name to search in directory: ";

//get dir name
        write(1,msg1,sizeof(msg1));
        read_count=read(0,dir_name,sizeof(dir_name));

	if(dir_name[read_count-1]=='\n')
	{
		dir_name[read_count-1] = 0;
	}

//get file name
read_count=0;
	write(1,msg2,sizeof(msg2));
        read_count=read(0,file_name,sizeof(file_name));

        if(file_name[read_count-1]=='\n')
        {
                file_name[read_count-1] = 0;
        }




DIR *dir;
struct dirent  *entry;

struct stat buffer;

        dir = opendir(dir_name);
	if(dir == NULL)
	{
		printf("\nNot able to open diretory\n");
	}

//chnage location
	int status;
        status = chdir(dir_name);
        if(status == -1)
        {
                printf("Check Directory Path or Directory not present\n");
                return -1;
        }

 
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
		{int temp=-1;

			temp= strcmp(file_name,entry->d_name);
			if(temp == 0)
			{
			   printf("\n*****File present in directory****\n");
			}
			   else
			   {
			      printf("\n***********File Not found**********\n");
			      return -1;
			   }
		//printf("\nFile Name: %s\n",entry->d_name);
		}
	}

return 0; 	
	
}


