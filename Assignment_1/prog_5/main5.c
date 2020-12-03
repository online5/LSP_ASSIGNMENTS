#include<stdio.h>
#include<fcntl.h>
// Accept name of the file from user and open that File
// Demonstration on how to use make command for accepting command line arguments
// To run this app hit make to build and then type make ARGS="File_Name" run

int main(int argc, char** argv)
{
  int fd;
  fd = open(argv[1], O_RDONLY);
  if(fd != -1)
  {
      printf("File Opened successfully.\n");
      printf("FileDescriptor %d.\n",fd);
  }
  else
  {
    printf("Error: File Not opened.\n");
  }
  close(fd);
  return 0;
}
