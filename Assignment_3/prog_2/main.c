#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

//2. Write a program which accept directory name from user and print all file names and its
//types from that directory.
int main(int argc, char* argv[])
{
  DIR *ret;
  struct dirent *entry;
  char path[500];

  if(argc != 2)
  {
    printf("Error: Invalid Parameters.\nEnter ./myexe your-Directory-name.\n");
    return -1;
  }

  // We can Either Give Absoulte like /home/deepak/Desktop/LSP
  // Or Relative aPath to the opendir Directory.
  if((ret=opendir(argv[1])) == NULL)
  {
    printf("Error: Directory cannot be opened.\n");
    return -1;
  }

  printf("Contents of Directory are\n");
  struct stat buff;
  while((entry=readdir(ret)) != NULL)
  {
    memset(&buff,0,sizeof(buff));
    memset(path,0, sizeof(path));

    sprintf(path,"%s/%s", argv[1],entry->d_name);
    if(stat(path, &buff)<0)
    {
      printf("Error: File statistics cannot be retrieved.\n");
      exit(EXIT_FAILURE);
    }
    printf("Name: %s\t", entry->d_name);
    if(S_ISREG(buff.st_mode))
    {
      printf("FileType: Regular.\n");
    }
    else if(S_ISDIR(buff.st_mode))
    {
      printf("FileType: Directory.\n");
    }
    else if(S_ISCHR(buff.st_mode))
    {
      printf("FileType: Character Special\n");
    }
    else if(S_ISFIFO(buff.st_mode))
    {
      printf("FIFO.\n");
    }
    else if(S_ISBLK(buff.st_mode))
    {
      printf("Block Special File.\n");
    }
    else if(S_ISSOCK(buff.st_mode))
    {
      printf("Socket.\n");
    }
    else if(S_ISLNK(buff.st_mode))
    {
      printf("Symbolic Link\n");
    }
    else
    {
      printf("FileType Unknown.\n");
    }
  }
  closedir(ret);
  return 0;
}
