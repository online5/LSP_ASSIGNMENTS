#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>

void* fun(void* p)
{
  int no;
  int* value=malloc(4);
  printf("Enter Value to return from this thread\n");
  scanf("%d",&no);
  printf("Inside Fun\n");
  *value=no;
  return(value);
}

int main()
{
  pthread_t thread1, thread2;
  int ret=0, res=0;
  int myvalue=10;
  int* result;
  ret=pthread_create(&thread1, NULL, fun, NULL);
  if(ret != 0)
  {
    printf("Unable to create thread.\n");
    return -1;
  }

  pthread_join(thread1,(void**)&result);
  printf("Value from thread is %d\n",*result);
  free(result);
  return 0;
}
