/*
 *4. Write a program which creates single thread and it accept one value from
user and it return some value to the caller thread. 
 *
 */
#include<stdio.h>
#include<pthread.h>
void* myprint()
{
 	 int k;
	 k =11;
	 pthread_exit((void *)k);  //logic will be updated soon, looks having global structure is better idea to return value or global value

}
int main()
{
 pthread_t th1;
 int x =5;
 int *y;
 pthread_create(&th1,NULL,myprint,NULL);
 pthread_join(th1,(void*)&y);
 printf("\n Exit value is [%d]\n",y);
}  
