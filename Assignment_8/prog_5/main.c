#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
//Write a program which is used to display Environment of our running process
// Declaration of the pointer
extern char ** environ;

int main()
{
  char** env=environ;
  printf("Environment variable are:");

  for(;*env !=NULL; ++env)
  {
    printf("__________________________________________\n");
    printf("%s\n",*env);
  }

  return 0;
}
