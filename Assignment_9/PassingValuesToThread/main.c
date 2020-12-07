#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>

void* fun(void* p)
{
  printf("Value from Main thread %d\n", (*(int*)p));

  printf("Inside Fun\n");
  pthread_exit(NULL);
}
int main()
{
  pthread_t thread1, thread2;
  int ret=0, res=0;
  int valueToPass=10;
  ret=pthread_create(&thread1, NULL, fun, &valueToPass);
  if(ret != 0)
  {
    printf("Unable to create thread.\n");
    return -1;
  }


  pthread_join(thread1,NULL);

  return 0;
}
