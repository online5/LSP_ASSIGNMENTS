/*
9. Write a program which accept filename and string from user and write that string into
file.
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

// To compile this program gcc main.c -o myexe
// To run use ./myexe FileName.txt ;
//
int main(int argc, char* argv[])
{
  if(argc!=3)
  {
    printf("Invalid Arguments given.\n");
    printf("Expected format ./myexe FileName.txt string\n");
    return -1;
  }
  int fd=0,ret=0;
  fd=open(argv[1],O_WRONLY);
  char buff[256]="";
  strcpy(buff, argv[2]);  // Copy second parameter into buffer.

  ret=write(fd, buff, strlen(buff));
  if(ret>0)
  {
    printf("Data Successfuly written to the file.\n");
  }
  else
  {
    printf("Error: data could not be written.\n");
  }
  
  close(fd);

  return 0;
}
