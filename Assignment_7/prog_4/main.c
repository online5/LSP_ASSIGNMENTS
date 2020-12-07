// 4. Write a program which creates two processess as process2 and process3 and our
// parent process waits till both the processess terminates.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
  int ret1, ret2;
  int status;
  if((ret1=fork())==0)
  {
    //Child Scope
    execl("./proc1","",NULL);
  }
  else
  {
    if((ret2=fork())==0)
    {
      execl("./proc2", "", NULL);
    }

    while(wait(&status)>0)
    {
      sleep(1);
    }
    printf("All processes done executing...\n");
    printf("Parent process terminating\n");
  }
  return 0;
}
