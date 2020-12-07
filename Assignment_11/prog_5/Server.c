#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/msg.h>
#include<stdlib.h>

// 5. Write a program which performs interprocess communication using the concept of
// message queue.
#define MAX_TEXT 512

struct my_msg_str
{
  long int my_msg_type;
  char some_text[MAX_TEXT];
};

int main()
{
  int running =1, msgid;
  struct my_msg_str some_data;
  char buffer[BUFSIZ];

  printf("Demonstration of IPC usinng Message Queue\n");
  msgid=msgget((key_t)1234, 0666|IPC_CREAT);
  if(msgid == -1)
  {
    printf("Failed to create message Queue\n");
    exit(EXIT_FAILURE);
  }
  printf("Message Queue Created Successfully\n");

  while(running)
  {
    printf("Enter Some Message: \n");
    fgets(buffer, BUFSIZ, stdin);
    some_data.my_msg_type=1;
    strcpy(some_data.some_text, buffer);

    if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1)
    {
      printf("Msgsnd failed\n");
      exit(EXIT_FAILURE);
    }
    if(strncmp(buffer, "end",3) == 0)
    {
      running=0;
    }
  }
  printf("Terminating the server process\n");
  exit(EXIT_SUCCESS);
}
