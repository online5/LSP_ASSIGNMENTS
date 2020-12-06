#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>


#define MAX_SIZE 1024

int main(int argc, char* argv[])
{
  struct stat buff;
  int FileSize=0, fd1=0, fd2=0;
  char buffer[MAX_SIZE];
  int ret=0;

  if(argc !=2 )
  {
    printf("Error: Invalid No of input.\n");
    printf("Expected Format: %s Exiting_File_Name ", argv[0]);
    return -1;
  }
  if(stat(argv[1],&buff)<0)
  {
    printf("File statistics cannot be obtained.");
    return -1;
  }

  FileSize=(int)buff.st_size;
  if(FileSize == 0)
  {
    printf("Error: Exiting File Size is 0 bytes.\n");
    exit(0);
  }
  // opening the existing file
  fd1=open(argv[1],O_RDONLY);
  if(fd1 == -1)
  {
    printf("Error File Cannot be opened.\n");
    return -1;
  }

  // NewFile created
  ret=creat("NewFile.txt",0777); // Rwx to owner group and others.
  if(ret == -1)
  {
    printf("File Cannot be created.\n");
    return -1;
  }
  //Opening the newly created file
  fd2=open("NewFile.txt", O_WRONLY);
  if(fd2 == -1)
  {
    printf("FileCannot be opened in write mode.\n");
    return -1;
  }

  while((ret=read(fd1, buffer, sizeof(buffer))) > 0)
  {
    write(fd2, buffer, ret);
  }
  printf("File Data successfully wrriten successfully.\n");

  close(fd1);
  close(fd2);
  return 0;
}
