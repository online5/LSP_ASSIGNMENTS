#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void* Fun(void* p)
{
  int no=10000;
  printf("Thread1 executing\n");
  printf("Inside Fun\n");
  for(int i=0;i<(int)p;i++)
  {
    printf("%d\n",i);
  }
  pthread_exit(no);
}

void* Gun(void* p)
{
  int no=100;
  printf("Thread 2 execiting\n");
  printf("Inside Gun\n");
  for(int i=0; i<=(int)p; i++)
  {
    printf("%d\n",i);
  }
  pthread_exit(NULL);
}


int main()
{
  pthread_t thread1, thread2;

  int no1=2, no2=3;
  int ret=0, result=0;
  int res=0, value=1000;
  ret=pthread_create(&thread1, NULL,Fun, value);
  if(ret == -1)
  {
    printf("Unable to create first thread\n");
    return -1;
  }
  ret=pthread_create(&thread2, NULL, Gun,value);
  if(ret == -1)
  {
    printf("Unable to create second thread\n");
    return -1;
  }

  pthread_join(thread1,&res);
  pthread_join(thread2,NULL);
  printf("Value from fun function is %d\n",(res));
  return 0;
}
