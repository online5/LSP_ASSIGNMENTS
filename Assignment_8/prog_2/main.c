#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
  int ret1=0, ret2=0;

  if((ret1=fork() == 0))
  {
    printf("Child Process 1 executing file operations");
    execl("./process1","",NULL);
  }
  else
  {
    if((ret2=fork()) == 0)
    {
      printf("Child Process 2 executing file operations");
      execl("./process2","",NULL);
    }
    printf("Parent Process Execution Completed\n");
  }
  return 0;
}
