#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
//5. Write a program which is used
//to get thread id inside its thread function.

void* fun(void* p)
{
  printf("Thread id =%ld\n", pthread_self());
  pthread_exit(NULL);
}

int main()
{
  pthread_t thread1, thread2;
  int ret=0, res=0, myvalue=10;

  ret=pthread_create(&thread1, NULL, fun, NULL);
  if(ret != 0)
  {
    printf("Unable to create thread.\n");
    return -1;
  }

  pthread_join(thread1,NULL);
  printf("In Main, Thread id is =%ld\n", thread1);
  return 0;
}
