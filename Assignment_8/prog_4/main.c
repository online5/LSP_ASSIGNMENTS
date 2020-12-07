#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/resource.h>

int main()
{
  pid_t pid;
  int ret=0;
  pid=getpid();
  printf("Priority of the process %d\n", getpriority(PRIO_PROCESS, pid));
  ret=setpriority(PRIO_PROCESS,0,-20);
  printf("Priority of the process %d\n%d\n", getpriority(PRIO_PROCESS, pid), ret);
  return 0;
}
