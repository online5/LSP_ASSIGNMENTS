#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
  DIR *dir;
  struct dirent *entry;
  struct stat filestat; // Struture which stores all file
  char name[550];
  char newfilename[250];
  int ret=0, count=0;

  if(argc != 2)
  {
    printf("Invalid Number of Parameter\n");
    return -1;
  }

  if((dir=opendir(argv[1])) == NULL)
  {
    printf("Unable to open directory\n");
    return -1;
  }
  while((entry=readdir(dir)) != NULL)
  {
    sprintf(name,"%s/%s", argv[1], entry->d_name);
    stat(name,&filestat);
    if(S_ISREG(filestat.st_mode))
    {
      count++;
      sprintf(newfilename,"%s/%d.txt",argv[1],count);
      ret=rename(name,newfilename);
      if(ret != 0)
      {
        printf("FileCannot Be Renamed\n");
        exit(0);
      }
    }
    memset(newfilename,0,sizeof(newfilename));
    memset(name,0,sizeof(name));
  }

  printf("Files Renamed Successfully\n");
  closedir(dir);
  return 0;
}
