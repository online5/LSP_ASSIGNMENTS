//Program to demostrate communication between
//Related processes via signals

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void sighup();
void sigint();
void sigquit();

int main()
{
  int pid;
  if((pid = fork()) < 0)
  {
    exit(1);
  }

  if(pid == 0)
  {
    signal(SIGHUP, sighup);
    signal(SIGINT, sigint);
    signal(SIGQUIT, sigquit);
    for(;;);
  }
  else
  {
    printf("\nPARENT: Sending SIGHUP\n\n");
    kill(pid, SIGHUP);
    sleep(3);

    printf("\nPARENT: sending SIGINT\n\n");
    kill(pid,SIGINT);
    sleep(3);

    printf("\nPARENT: sending SIGQUIT");
    kill(pid, SIGQUIT);
    sleep(3);
  }
}

void sighup()
{
  signal(SIGHUP, sighup);
  printf("CHILD: I have recieved a SIGHUP\n");
}
void sigint()
{
  signal(SIGINT, sigint);
  printf("\nCHILD: I have recieved a SIGINT\n");
}
void sigquit()
{
  printf("\nParent process kill child\n");
  exit(0);
}
