//This program will copy regular files from directory to current directory(from where program is  executed).
//program will ask for directory name run time.
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

struct file{
	char f_name[20];
	int  f_size;

};

int main()
{char dir_path[50];
 

	printf("\nEnter name of directory: ");
	scanf("%s",dir_path);

//Directory variable
DIR *dp;
struct dirent *dir_structure;
//filestat variable
struct stat buffer;
//for storing path
char  relative_path[1000];
//structru part
struct file f1;


	dp = opendir(dir_path);
	if(dp == NULL)
        {
                printf("\nNot able to open diretory\n");
        }
		
	int fd = 0;

        fd = creat("temp",O_RDWR);
        if (fd == -1)
        {
                 printf("\nNot able to creat temp file\n");
        }


	while((dir_structure = readdir(dp)) != NULL)
	{

		sprintf(relative_path,"%s/%s",dir_path,dir_structure->d_name);

		if((stat(relative_path,&buffer))<0)
		{
		printf("Error while retriving statistics of file\n");
                return -1;
		}
		if(S_ISREG(buffer.st_mode))
		{
			strcpy(f1.f_name,dir_structure->d_name); 
			f1.f_size = (int)buffer.st_size;
		//printf("\n%s %d\n",dir_structure->d_name,(int)buffer.st_size);
		
			write(fd,&f1,sizeof(struct file));
               //red from file   
			int cp=0,fd1=0,wr=0;
			char temp_buffer[(int)buffer.st_size];
			memset(temp_buffer,'\0',(int)buffer.st_size);

			cp  = open(relative_path,O_RDONLY);
			fd1 = read(cp,temp_buffer,sizeof(temp_buffer));
		//	printf("\n%s: %d\n",relative_path,(int)buffer.st_size);
                //wrte to structure temp file
			wr  = write(fd,temp_buffer,(int)buffer.st_size);

		}


	}//end while// end reading data from dir

        //set fd to default
//	lseek(fd,0,SEEK_SET); 
	int fdnew = 0;     
        fdnew = open("temp",O_RDWR);
        if (fdnew == -1)
        {
                 printf("\nNot able to creat temp file\n");
        }  

        struct file f2;


	while(read(fdnew,&f2,sizeof(struct file)))
	{int ret=0;
	int read_buffer[f2.f_size];
	printf("\n%s: %d\n",f2.f_name,f2.f_size);
        read(fdnew,read_buffer,f2.f_size); 

        ret = creat(f2.f_name,O_WRONLY);
        write(ret,read_buffer,f2.f_size);
        close(ret);	

	}



close(fd);
close(fdnew);
return 0;
}
