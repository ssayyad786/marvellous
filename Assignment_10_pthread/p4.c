/*
 *
 * 4. Write a program which creates two thread , and by using appropriate
synchronization technique avoid the scheduling problem.
 */
#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
#include <stdlib.h>


static int glob = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static void *			/* Loop 'arg' times incrementing 'glob' */
threadFunc (void *arg)
{
  int loops = *((int *) arg);
  int loc, j, s;
  for (j = 0; j < loops; j++)
    {
      s = pthread_mutex_lock (&mtx); //lock
      loc = glob;
      loc++;
      glob = loc;
      s = pthread_mutex_unlock (&mtx);   //end lock
    }
  return NULL;
}

int main (int argc, char *argv[])
{
  pthread_t t1, t2;
  int loops, s;
  loops = 10000000;
  s = pthread_create (&t1, NULL, threadFunc, &loops);
  s = pthread_create (&t2, NULL, threadFunc, &loops);

  s = pthread_join (t1, NULL);
  s = pthread_join (t2, NULL);

  printf ("glob = %d\n", glob);
  return 0;
}
