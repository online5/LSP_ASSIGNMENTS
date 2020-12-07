//1. Write a program which creates two process as reader and writer and that processess
//should communicate with each other using FIFO.
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>

#define MAX_BUF 1024

int main()
{
  int fd;
  char* myfifo = "/tmp/myfifo";
  char buf[MAX_BUF];

  printf("Demonstration of IPC using Named pipe");

  printf("Client Process is running");

  fd=open(myfifo, O_RDONLY);
  read(fd, buf, MAX_BUF);
  printf("Recienvec data is: %s\n", buf);
  close(fd);

  return 0;
}
