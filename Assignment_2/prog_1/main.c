#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
// 1. Write a program which accept file name from user and open that file.

int main(int argc, char** argv)
{
  int fd;

  if(argc != 2)
  {
    printf("Error: Insufficent arguments given\n");
    return -1;
  }
  fd = open(argv[1], O_RDONLY);
  if(fd == -1)
  {
    printf("Error: File not opened successfuly.\n");
    return -1;
  }

  printf("File opened successfuly with %d file descriptor.\n", fd);
  close(fd);


  return 0;
}
