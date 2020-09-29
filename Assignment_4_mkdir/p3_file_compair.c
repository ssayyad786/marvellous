/*
 * This code will compair content of two files strictly
 * even space shold match in both files
 *
 */
#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>

int compair_file(char *,char *);
int return_file_size(char const name[]);

int main()
{
	int ret=0;
	char f1_name[50],f2_name[50];

	printf("\nEnter first name of file you want to compair: ");
        scanf("%s",f1_name);

	printf("\nEnter first name of file you want to compair: ");
        scanf("%s",f2_name);

        ret = compair_file(f1_name,f2_name);
	if(ret == -1)
	{
		 printf("\nContent of file is not equal!!!\n");
		 return -1;
	}
	else
	{
         	 printf("\n*********Content of file is equal************\n");
	}


	return 0;
}

int compair_file(char *f1,char *f2)
{
	int offset;
	int fd1,fd2,ret1=0,ret2=0;
	char a,b;
	int size1=0,size2=0;
        
	fd1 = open(f1,O_RDONLY);
	if(fd1 == -1)
	{
		printf("\nNot able to open file 1\n");
	}
        fd2 = open(f2,O_RDONLY);
        if(fd2 == -1)
        {
                printf("\nNot able to open file 2\n");
        }
 	size1=return_file_size(f1);
	size2=return_file_size(f2);
        if(size1 != size2)
	{
		//printf("\nContent of file ish not equal!!!\n");
		return -1;
	}
//Read comtent of both files
       char buf_file_1[size1];
       char buf_file_2[size2];

       ret1=read(fd1,buf_file_1,sizeof(buf_file_1));
       ret2=read(fd2,buf_file_2,sizeof(buf_file_2));      
       if((ret1 == -1) || (ret2 == -1))
        {
                printf("\nNot able to read file 1\n");
		return -1;
        }
        int cnt = 0;
	do
	{
           if(buf_file_1[cnt]!=buf_file_2[cnt])
	   {
              return -1;
	   }
	   cnt++;
//	   printf("\n%c\n",buf_file_1[cnt]);
	}while(size1!=cnt);

//	return 0;
}

int return_file_size(char const name[])
{
	int ret=0;
	struct stat sbuffer;

	ret = stat(name,&sbuffer);
	if(ret == -1)
	  {
                printf("\nstat function failed\n");
                return -1;
          }
  return((int)sbuffer.st_size);

}
