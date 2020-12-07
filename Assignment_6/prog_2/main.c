#include<string.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

#include<stdlib.h>
#include<sys/stat.h>
//2. Write a program which create hole of size 1kb at the end of file.
int main(int argc, char* argv[])
{

  if(argc != 2)
  {
    printf("Enter Enter Valid Parameters.\n");
    printf("Enter ./myexe File_Name\n");
    return -1;
  }
  int fd=0,ret=0;
  char buff[30]={'\0'};
  fd=open(argv[1], O_RDWR);
  if(fd == -1)
  {
    printf("Error: Cannot Open file in read write mode.\n");
    return -1;
  }

  if((write(fd,"start",strlen("start")))<0)
  {
	printf("Error: Write call failed at start.\n");
	return -1;
  }

  ret=lseek(fd,1000,SEEK_END);
  if(ret == -1)
  {
    printf("Error: lseek failed.\n");
    return -1;
  }
  ret=write(fd, "abc", strlen("abc"));
  if(ret == -1)
  {
    printf("Error: Data could not be written after holes.\n");
    return -1;
  }
  printf("Data successfully Written.\n");
  if((lseek(fd, -3, SEEK_CUR )) < 0 )
  {
    printf("lseek after write failed.\n");
    return -1;
  }
  while((ret=read(fd, buff,10)) > 0)
  {
    if(ret == -1)
    {
      printf("Error: Read operation failed.\n");
      exit(EXIT_FAILURE);
    }
    printf("ret: %d\n",ret);
    write(1, buff, ret);
  }
  printf("\nRead successfully.\n");

  return 0;
}
