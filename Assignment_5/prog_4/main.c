#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
/*
4.Write a program which accept directory name from user and combine all contents of file
from that directory into one file named as AllCombine.
*/

//This structure is written into the starting of file
struct HeaderFile
{
  char name[50];
  int size;
};

void ReadDataFromFile(char* name)
{
  int fd=0, ret=0, fret=0, read_ret=0;
  char buff[256]={'\0'};
  char *buffer=NULL;
  struct HeaderFile fobj;

  if(name == NULL)
  {
    printf("Error: Invalid Name\n");
    return;
  }

  fd=open(name, O_RDONLY);
  if(fd == -1)
  {
    printf("Error: FileCnanot be opened.\n");
    return;
  }

  while((ret=read(fd, &fobj, sizeof(fobj)))>0)
  {
    printf("\nFile_Name: %s  FileSize: %d\n",fobj.name, fobj.size);
    buffer=(char*)malloc((fobj.size));

    if((read_ret=read(fd, buffer, fobj.size)) == -1)
    {
      printf("Error: Data cannot be read successfully\n");
      exit(EXIT_FAILURE);
    }

    write(1, buffer, read_ret);
    memset(buffer, 0, sizeof(buffer));
    memset(&fobj, 0, sizeof(fobj));
  }
  close(fd);
}

int main(int argc, char* argv[])
{
  DIR *dir;
  struct stat fstat;
  struct dirent* entry;
  struct HeaderFile iobj;

  char name[500]={'\0'}, buff[100]={'\0'};
  char path[1250]={'\0'};
  int fd=0,fd_combine_file=0, fd_dir_files=0, ret=0, ret_write;

  if(argc != 3)
  {
    printf("Error: Invalid syntax\n");
    printf("Expected ./file_name directory_name NewCombineFile\n");
    return -1;
  }

  if((dir=opendir(argv[1])) == NULL)
  {
    printf("Error: Unable to open specified directory.\n");
    return -1;
  }

  if((fd_combine_file=open(argv[2], O_CREAT | O_WRONLY | O_APPEND, 0777)) == -1)
  {
    printf("Error: File cannot be created and opened.\n");
    closedir(dir);
    return -1;
  }

  while((entry=readdir(dir)) != NULL)
  {
    memset(&iobj, 0, sizeof(iobj));
    memset(path, 0, sizeof(path));
    memset(&fstat,0, sizeof(fstat));

    sprintf(path,"%s/%s",argv[1],entry->d_name);
    if((stat(path, &fstat)) == -1)
    {
      printf("Error: stat function failed.\n");
      return -1;
    }

    if(S_ISREG(fstat.st_mode))
    {
        strcpy(iobj.name, entry->d_name);
        iobj.size=fstat.st_size;
        if((ret_write=write(fd_combine_file, &iobj, sizeof(iobj))) == -1)
        {
          printf("Error: Write function call failed");
          exit(EXIT_FAILURE);
        }

        if((fd_dir_files=open(path, O_RDONLY)) == -1)
        {
          printf("Error: file cannot be opened.\n");
          return -1;
        }

        while((ret=read(fd_dir_files, buff, sizeof(buff)))>0)
        {
          write(fd_combine_file, buff, ret);
        }
        memset(buff, 0, sizeof(buff));
        close(fd_dir_files);
    }   //End IF

  } // End While
  printf("\nData Successfully written.\n");
  close(fd_combine_file);
  closedir(dir);
  // Reading data from the file
  ReadDataFromFile(argv[2]);
  return 0;
}
