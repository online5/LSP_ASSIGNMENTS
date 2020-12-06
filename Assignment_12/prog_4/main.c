#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
/*
4. Write a program which accept user defined signal from terminal.
*/

void sig_handler(int sig_no)
{
  if(sig_no == SIGUSR1)
  {
    printf("SIGNAL: SIGUSR1 handled successfully \n");
    exit(EXIT_SUCCESS);
  }
  else if(sig_no == SIGUSR2)
  {
    printf("SIGNAL: SIGUSR2 handled successfully \n");
    exit(EXIT_SUCCESS);
  }
  else
  {
    printf("ERROR: Invalid signal at input\n");
    exit(EXIT_FAILURE);
  }
}

int main()
{
  printf("Program for handling user defined signals from the terminal\n");
  if((signal(SIGUSR1, sig_handler)) == SIG_ERR)
  {
    printf("Error: SIGUSR1 signal cannot be handled\n");
    exit(EXIT_FAILURE);
  }
  if((signal(SIGUSR2, sig_handler)) == SIG_ERR)
  {
    printf("Error: SIGUSR2 signal cannot be handled\n");
    exit(EXIT_FAILURE);
  }
  for(;;)
  // Function to wait for accepting signal
  pause();
  return 0;
}
