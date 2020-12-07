#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define SHMSZ 30 //Size of the segment

int main()
{
  int shmid;
  key_t key;
  char* shm, *s;
  char c;

  printf("Demo of IPC using Shared Memory\n");
  printf("Server is running.\n");

  key=ftok(".",'a');
  shmid=shmget(key, SHMSZ, IPC_CREAT | 0666);
  shm=shmat(shmid, NULL, 0);

  s=shm;
  for(c='a'; c<='z'; c++)
  {
    *s=c;
    s++;
  }
  *s='\0';
  printf("Data is wriiten in Shared Memory\n");
  // Waiting until ohter proces changes the
  // first character of our Memory to '*'

  while(*shm != '*')
  {
    sleep(1);
  }
  printf("Data is Successfully fetched by client.\n");
  exit(0);
}
