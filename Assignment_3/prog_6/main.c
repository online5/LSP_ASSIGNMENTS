#include<stdio.h>
#include<fcntl.h>
//6. Write a program which accept two directory names from user and move all files from
//source directory to destination directory.


/*

#include <stdio.h>
int rename (const char *oldpath, const char *newpath);

*/
int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    printf("Error: Enter ./myexe OldDirName DestDirName\n");
    return -1;
  }
  int fd=rename(argv[1], argv[2]);
  if(fd == -1)
  {
    printf("Error: File contents cannot be moved.\n");
    return -1;
  }
  else
  {
    printf("File Contents moved successfully.\n");
  }

  return 0;
}
