/*
3. Write a program which creates one child process ,
child process write something in
unamed pipe and parent process read the data from that pipe.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
  int ret=0;

  if((ret=fork()) == 0)
  {
    //Child Process Communication

  }
  else
  {
    // Parent Process Communication

  }
  return 0;
}
