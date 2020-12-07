#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/msg.h>
#include<stdlib.h>


#define MAX_TEXT 512

struct my_msg_str
{
  long int my_msg_type;
  char some_text[MAX_TEXT];
};
int main()
{
  printf("Demonstration of IPC using Message Queue\n");
  printf("Client Process is running\n");
  int running=1;
  int msgid;
  struct my_msg_str some_data;
  long int msg_to_recieve=0;

  msgid=msgget((key_t)1234, 0666);
  printf("Fectching the messages from the message Queue\n");
  while(running)
  {
    msgrcv(msgid, (void*)&some_data, BUFSIZ, msg_to_recieve, 0);
    printf("Recieved Message: %s\n", some_data.some_text);
    if(strncmp(some_data.some_text, "end", 3)== 0)
    {
      running = 0;
    }
  }
  printf("Terminating the client process\n");
  exit(EXIT_SUCCESS);

}
