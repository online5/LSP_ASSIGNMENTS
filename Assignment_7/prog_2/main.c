#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
  int ret1, ret2, ret3;
  int status;

  if((ret1=fork()) == 0)
  {
    execl("./process1","",NULL);
  }
  else
  {
    while(wait(&status)>0)
    {
      sleep(1);
    }
    printf("Child process1 done executing.\n");
    printf("Main Parent(Root) is terminating\n");
  }
  return 0;
}
