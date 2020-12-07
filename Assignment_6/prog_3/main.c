/*
3. Write a aprogram which accept directory name and file name from user and create file in
that directory.
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
  char path[50]={'\0'};
  int ret=0;
  if(argc != 3)
  {
    printf("Error: Invalid number of arguments.\n");
    print("Enter %s DirectoryName FileName", argv[0]);
    return -1;
  }

  //Creating relative path
  sprintf(path, "%s/%s",argv[1],argv[2]);
  ret=creat(path, S_IRWXU | S_IRWXG |S_IROTH | S_IXOTH);
  if(ret == -1)
  {
    printf("File cannot be created.\n");
    return -1;
  }
  printf("File successfully created.\n");
  return 0;
}
