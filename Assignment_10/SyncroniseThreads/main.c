#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>



pthread_mutex_t lock;

void* ThreadExecute(void* p)
{
  pthread_mutex_lock(&lock);
  int no=0;
  no++;
  printf("Thread %d is executing\n", no);
  for(int i=0; i<0xffffffff; i++);
  printf("Thread %d done executing.\n",no);
  pthread_mutex_unlock(&lock);
}

int main()
{
  pthread_t thread[4];
  if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\n mutex init has failed\n");
        return 1;
    }

  for(int i=0; i<4;i++)
  {
    printf("Creating thread %d\n",i+1);
    pthread_create(&thread[i], NULL, ThreadExecute, NULL);
  }

  printf("Waiting for threads to complete execution\n");
  for(int i=0; i<4;i++)
  {
    pthread_join(thread[i], NULL);
  }
  printf("Threads are executed successfully\n");
  pthread_mutex_destroy(&lock);
  return 0;
}
