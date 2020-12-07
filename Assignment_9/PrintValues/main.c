#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>

void* fun(void* par)
{
  printf("Inside thread1\n");
  int i=0;
  for(i=1; i<=10 ;i++)
  {
    printf("%d\n",i);
  }
  pthread_exit(NULL);
}
void* gun(void* pat)
{
  printf("Inside thread2\n");
  int i=0;
  for(i=1; i<=10 ;i++)
  {
    printf("\t%d\n",i);
  }
  pthread_exit(NULL);
}

int main()
{
  pthread_t thread1, thread2;
  int ret=0, res=0;

  ret=pthread_create(&thread1, NULL, fun, NULL);
  if(ret != 0)
  {
    printf("Unable to create thread.\n");
    return -1;
  }

  ret=pthread_create(&thread2, NULL, gun, NULL);
  if(ret != 0)
  {
    printf("Unable to create thread2.\n");
    return -1;
  }
  pthread_join(thread1,NULL);
  pthread_join(thread2,NULL);
  return 0;
}
