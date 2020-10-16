/*
 *5. Write a program which creates two threads by using pthread API, where
one thread count number of capital characters from demo.txt file and other
threads count number of small characters from same file. 
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int fd;

static int capital = 0, small = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static void *
threadcountCapital ()
{
  int loc, j, s;
  s = pthread_mutex_lock (&mtx);
  fd = open ("demo.txt", O_RDONLY);
  char letter[1];
  while (read (fd, letter, 1))
    {				//s = pthread_mutex_lock (&mtx);
      if ((letter[0] >= 'A') && (letter[0] <= 'Z'))
	capital++;
      //s = pthread_mutex_unlock (&mtx);
    }
  s = pthread_mutex_unlock (&mtx);
  return NULL;
}

static void *
threadcountSmall ()
{
  int loc, j, s;
  s = pthread_mutex_lock (&mtx);
  fd = open ("demo.txt", O_RDONLY);
  char letter[1];
  while (read (fd, letter, 1))
    {				//s = pthread_mutex_lock (&mtx);
      if ((letter[0] >= 'a') && (letter[0] <= 'z'))
	{			//printf("\n%c\n",letter[0] );
	  small++;
	}
      // s = pthread_mutex_unlock (&mtx);
    }
  s = pthread_mutex_unlock (&mtx);
  return NULL;
}

int
main (int argc, char *argv[])
{
  pthread_t t1, t2;
  int s;
  s = pthread_create (&t1, NULL, threadcountCapital, NULL);
  s = pthread_create (&t2, NULL, threadcountSmall, NULL);

  s = pthread_join (t1, NULL);
  s = pthread_join (t2, NULL);

  printf ("capital = %d\n", capital);
  printf ("small = %d\n", small);

  return 0;
}
