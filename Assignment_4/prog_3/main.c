/*
3. Write a program which accept two file names from user and check whether contents of
that two files are equal are not.
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

int main(int argc, char* argv[])
{
  int ret1=0, ret2=0;
  char buff1[30];
  char buff2[30];
  BOOL isIdentical=FALSE;
  
  if(argc != 3)
  {
    printf("Invalid Format.\n");
    return -1;
  }
  int fd1=0, fd2=0;

  fd1=open(argv[1],O_RDONLY);
  if(fd1 == -1)
  {
    printf("Error: File 1 cannot be opened.\n");
    return -1;
  }
  fd2=open(argv[2],O_RDONLY);
  if(fd2 == -1)
  {
    printf("Error: File 2 cannot be opened.\n");
    return -1;
  }
  while(((ret1=read(fd1,buff1,20)) > 0) && (ret2=read(fd2,buff2,20))>0)
  {
    buff1[ret1]='\0';
    buff2[ret2]='\0';
    if(strcmp(buff1,buff2) == 0)
    {
      isIdentical=TRUE;
      continue;
    }
    else
    {
      isIdentical=FALSE;
      break;
    }
  }
  if(isIdentical == TRUE)
  {
    printf("Files have Identical data.\n");
  }
  else
  {
    printf("FILE contents are not same.\n");
  }
  printf("\nFiles are succesfully opened\n");

  close(fd1);
  close(fd2);
  return 0;
}
