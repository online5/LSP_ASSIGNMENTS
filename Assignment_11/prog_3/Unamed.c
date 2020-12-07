#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


#define ReadEnd 0
#define WriteEnd 1

int main()
{
  int pipeFDs[2];
  int ret=0;
  char buf;
  const char* msg="Bigger Stronger Leaner\n";
  printf("Demonstration of IPC using Unamed Pipes\n");

  if(pipe(pipeFDs)<0)
  {
    printf("Pipe Creation Failed\n");
    exit(-1);
  }

  pid_t cpid=fork();
  if(cpid<0)
  {
    printf("Fork Failed\n");
    exit(-1);
  }
  if(0 == cpid)
  {
    printf("Child Process is Running\n");
    close(pipeFDs[ReadEnd]);
    printf("Sending Data to Parent process\n");
    write(pipeFDs[WriteEnd], msg, strlen(msg));
    printf("Data Sent Successfully\n");
    close(pipeFDs[WriteEnd]);
    exit(0);
  }
  else
  {
    printf("Parent Process Running\n");
    close(pipeFDs[WriteEnd]);
    while((ret=read(pipeFDs[ReadEnd], &buf, 1))>0)
    {
      write(1,&buf,ret);
    }
    printf("Data is Read from the child\n");
    wait(NULL);
    exit(0);
  }
  return 0;
}
