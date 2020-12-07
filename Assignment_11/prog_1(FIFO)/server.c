//Named Pipe

#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

// 1. Write a program which is used to create unnamed pipe. Parent process creates new child
// process and both the processess will communicate with each other.
int main()
{
  int fd;
  char* myfifo="/tmp/myfifo";
  printf("Demonstration of IPC using Named Pipe\n");
  printf("Server is running\n");

  mkfifo(myfifo, 0666);

  // Write data to the FIFO
  fd=open(myfifo, O_WRONLY);
  write(fd, "Marvellous Message",strlen("Marvellous Message")+1);
  close(fd);

  printf("Data successfully written in named pipe\n");
  return 0;

}
