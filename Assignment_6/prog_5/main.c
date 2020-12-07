/*
5. Write a program which accept file name from user and offset, remove all the data from
that offset.
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
/*
Shrink or extend the size of each FILE to the specified size

       A FILE argument that does not exist is created.

       If a FILE is larger than the specified size, the extra data is lost.
       If a FILE is shorter, it is extended and the sparse extended part
       (hole) reads as zero bytes.


*/

int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    printf("Enter ./Executable-file FileName Offset.\n");
    return -1;
  }
  int fd=0, ret=0;
  int size=0;
  int offset=atoi(argv[2]);
  char buff[30]={'\0'};

  fd=open(argv[1], O_RDWR);

  if(fd == -1)
  {
    printf("Error: FileCannot be opened.\n");
    return -1;
  }
  if((ftruncate(fd,offset)<0))
  {
    printf("Error: Ftruncate till the offset. byte.\n");
    return -1;
  }

  printf("File truncated.\n");
  close(fd);
  return 0;
}
