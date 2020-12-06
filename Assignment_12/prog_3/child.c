#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<fcntl.h>
#include<sys/wait.h>


// User defined signal handler used registered via signal()
// system call
static void sig_handler(int sig_no)
{
  printf("Inside signal handler function\n");
  if(sig_no == SIGINT)
  {
    printf("SIGINT signal recieved\n");
    exit(EXIT_SUCCESS);
  }
  else if(sig_no == SIGHUP)
  {
    printf("SIGHUP signal received\n");
    exit(EXIT_SUCCESS);
  }
  else if(sig_no == SIGUSR1)
  {
    printf("User defined signal 1 recieved\n");
    exit(EXIT_SUCCESS);
  }
  else if(sig_no == SIGUSR2)
  {
    printf("User defined signal 2 recieved\n");
    exit(EXIT_SUCCESS);
  }
  else
  {
    printf("Signal not recognized correctly\n");
    exit(EXIT_FAILURE);
  }

}
int main()
{
  int ret, status;

  printf("Inside child process waiting for a signal to be handled\n");
  printf("Process ID : %d\n", getpid());
  // The process ID is used by kill utilily
  // kill command used in terminal
  // kill -<signal_name> process_id

  if(signal(SIGINT, sig_handler) == SIG_ERR)
  {
    printf("SIGINT signal cannot be handled well\n");
    exit(EXIT_FAILURE);
  }
  if(signal(SIGHUP, sig_handler) == SIG_ERR)
  {
    printf("SIGINT signal cannot be handled well\n");
    exit(EXIT_FAILURE);
  }
  if(signal(SIGUSR1, sig_handler) == SIG_ERR)
  {
    printf("SIGINT signal cannot be handled well\n");
    exit(EXIT_FAILURE);
  }
  if(signal(SIGUSR2, sig_handler) == SIG_ERR)
  {
    printf("SIGINT signal cannot be handled well\n");
    exit(EXIT_FAILURE);
  }

  for(;;)
  // Waiting for getting a signal
  pause();

  return 0;
}
