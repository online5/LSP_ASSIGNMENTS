#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
  printf("Inside Child Process");
  sleep(3);
  return 0;
}
