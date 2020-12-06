#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

// 2. Write a program which accept file name and mode from user and then open that file in
//specified mode..
/*
file path : Either absolute or relative path of the file that we want to open
        mode :
              O_RDONLY
              O_WRONLY
              O_RDWR
*/

int main(int argc, char* argv[])
{
  int fd;
  char buff[20];
  int ret=0, mode, mode_no;

  if(argc != 3)
  {
    printf("Error: Insufficent arguments given\n");
    return -1;
  }

  printf("Before mode");
  if(strcmp(argv[1],"--help") == 0)
  {
    printf("Format: ./Myexe file_name mode\n");
    printf("ModeOptions: mode=1->O_RDONLY mode=2->O_WRONLY mode=3->O_RDWR \n");
    return -1;
  }

  mode_no=atoi(argv[2]);
  if(mode_no == 1)
  {
    mode=O_RDONLY;
  }
  else if(mode_no == 2)
  {
    mode=O_WRONLY;
  }
  else if(mode_no == 3)
  {
    mode=O_RDWR;
  }
  else
  {
    printf("Error: Enter Valid Mode");
    return -1;
  }
  printf("After mode");
  fd = open(argv[1], mode);
  if(fd == -1)
  {
    printf("Error: File not opened successfuly.\n");
    return -1;
  }
	while((ret=read(fd, buff, strlen(buff))) != 0)
	{
		write(1, buff, ret);
	}
  printf("File opened successfuly with %d file descriptor.\n", fd);
  close(fd);
  return 0;
}
