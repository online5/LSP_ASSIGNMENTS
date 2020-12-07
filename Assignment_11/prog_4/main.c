#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<sys/types.h>

// 4. Write a program which map any file in memory and read the data from that mapped file.
int main(int argc, char* argv[])
{
  struct stat fs;
  off_t len;
  char* p;
  int fd, ret;
  char str[30];

  if(argc != 2)
  {
    fprintf(stderr, "usage: %s <fileName>\n", argv[0]);
    return 1;
  }
  //Open that file
  fd=open(argv[1], O_RDONLY);
  if(fd == -1)
  {
    printf("Error: FileCannot be opened\n");
    return 1;
  }

  if(fstat(fd, &fs) == -1)
  {
    printf("Error: fstat failed\n");
    return 1;
  }
  if(!S_ISREG(fs.st_mode))
  {
    fprintf(stderr,"%s is not file\n", argv[1]);
    return 1;
  }

  p = mmap(0, fs.st_size, PROT_READ, MAP_SHARED, fd, 0);
  if(p == MAP_FAILED)
  {
    printf("Error: Map failed\n");
    return 1;
  }

  //Closing the file because mmap while using the file descriptor
  //increments the reference count of the file by 1;
  if(close(fd) == -1)
  {
    printf("Error: Close failed\n");
    return -1;
  }

  for(len=0; len<fs.st_size; len++)
  {
    printf("%c",p[len]);
  }
  printf("\n");

  // Unmapping the mapped file from the memory
  if(munmap(p, fs.st_size) == -1)
  {
    printf("Error: Unmapping of the file failed\n");
    return 1;
  }

  return 0;
}
