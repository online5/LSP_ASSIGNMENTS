#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>

void* CountCapital(void* p)
{
  int fd=open("file.txt", O_RDONLY);
  if(fd == -1)
  {
    printf("File cannot be opened\n");
    return NULL;
  }
}
void* CountSmall(void* p)
{

}
int main()
{

  pthread_t thread1, thread2, thread3, thread4;


}
