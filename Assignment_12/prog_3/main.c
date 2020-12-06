#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>

// Write a program which creates such a process
// which accept signals from the terminal.
int main()
{
  int ret=0;
  int status;

  if((ret=fork()) == 0)
  {
    execl("./child","",NULL);
  }
  else
  {
    //Parent scope
    while(wait(&status)>0)
    {
      sleep(1);
    }
    printf("Child process executed successfully\n");
  }
}
