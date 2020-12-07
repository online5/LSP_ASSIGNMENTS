#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define SHMSZ 30

int main()
{
  char c;
  int shmid;
  char* shm, *s;

  printf("Demo of IPC using Shared Memory\n");
  key_t key=ftok(".",'a');

  shmid = shmget(key, SHMSZ, IPC_CREAT|0666);

  shm=shmat(shmid, NULL, 0);
  s=shm;

  for(s=shm; *s != '\0'; s++)
  {
    printf("%c ",*s);
  }
  *shm='*'; //Indicating server that the client have
  //completed the readiing process.
  printf("\nTerminating Client\n");
  exit(0);
}
