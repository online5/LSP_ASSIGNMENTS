#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
//3. Write a program which accept directory name from user and print name of such a file
//having largest size.

int main(int argc, char* argv[])
{
  DIR *ret;
  struct stat buff;
  struct dirent *entry;
  int max=-1, val=0;
  char name[30]="";
  char path[300]={'\0'};

  if(argc != 2)
  {
    printf("Error: Invalid Parameters\n");
    return -1;
  }

  ///home/deepak/Desktop/LSP/FileSubsystemPropertyPrograms
  // Or Relative aPath to the opendir Directory.
  if((ret=opendir(argv[1])) == NULL)
  {
    printf("Error: Directory cannot be opened.\n");
    return -1;
  }

  printf("Contents of Directory are\n");
  while((entry=readdir(ret)) != NULL)
  {
    memset(path, 0, sizeof(path));
    sprintf(path,"%s/%s",argv[1], entry->d_name);
    val=stat(path, &buff);
    if(val == -1)
    {
      printf("statistics of file cannot be retrieved.\n");
      memset(&buff, 0 ,sizeof(buff));
      break;
    }
    if(max<buff.st_size)
    {
      strcpy(name,entry->d_name);
      max=buff.st_size;
    }
    memset(&buff, 0, sizeof(buff));
  }
  printf("File %s is largest of size %d.\n",name,max);
  closedir(ret);
  return 0;
}
