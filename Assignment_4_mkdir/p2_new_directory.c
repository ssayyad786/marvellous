/*
Program to accept directory name from user and create it.

 */

#include <sys/stat.h> 
#include <stdio.h> 

int main()
{
  char d_name[50];
  int ret;

	printf("\nEnter name of directory you want to create: ");
	scanf("%s",d_name);

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

return 0;
//	printf("\n%s\n",d_name);
}
