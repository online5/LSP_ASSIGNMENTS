#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
  printf("Process2 executing\n");
  //Some task
  sleep(4);
  printf("Process2 done with executing\n");
  return 0;
}
