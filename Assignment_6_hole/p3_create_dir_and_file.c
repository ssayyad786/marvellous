#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>

int main()
{
  char d_name[50];
  char f_name[50];
  char path[100];
  int ret;
  char *source;
  source = (char*)malloc(10*sizeof(char));

        printf("\nEnter name of directory you want to create: ");
        scanf("%s",d_name);

	printf("\nEnter name of file name you want to create: ");
        scanf("%s",f_name);

//logic to create new directory

  ret = mkdir(d_name,0777);

  if(!ret)
  {
          printf("\nDerectory created\n");
  }
  else
  {
          printf("\nNot able to create directory!!!\n");
          return -1;
  }
//creat path for new file to create 
  int size;
  size = strlen(d_name);
  d_name[size] = '/';
  strcat(d_name,f_name);

  printf("\npath: %s\n",d_name);

//
  int fd =0;

  fd = creat(d_name,0777);
  if (fd == -1){
	  printf("\nNot able to create file\n");
	  return -1;
  }
  else
	  printf("\nFile created inside dir\n");


return 0;
//      printf("\n%s\n",d_name);
}

