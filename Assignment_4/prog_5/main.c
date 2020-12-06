/*
5. Write a program which accept file name and position from user and read 20 bytes from
that position.
*/
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
  struct stat fstat;
  int pos=0, fileSize=0,ret=0;
  int fd=0;
  char buff[30]={'\0'};

  if(argc !=3)
  {
    printf("Error: Invaild parameter.\n");
    printf("Expected format ./File_Name file_to_read position");
    return -1;
  }
  ret =stat(argv[1],&fstat);
  if(ret == -1)
  {
    printf("Error: Stat function error\n");
    return -1;
  }

  pos=atoi(argv[2]);
  fileSize=fstat.st_size;

  if(pos<0 || pos>fileSize)
  {
    printf("Invalid Position.\n");
    return -1;
  }
  fd=open(argv[1],O_RDONLY);
  if(fd == -1)
  {
    printf("File Cannot be opened.\n");
    return -1;
  }

  lseek(fd, pos, SEEK_SET);
  while((ret=read(fd, buff, 20)) > 0)
  {
    if(ret == -1)
    {
      printf("Error: Data could not be read.\n");
    }
    write(1, buff, ret);
  }
  close(fd);
  return 0;
}
