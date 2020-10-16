/*
 * 3. Write a program which creates single thread and we have to pass
parameter to that thread from main thread. 
 */
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *gun(void *p)
{
	int i;
	int count;
	count=*((int *)p);
	//printf("\ntest\n");
	for(i=1;i<=count;i++)
	{
	printf("\ngun: %d\n",i);
	}
	pthread_exit(NULL);
}



int main()
{
	pthread_t t1,t2;
	int ret,num=5;

	ret = pthread_create(&t1,NULL,gun,&num);
 	if(ret != 0)
	{
		printf("\nNot able to create thread 1\n");
	}

	pthread_join(t1,NULL);


return 0;
}
