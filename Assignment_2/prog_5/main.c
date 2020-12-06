#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

//5. Write a program which accept file name and number of bytes from user and read that
//number of bytes from file.


int main(int argc, char** argv)
{
  int fd;
  int NoOfBytes=atoi(argv[2]);
  char buff[50];

  if(strcmp(argv[1],"--help") == 0)
  {
    printf("Format:./Myexe file_name NumberOfBytes\n");
    printf("\n");
    return -1;
  }
  if(argc != 3)
  {
    printf("Error: Insufficent arguments given\n");
    return -1;
  }

  fd = open(argv[1],O_RDONLY);
  if(fd == -1)
  {
    printf("Error: File not opened successfuly.\n");
    return -1;
  }

  printf("File opened successfuly with %d file descriptor.\n", fd);
  NoOfBytes = read(fd, buff, NoOfBytes);
  buff[NoOfBytes]='\0';
  if(NoOfBytes == -1)
  {
    printf("FileCouldNot be read.");
    return -1;
  }
  printf("The contents of file are: %s", buff);
  close(fd);
  return 0;
}
