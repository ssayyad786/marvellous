#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *gun(void *p)
{
	int i=0;
	printf("\nHi from thread gun\n");
}

int main()
{
	pthread_t t1;
	int ret,num=5;

	ret = pthread_create(&t1,NULL,gun,&num);
	pthread_join(t1,NULL);
	
return 0;
}
