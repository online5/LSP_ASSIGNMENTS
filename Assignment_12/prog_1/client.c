#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

#define MAX 1024

int main()
{
  printf("Inside Child2 as client\n")
  int fd;
  char buff[MAX]={'\0'};
  char *path="/tmp/myfifo";
  printf("Client process is running\n");

  fd=open(path, O_RDONLY);
  read(fd, buff, sizeof(buff));
  printf("Data Recieved from child1:\n %s\n",buff);
  close(fd);

  return 0;
}
