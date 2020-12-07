#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
  pid_t pid;
  printf("Process 2 executing with process ID: %d\n", getpid());
  // Some execution
  sleep(3);
  printf("Process2 done executing...\n");
  return 0;
}
