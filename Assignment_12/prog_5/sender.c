#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char* argv[])
{
  sleep(3);
  printf("Inside Senders process\n");
  int ret;
  ret=kill(atoi(argv[0]),SIGUSR1);
  if(ret != 0)
  {
    printf("Signal could not be send\n");
    exit(EXIT_FAILURE);
  }
  else
  {
    printf("Signal send successfully\n");
  }
  return 0;
}
