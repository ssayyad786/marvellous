/*
 * 2. Write a program which creates two thread , first thread print numbers
from 1 to 500 & other thread print the numbers from 500 to 1.
 */
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *gun()
{
	int i;
	//printf("\ntest\n");
	for(i=1;i<=10;i++)
	{
	printf("\ngun: %d\n",i);
	}
	pthread_exit(NULL);
}

void *fun()
{
        int i;
        //printf("\ntest\n");
        for(i=10;i>=1;i--)
        {
        printf("\nfun: %d\n",i);
        }
        pthread_exit(NULL);
}


int main()
{
	pthread_t t1,t2;
	int ret,ret1;

	ret = pthread_create(&t1,NULL,gun,NULL);
 	if(ret != 0)
	{
		printf("\nNot able to create thread 1\n");
	}
	ret = pthread_create(&t2,NULL,fun,NULL);
        if(ret != 0)
        {
                printf("\nNot able to create thread 2\n");
        }

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);


return 0;
}
