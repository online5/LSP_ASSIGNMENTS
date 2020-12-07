#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main()
{
  int fd=0,ret=0, i=0;
  int CapCount=0;
  char str[250]={'\0'};
  int fd2=0;
  fd=open("hello.txt", O_RDONLY);
  if(fd == -1)
  {
    printf("FileCannot be opened\n");
    return -1;
  }

  printf("FileOpened Successufully\n");
  while((ret=read(fd,str,10)) > 0 )
  {
    for(i=0; i<ret; i++)
    {
      if(str[i]>='A' && str[i]<='Z')
      {
        CapCount++;
      }
    }
  }

  fd2=open("count.txt",O_WRONLY);
  if(fd2 == -1)
  {
    printf("Count.txt Cannot Be opened\n");
    return -1;
  }
  memset(str,0,sizeof(str));
  sprintf(str,"Number of Capital count from ChildProcess2 is %d\n",CapCount);
  pwrite(fd2, str, strlen(str),strlen(str)+1);
  printf("Data Written successfully by ChildProcess2\n");

  close(fd);
  close(fd2);
  return 0;
}
