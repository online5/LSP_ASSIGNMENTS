#include<stdio.h>
#include<stdlib.h>

extern char** environ;
// 7. Write a program which is used to pring home directory and login user name.
int main()
{
  // It is used to get the specific environ vairable
  // outof all envrionment variables
  char* ptr=getenv("HOME");
  if(ptr != NULL)
  {
    printf("Home Directory: %s\n", ptr);
  }
  else
  {
    printf("Error: Specified environment variable cannot be fetched\n");
    return -1;
  }

  ptr=getenv("LOGNAME");
  if(ptr != NULL)
  {
    printf("LOGIN username: %s\n", ptr);
  }
  else
  {
    printf("Error: Specified environment variable cannot be fetched\n");
    return -1;
  }

  return 0;
}
