#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
int rfile(char const filename[]);

int main()
{  int fd,fdd, file_dis;  
   char name[200];  //for accepting name of source file
   char dname[200];  //for accepting name of destication file
   int  size=0;

        //source
        write(1,"\nEnter file name or path:",27); 
   	fd=read(0,name,sizeof(name));
	write(1,"\nName of file is:",18);
  	write(1,name,fd);

	if (name[fd-1] == '\n')
	{
            name[fd-1] = 0;
        }

	//destication
	write(1,"\nEnter destination file name or path:",38);
        fdd=read(0,dname,sizeof(dname));
        write(1,"\nName of file is:",18);
        write(1,dname,fdd);

        if (dname[fdd-1] == '\n')
        {
            dname[fdd-1] = 0;
        }


	file_dis = open(name,O_RDONLY);
        if(file_dis == -1)
        {
                printf("File not able to find\n");
                return -1;
        }
        else
        {
                printf("\nFile is Exists\n");
		size=rfile(name);

		if(size==-1)
		{
			return 0;
		}
		

//file read and display
char file_size_to_read[size];
int new_ret=0;

	         new_ret = read(file_dis,file_size_to_read,sizeof(file_size_to_read));
                 if(new_ret == -1)
                 {
                         printf("Not able to READ, Program not working as it says\n");
                         return -1;
                 }
                 else
                 {
	         //File where we want to copy
		 int fd=0,ret=0;
		 fd= open(dname,O_WRONLY);
                 if(fd == -1)
                 {
                       printf("Not able to locate file, pls check file path\n");
                       return -1;
                 }
                 else
                 {
                      printf("File Opened in write mode\n");
		      ret = write(fd,file_size_to_read,sizeof(file_size_to_read));
                      if(ret == -1)
		      {
			      printf("Not able to Write, Program not working as it says\n");
			      return -1;
		      }
		      else
		      {
			      printf("\nContent of file is Copied\n");
		      }

		 }

                 //printf("\nContent of file is: %s\n",file_size_to_read);
                 }

        }
	
return 0;
}

int rfile(char const filename[])
{
  int ret=0;
  struct stat sbuffer;
 
  ret = stat(filename,&sbuffer);
  if(ret == -1)
  {
		printf("\nstat function failed\n");
		return -1;
  }
  return((int)sbuffer.st_size);
 // char file_size_to_read[(int)sbuffer.st_size];   //this will come in bytes
  

}
