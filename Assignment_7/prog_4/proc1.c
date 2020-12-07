#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
  printf("Process1 executing.....\n");
  // Some process
  sleep(4);
  printf("Process1 done with executing\n");

  return 0;
}
