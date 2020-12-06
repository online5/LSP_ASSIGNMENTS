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
5. Write a program which accept file name which contains data of all file. We have to
create all file again.
*/

//This structure is written into the starting of file
// also useful for recreating files

struct HeaderFile
{
  char name[50];
  int size;
};

void CreateIndivialFiles (char* name, char* dir_name)
{
  int fd=0, ret=0, read_ret=0,fd_seg=0, write_ret=0, dir_ret;
  char buff[256]={'\0'}, path[500];
  char *buffer=NULL;
  struct HeaderFile fobj;

  if(name == NULL)
  {
    printf("Error: Invalid Name\n");
    return;
  }

  //Opening combine file from current directory
  fd=open(name, O_RDONLY);
  if(fd == -1)
  {
    printf("Error: FileCnanot be opened.\n");
    return;
  }

  // For storing files in a directory make one
  dir_ret=mkdir(dir_name, 0777);
  while((ret=read(fd, &fobj, sizeof(fobj)))>0)
  {
    memset(path, 0, sizeof(path));
    sprintf(path, "%s/%s", dir_name, fobj.name);
    if((ret=creat(path, 0777)) == -1)
    {
      printf("Error: File Cannot be created\n");
      exit(EXIT_FAILURE);
    }

    fd_seg=open(path, O_WRONLY);
    if(fd_seg == -1)
    {
      printf("Error: Segregate file cannot be opened\n");
      exit(EXIT_FAILURE);
    }

    buffer=(char*)malloc((fobj.size));
    if((read_ret=read(fd, buffer, fobj.size)) == -1)
    {
      printf("Error: Data cannot be read successfully\n");
      exit(EXIT_FAILURE);
    }

    if((write_ret=write(fd_seg, buffer, read_ret)) == -1)
    {
      printf("Error: Data cannot be written into Segregate file\n");
      exit(EXIT_FAILURE);
    }

    //Closing Individual files which are created
    close(fd_seg);
    memset(buffer, 0, sizeof(buffer));
    memset(&fobj, 0, sizeof(fobj));
  }
  //Closing combined file
  close(fd);
}

int main(int argc, char* argv[])
{
  // Driver code
  // ./myexe combined_file_Name New_DirectoryName
  if(argc != 2)
  {
    printf("Error: Invalid files\n");
    return -1;
  }
  CreateIndivialFiles(argv[1], argv[2]);
  return 0;
}
