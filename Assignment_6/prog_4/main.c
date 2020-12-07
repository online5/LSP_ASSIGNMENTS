/*
4. Write a program which accept directory name from user and delete all such files whose
size is greater than 100 bytes.
*/
#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char* argv[])
{
  DIR *dir;
  struct stat fstat;
  struct dirent* entry;
  char name[500], buff[51];
  int fd=0,fd_combine_file=0, fd_dir_files=0, ret=0;

  if(argc != 2)
  {
    printf("Error: Invalid syntax\n");
    printf("Expected ./File_Name Dire_Name\n");
    return -1;
  }
  if((dir=opendir(argv[1])) == NULL)
  {
    printf("Error: Unable to open specified directory.\n");
    return -1;
  }

  printf("Contents of directory as\n");
  fd_combine_file = open("combine.txt", O_CREAT | O_WRONLY | O_APPEND, 0777);
  if(fd_combine_file == -1)
  {
    printf("File cannot be created.\n");
    return -1;
  }

  while((entry = readdir(dir)) != NULL)
  {
    memset(&fstat, 0, sizeof(fstat));
    memset(name, 0, sizeof(name));

    sprintf(name, "%s/%s",argv[1], entry->d_name);
    stat(name, &fstat);

    if(S_ISREG(fstat.st_mode) && (fstat.st_size > 100))
    {
        printf("%s FileDeleted successfully.\n",entry->d_name);
        unlink(name);
    }
  }
  closedir(dir);
  //printf("File contents successfully written.\n");
  close(fd_combine_file);
  return 0;
}
