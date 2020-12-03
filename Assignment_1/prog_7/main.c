//7. Write a program which accept file name and read first 5 characters from it.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define MAX_BUFFER 102
int main(int argc, char *argv[])
{
  int fd=0,ret;
  char buff[256];
  fd=open(argv[1], O_RDONLY);
  if(fd == -1)
  {
    printf("Error: File cannot be opened.\n");
  }
  else
  {
    ret=read(fd, buff, 5);
    if(ret != -1)
    {
      printf("%s", buff);
    }
    else
    {
      printf("File contents could not be read.\n");
      close(fd);
      return -1;
    }
  }

  return 0;
}
