#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

// Write a program which is used to increase the priority by 5.
// Note: It is note guranteed that the priority is changed
// as nice system call is just a request to the kernel for
// changing the priority;

int main()
{
  int ret=0;

  ret = nice(0);
  printf("Default priority is %d\n", ret);

  ret = nice(-5);
  printf("Changed the priority of the process %d\n", ret);
  return 0;
}
