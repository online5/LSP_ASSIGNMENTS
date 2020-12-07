#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
  int ret1, status;
  if((ret1=fork())==0)
  {
    //Child Scope
    execl("./child","",NULL);
  }
  else
  {
    //Parent Scope
    printf("Parent Scope: Waiting for child process to end\n");
    while(wait(&status)>0)
    {
      sleep(1);
    }
    printf("Child Process excecuted Successfully\n");
  }


}
