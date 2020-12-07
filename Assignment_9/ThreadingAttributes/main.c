#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
/*
// For setting up thread Attributes we need to intialise attribute object
// and set up appropriate attribute values and after using the thread service
// destroy the attribute object as space is allocated for that.

// Attributes that can be altered or added to the thread attributes:

// Scope-ThreadSystemScope(bound), or ThreadProcessScope(unbound)
// Detachstate->PthreadCreateJoinable or PthreadCreateDetached
// SetGuardSize-> For protection against thread stack Overflow.
// Scheduling Policy->SCHED_FIFO, SCHED_SCHEDRR, SCHED_OTHER
// ThreadPrority-> Thread priority mentioned in SCHED_PARAM can be changed
// SetStackSize
// SetStackAddress

*/

//Thread running this function with thread_attributes set
void* run(void* arg)
{
  printf("Inside thread3 run\n");
  int i=0;
  for(i=0; i<=10; i++)
  {
    printf("%d\n", i);
  }
  pthread_exit(NULL);
}

// Thread running this routine with default thread_attributes set
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

//Thread running this function with thread_attributes set
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
  pthread_t thread1, thread2, thread3;
  pthread_attr_t tattr1, tattr2;
  int ret=0, res=0;
  int ret_atr;

  //Creation of thread with default thread attributes
  ret=pthread_create(&thread1, NULL, fun, NULL);
  if(ret != 0)
  {
    printf("Unable to create thread.\n");
    return -1;
  }

  //Creating thread with thread_attributes set
  //Setting detach state of thread2 with property PTHREAD_CREATE_DETACHED
  ret_atr=pthread_attr_init(&tattr1);
  ret_atr=pthread_attr_setdetachstate(&tattr1,PTHREAD_CREATE_DETACHED);
  ret_atr=pthread_attr_setschedpolicy(&tattr1, SCHED_FIFO);
  ret_atr=pthread_attr_setscope(&tattr1, PTHREAD_SCOPE_SYSTEM);
  if(ret_atr != 0 )
  {
    printf("Error: Thread atributes of thread 2 not set\n");
    return -1;
  }

  ret=pthread_create(&thread2, &tattr1, gun, NULL);
  if(ret != 0)
  {
    printf("Unable to create thread2.\n");
    return -1;
  }

  //Creating thread 3 with thread_attributes set
  ret_atr=pthread_attr_init(&tattr2);
  ret_atr=pthread_attr_setdetachstate(&tattr2, PTHREAD_CREATE_DETACHED);
  ret_atr=pthread_attr_setschedpolicy(&tattr2, SCHED_RR);
  ret_atr=pthread_attr_setscope(&tattr2, PTHREAD_SCOPE_SYSTEM);
  if(ret_atr != 0 )
  {
    printf("Error: Thread atributes of thread 3 not set\n");
    return -1;
  }
  ret=pthread_create(&thread3, &tattr2, run, NULL);
  if(ret == -1)
  {
    printf("Unable to create thread3\n");
    return -1;
  }

  pthread_join(thread1,NULL);
  if((ret=pthread_attr_destroy(&tattr1)) != 0)
  {
    printf("Error: attribute object 1 cannot be destroyed\n");
    return -1;
  }
  if((ret=pthread_attr_destroy(&tattr2)) != 0)
  {
    printf("Error: attribute object 2 cannot be destroyed\n");
    return -1;
  }
  return 0;
}
