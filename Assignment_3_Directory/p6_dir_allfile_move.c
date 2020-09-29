#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
int main()
{

 int  read_count=0;
 char dir_name[200];
 char dest_name[200];
// char cw_dir[200];
 char msg1[50] = "\nEnter Source directory name or path: ";
 char msg2[50] = "\nEnter Destination directory name or path: ";
        write(1,msg1,sizeof(msg1));
        read_count=read(0,dir_name,sizeof(dir_name));

	if(dir_name[read_count-1]=='\n')
	{
		dir_name[read_count-1] = 0;
	}

	read_count=0;

	write(1,msg2,sizeof(msg2));
        read_count=read(0,dest_name,sizeof(dest_name));

        if(dest_name[read_count-1]=='\n')
        {
                dest_name[read_count-1] = 0;
        }


//Fetch Current working directory for future reference//
//start

//	getcwd(cw_dir,sizeof(cw_dir));
//	printf("Current working directory is %s\n",cw_dir);
        
	char* cw_dir = realpath(dest_name, NULL);
	if(cw_dir == NULL){
         printf("cannot find file with name[%s]\n", dest_name);
        } else{
         printf("path[%s]\n", cw_dir);
        }
//End of current dir logic 


        char* bb_dir = realpath(dir_name, NULL);
        if(bb_dir == NULL){
         printf("cannot find file with name[%s]\n", dir_name);
        } else{
         printf("path[%s]\n", bb_dir);
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

        int delete_status=0;  
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
			char file_content[(int)buffer.st_size];
			int file_dis = 0;
			int new_ret=0;
			int func=0;
			char tempfilename[100];

			//file copy logic starts
			//

			file_dis = open(entry->d_name,O_RDONLY);
			if(file_dis == -1)
                        {
               			 printf("File not able to find file\n");
                	         return -1;
        		}
			new_ret = read(file_dis,file_content,sizeof(file_content));
                        if(new_ret == -1)
                 	{
                        	 printf("Not able to READ, Program not working as it says\n");
                         	return -1;
                 	}
                       // printf("\nContent of file is: %s\n",file_content);
		       int temp_fd=0;
		       int r_v=0;
		       char temp_cw_dir[200];  //this step so value current working directory is stored
		       strcpy(tempfilename,entry->d_name);
		       //strcpy(temp_cw_dir,cw_dir);
		       //strcat(temp_cw_dir,"/");
		       //strcat(temp_cw_dir,tempfilename);
		       //printf("\n*******%s******\n",temp_cw_dir);
                       //r_v= strlen(temp_cw_dir);
		      // printf("****%d\n",r_v);
                      
		     //   cwk_path_get_absolute(cw_dir, tempfilename, temp_cw_dir, sizeof(temp_cw_dir));                  
		       //     temp_fd = open(temp_cw_dir,O_RDWR);
		         //   if(temp_fd == -1)
			   // {
			//	printf("Unable to open file");
			//	return -1;
			  //  }

                           DIR *dir_n;
              //             struct dirent  *entry_n;
        			dir_n = opendir(cw_dir);
        			if(dir_n == NULL)
        			{
        			        printf("\nNot able to open diretory\n");
       				}
				int location=0;
        			location = chdir(cw_dir);
				if(location == -1)
      				{
               			  printf("Check Directory Path or Directory not present\n");
             			  return -1;
        			}

                            //   temp_fd = open(tempfilename,O_RDWR);
			      // if(temp_fd == -1)
			      // {
				  //     printf("Unable to open file");
				//      return -1;
				//} 

                               int create_fd;
			       create_fd = creat(tempfilename,0x777);
			       if(create_fd == -1)
   				{
				printf("Unable to create the file\n");
				}

                                temp_fd = open(tempfilename,O_RDWR);
                                if(temp_fd == -1)
                                {
                                       printf("Unable to open file");
                                      return -1;
                                }

                                int wr_ret;
				wr_ret =  write(temp_fd,file_content,sizeof(file_content));
				if(wr_ret == -1)
				{
                        	printf("Not able to Write, Program not working as it says\n");
                	        return -1;
		                }
				else{
					printf("\n*******File: %s, Copied Sussfully*******\n",tempfilename);
				}


               //Go Back to source location 

				DIR *dir_b;
              //             struct dirent  *entry_n;
                                dir_b = opendir(bb_dir);
                                if(dir_b == NULL)
                                {
                                        printf("\nNot able to open diretory\n");
                                }
                                int location_1=0;
                                location_1 = chdir(bb_dir);
                                if(location_1 == -1)
                                {
                                  printf("Check Directory Path or Directory not present\n");
                                  return -1;
                                }




			
		}
	}


  	
	
}


