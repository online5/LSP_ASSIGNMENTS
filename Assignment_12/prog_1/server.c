#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
// 1. Write a program which creates two process as reader and writer and that processess
// should communicate with each other using FIFO.

int main()
{
  int fd=-1, wtr;
  char* path="/tmp/myfifo"; //Write the path name correctly
  char str[]="Data from the server\n";

  printf("Demonstration of IPC using named pipe\n");
  printf("Server is running\n");

  // Create the FIFO named pipe
  if((mkfifo(path, 0666) == -1))
  {
      printf("Fifo cannot be made\n");
      return -1;
  }
  //Calling open function call to open pipe
  fd=open(path, O_WRONLY);
  if(fd == -1)
  {
    printf("FileCannot be opened\n");
    return -1;
  }

  wtr=write(fd, str, strlen(str)+1);
  if(wtr == -1)
  {
    printf("Data Could not be wriiten successfully\n");
    return -1;
  }
  close(fd);
  printf("Data is successfully wriitend into the file\n");

  return 0;
}
