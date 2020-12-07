#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

// 2. Write a program which creates two processess and that two processess can communicate
// with each other by using concept of shared memory.

int main()
{
  int ret=0, ret1=0, value=0;
  int status=0;
  if((ret=fork()) == 0)
  {
    printf("Child1 executing Server Process\n");
    execl("./Server","",NULL);
  }
  else
  {
    if((ret1=fork()) == 0)
    {
      printf("Child2 executing Client Process\n");
      execl("./Client","",NULL);
    }
    else
    {
      printf("Parent process waiting\n");
      while((value=wait(&status))>0)
      {
        sleep(1);
      }
    }

  }
  return 0;
}
