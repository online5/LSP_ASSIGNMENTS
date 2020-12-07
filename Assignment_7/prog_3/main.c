/*
3. Write a program which creates three diffrent processess internally as process2,
process3, process4.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
  int ret1, ret2, ret3;
  int status;
  if((ret1=fork())==0)
  {
    //Process 1 created and executed here
    execl("./process1","",NULL);
  }
  else
  {
    if((ret2=fork()) == 0)
    {
      //Process 2 created and excecuted here
      execl("./process2","",NULL);
    }
    else
    {
      if((ret3=fork()) == 0)
      {
        execl("./process3","",NULL);
      }
    }

    // Parent process will wait for all processes to end
    // Only after that parent process will terminate
    while((wait(&status)>0))
    {
      sleep(1);
    }
    printf("All processes are done with there execution\n");
  }

}
