#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
#include<sys/wait.h>
// 2. Write a program which creates child process and parent process will communicate with
// child process by sending signals.

void send_signal(int pid)
{
  int ret=0;
  ret=kill(pid, SIGINT);
  if(ret == 0)
  {
    printf("Successfully send signal to child\n");
  }
  else
  {
    printf("Error: Signal cannot be sent to child\n");
  }
}

int main()
{
  int ret, status;
  int return_value=0;
  if((ret=fork()) == 0)
  {
    // Child Process
    execl("./child","",NULL);
  }
  else
  {
    // Parent process with ret containing pid of process
    //Call to sleep will ensure that child process will execute first
    sleep(5);
    send_signal(ret);
    while(wait(&status)>0)
    {
      sleep(1);
    };
    printf("Child Successfully executed\n");
  }
  return 0;
}
