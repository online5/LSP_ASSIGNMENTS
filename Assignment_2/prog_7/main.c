#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

//.7. Write a program which accept file name from user and write string in that file.

int main(int argc, char** argv)
{
  char buff[50];
  int fd, NoOfBytes;
  strcpy(buff, argv[2]);

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

  fd = open(argv[1], O_APPEND);
  if(fd == -1)
  {
    printf("Error: File not opened successfuly.\n");
    return -1;
  }

  printf("File opened successfuly with %d file descriptor.\n", fd);
  NoOfBytes = write(fd, buff, strlen(buff));
  if(NoOfBytes == -1)
  {
    printf("Data could not be written in file.\n");
    return -1;
  }

  printf("Data is Written successfuly.\n");
  close(fd);
  return 0;
}
