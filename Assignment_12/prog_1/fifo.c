// 1. Write a program which creates two process as reader and writer and that processess
// should communicate with each other using FIFO.
#include<string.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
  int pid1, pid2, ret;
  int status;
  if((pid1=fork()) == 0)
  {
    execl("./reader","",NULL);
  }
  else
  {
    printf("Inside Parent scope\n");
    if((pid2=fork()) == 0)
    {
      execl("./writer","",NULL);
    }
    while(wait(&status)>0)
    {
      sleep(1);
    }
    printf("All Child process executed successfully\n");
  }

  return 0;
}
