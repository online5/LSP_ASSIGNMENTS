#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>
void* CountCapital(void* p)
{
  char buff[456]={'\0'};
  int ret=0, countCap=0, i=0;
  int fd=*(int*)p;
  printf("Inside Thread1\n");
  while(ret=read(fd, buff, sizeof(buff)))
  {
    for(i=0; i<ret; i++)
    {
      if(buff[i] >= 'A' && buff[i]<= 'Z')
      {
        countCap++;
      }
    }
  }
  printf("Number of capital characters %d\n", countCap);
  pthread_exit(NULL);
}

void* CountSmall(void* p)
{
  char buff[456]={'\0'};
  int ret=0, countSmall=0, i=0;
  int fd=*(int*)p;
  printf("Inside Thread2\n");
  while(ret=read(fd, buff, sizeof(buff)))
  {
    for(i=0; i<ret; i++)
    {
      if(buff[i] >= 'a' && buff[i]<= 'z')
      {
        countSmall++;
      }
    }
  }
  printf("Number of small characters %d\n", countSmall);
  pthread_exit(NULL);
}

int main()
{
  pthread_t thread1, thread2, thread3, thread4;
  int ret=0;

  int fd=open("file.txt", O_RDONLY);
  if(fd == -1)
  {
    printf("File cannot be opened\n");
    return -1;
  }
  ret=pthread_create(&thread1, NULL, CountCapital, (void*)&fd);
  if(ret == -1)
  {
    printf("Thread cannot be created\n");
    return -1;
  }
  ret=pthread_create(&thread2, NULL, CountSmall, (void*)&fd);
  if(ret == -1)
  {
    printf("Thread cannot be created.\n");
    return -1;
  }

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  close(fd);
  return 0;
}
