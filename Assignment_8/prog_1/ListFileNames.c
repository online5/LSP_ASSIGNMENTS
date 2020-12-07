#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
  DIR* dir;
  struct dirent *entry;
  int fd;
  if((dir = opendir("/home/deepak/Desktop")) == NULL)
  {
    printf("Unable to open specified directory\n");
    return -1;
  }

  fd=open("Demo.txt",O_WRONLY);
  if(fd == -1)
  {
    printf("File Cannot Be Opened\n");
    return -1;
  }
  char str[500]={'\0'};
  //printf("directory opened successfully\n");
  sprintf(str,"Contents of Desktop directory are\n");
  write(fd, str, strlen(str));
  while((entry = readdir(dir)) != NULL)
  {
    //printf("Name: %s\n", entry->d_name);
    sprintf(str,"Name: %s\n",entry->d_name);
    write(fd,str,strlen(str));
    memset(str,0,sizeof(str));
  }
  close(fd);
  return 0;
}
