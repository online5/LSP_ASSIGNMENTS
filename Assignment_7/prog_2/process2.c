#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
  printf("Inside Level2 hierarchy, process2 executing.\n");
  int ret;
  int status;
  sleep(3);

  if((ret=fork())==0)
  {
    execl("./process3","",NULL);
  }
  else
  {
    //process2: parent scope
    while(wait(&status)>0)
    {
      sleep(1);
    }
    printf("Child process3 is done executing\n");
    printf("Level2 process is terminating\n");
  }
}
