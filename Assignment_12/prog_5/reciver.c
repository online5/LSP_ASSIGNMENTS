#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>

void user_signal_hangler(int sig_no)
{
  printf("SIGUSR1 signal recieved\n");
  exit(EXIT_SUCCESS);
}

int main()
{
  int ret;
  printf("Inside Reciever Process\n");
  
  if(signal(SIGUSR1, user_signal_hangler) == SIG_ERR)
  {
    printf("SIGINT signal cannot be handled :/");
    exit(EXIT_FAILURE);
  }
  for(;;)
  {
    pause();
  }
  return 0;
}
