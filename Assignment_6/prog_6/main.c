/*
6. Write a program which accept directory name from user and create hole in file if size is
less than 1kb & if it is greater than 1kb then truncate the remaining data.
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
  struct stat fstat;
  int fd=0;
  int size=0;
  fd=open(argv[1], O_RDWR);
  int rem=0;
  if(fd == -1)
  {
    printf("Error: File cannot be opened.\n");
    return -1;
  }
  if((stat(argv[1],&fstat)<0))
  {
    printf("Error: File Statistics failed.\n");
    return -1;
  }
  size=fstat.st_size;// asssign size of the file to "size" variable.

  if(size > 1000)
  {
    rem=size-1000;
    if((ftruncate(fd, 1000)<0))
    {
      printf("Error: ftruncate failed.\n");
      return -1;
    }
    printf("File truncated() successfully.\n");
  }
  else
  {
    if((ftruncate(fd, 1000)<0)) // Ftruncate takes fd as first argument
                                //and offset till the file should be trucated.
                                
    {
      printf("Error: ftruncate failed.\n");
      return -1;
    }
    printf("File truncated(i.e extended.) successfully.\n");
  }
  close(fd);
  return 0;
}
