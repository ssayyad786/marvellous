#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
char * format(char *);
int main()
{
	char copy_f_name[20] = "demo";
        char *source;
	source = (char*)malloc(10*sizeof(char));


	printf("\nEnter directory name from\nwhere you want to copy 10 bytes from each regular file: ");
	scanf("%s",source);

	DIR *dir;
	dir = opendir(source);
        if(dir == NULL)
        {
                printf("\nNot able to open diretory\n");
		return -1;
        }

	struct dirent  *entry;
	struct stat buffer;

 // format path to open in dir
        int size;
        size = strlen(source);
	source[size] = '/';
//	printf("\n\nstring is : %s\n\n",source);
        char file_copy_content[1000];

	while((entry = readdir(dir)) != NULL)
        {
		char temp[50];
		char file_path[50];
		char file_content[1000];
		strcpy(temp,entry->d_name);  //copy string from structure   "name of file"
		strcpy(file_path,source);
		strcat(file_path,temp);     //this contains relative full path

		//printf("\n\n%s : \n\n",file_path);
                //printf("%s : ",entry->d_name);
                if (stat(file_path, &buffer) < 0)
                {
                printf("Error while retriving statistics of file\n");
                return -1;
                }
                //check file type
                if (S_ISREG(buffer.st_mode))
                {
			//printf("\nHello \n");
			int file_dis = 0;
			int new_ret=0;
			file_dis = open(file_path,O_RDONLY);
			if(file_dis == -1)
                        {
                                 printf("File not able to find file\n");
                                 return -1;
                        }
			new_ret = read(file_dis,file_content,10);
			if(new_ret == -1)
                        {
                                 printf("Not able to READ, Program not working as it says\n");
                                return -1;
                        }

		}
		strcpy(temp,"");
		strcat(file_copy_content,file_content);
		strcpy(file_content,"");
		
	}

//	printf("\n%s\n",file_copy_content);
//  Now write content to file named demo
        int file_dis1=0;
       
        file_dis1 = open("demo",O_CREAT | O_APPEND | O_WRONLY);	
	write(file_dis1,file_copy_content,strlen(file_copy_content));

	printf("\n\nOpen file demo, content of every regular file from %s is copied (10bytes)\n#vim demo\n\n",source);


return 0;
}
