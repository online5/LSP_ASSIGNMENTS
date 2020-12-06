/*
2. Write a aprogram which accept directory name from user and create new directory of that
name.
*/

//ret = mkdir("NewDirectory5", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);


#include<dirent.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>


int main(int argc, char* argv[])
{
  if(argc != 2)
  {
    printf("Error: Enter Invalid Number of argumnet.\n");
    return -1;
  }
  int ret=0;
  ret=mkdir(argv[1],S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

  if(ret == -1)
  {
    printf("Cannot create the directory...\n");
    exit(EXIT_FAILURE);
  }

  printf("Directory succesfully created.\n");

  return 0;
}
