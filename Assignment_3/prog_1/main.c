#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/types.h>

//Prog1: 1. Write a program which accept directory name from user and print all file names from that
//directory.

int main(int argc, char* argv[])
{
  DIR *ret;
  struct dirent *entry;

  if(argc != 2)
  {
    printf("Error: Invalid Parameters.\nEnter ./myexe your-Directory-name.\n");
    return -1;
  }
  // We can either give absoulte path like /home/deepak/Desktop/LSP
  // Or Relative path to the opendir Directory.
  if((ret=opendir(argv[1])) == NULL)
  {
    printf("Error: Directory cannot be opened.\n");
    return -1;
  }

  printf("Contents of Directory are\n");
  while((entry=readdir(ret)) != NULL)
  {
    printf("Name: %s\tInode %ld\n", entry->d_name, entry->d_ino);
  }
  closedir(ret);
  return 0;
}
