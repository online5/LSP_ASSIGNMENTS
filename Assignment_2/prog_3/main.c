#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>

// 3. Write a program which accept file name and on mode and that program check whether our
// process can access that file in accepted mode or not.

// access() checks whether the calling process can access the file pathname.  If pathname is a symbolic link, it is dereferenced.
//On  success  (all requested permissions granted), zero is returned.
// On error (at least one bit in mode asked for a permission that is denied, or some other error occurred), -1 is returned,

int main(int argc, char* argv[])
{
  char name[400];

  if((access(argv[1], R_OK)) == -1)
  {
    printf("File does NOT have read access right\n");
  }
  else
  {
    printf("File does have read access right\n");
  }

  if((access(argv[1], W_OK)) == -1)
  {
    printf("File does NOT have WRITE access right\n");
  }
  else
  {
    printf("File does have WRITE access right\n");
  }
  //R_OK->Read Access
  //W_OK->Write Access
  //X_OK->Execute Access

  if((access(argv[1], X_OK)) == -1)
  {
    printf("File does NOT have EXECUTE access\n");
  }
  else
  {
    printf("File does have EXECUTE access \n");
  }

  return 0;
}
