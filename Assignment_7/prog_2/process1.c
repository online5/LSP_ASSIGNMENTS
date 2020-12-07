#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
  printf("Inside Level1 hierarchy, process1 executing.\n");
  int ret, status;

  sleep(3);

  if((ret=fork())==0)
  {
    execl("./process2","",NULL);
  }
  else
  {
    //process1: parent scope
    while(wait(&status)>0)
    {
      sleep(1);
    }
    printf("Child process2 is done executing\n");
    printf("Level1 process is terminating\n");
  }
}
