#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

static void sigint_handler(int sig_no)
{
  printf("Caught signal SIGINT with signal_no %d\n", sig_no);
  exit(EXIT_SUCCESS);
}

int main()
{
  int ret=0;
  printf("Inside Child Process\n");
  if(signal(SIGINT, sigint_handler) == SIG_ERR)
  {
    printf("Cannot handle signalt catched by the parent process\n");
    exit(EXIT_FAILURE);
  }
  for(;;)
  {
    // Waiting for the parent to send signal to child
    pause();
  }
  return 0;
}
