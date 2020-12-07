// 5. Write a program which is used to create deamon process.
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<linux/fs.h>

/*
A daemon is a process that runs in the background, not connecting to any control-
ling terminal. Daemons are normally started at boot time, are run as root or some
other special user (such as apache or postfix), and handle system-level tasks
*/

// Syntax for creating daemon process
// #include <unistd.h>
// int daemon (int nochdir, int noclose);

// if nochdir is zero then daemon process will change its directory to root.
// if not zero then the current directory will remain the same as that of parent.
// if noclose is nonzero then daemon will not close all open file descriptors
// if it is zero then it will close all open file descriptors.
int main()
{
  int ret;

  if((ret=daemon(0, 0)) == -1)
  {
    printf("Daemon process could not be created successfully\n");
    return -1;
  }
  return 0;
}
