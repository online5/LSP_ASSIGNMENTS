#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main()
{
  int fd=-1;
  char* myfifo="/tmp/myfifo"; // Write the path name correctly
  char str[]="Data from the server\n";

  printf("Inside Child 1 as Server(Writer) process\n");
  printf("Demonstration of IPC using named pipe\n");
  printf("Server is running\n\n");

  // Create the FIFO named pipe
  mkfifo(myfifo, 0666);

  //Write data to FIFO
  fd=open(myfifo, O_WRONLY);
  if(fd == -1)
  {
    printf("FileCannot be opened\n");
    return 0;
  }
  write(fd, str, strlen(str)+1);
  close(fd);

  printf("Data is successfully wriitend into the file\n");
  return 0;

}
