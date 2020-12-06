// 5. Write a program which creates two process as sender and receiver in which sender process
// send signal to receiver process.
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
  int pid_of_rec, pid_of_send;
  int fd;
  int status;
  char str[30];// buffer for storing pid value
  
  if((pid_of_rec=fork()) > 0)
  {
    sprintf(str,"%d",pid_of_rec);
    // Parent Process
    if((pid_of_send=fork()) == 0)
    {
      execl("./sender",str,NULL);
    }
  }
  else
  {
    execl("./reciever","",NULL);
    // reciever process
  }
  while(wait(&status)>0)
  {
    sleep(1);
  }
  printf("Both sender reciever process executed successfully\n");
  return 0;
}
