#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
  int ret=0;
  if((ret = fork()) == 0)
  {
    printf("Child process 1 is created by parent\n");
    execl("./ExecuteToListFiles","",NULL);
  }
  else
  {
    printf("Parent process Executing\n");
  }
  return 0;
}
