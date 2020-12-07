#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>
// 1. Write a program which creates 4 number of threads and our main thread
// waits till all the thread terminates.


void* ThreadExecute(void* p)
{
  printf("Thread %d is executing\n", *(int*)p);
  for(int i=0; i<0xffffffff; i++);
  printf("Thread %d done executing.\n",*(int*)p);
}

int main()
{
  pthread_t thread[4];

  for(int i=0; i<4;i++)
  {
    printf("Creating thread %d\n",i+1);
    pthread_create(&thread[i], NULL, ThreadExecute, (void*)&i);
  }

  printf("Waiting for threads to complete execution\n");
  for(int i=0; i<4;i++)
  {
    pthread_join(thread[i], NULL);
  }
  printf("Threads are executed successfully\n");

  return 0;
}
