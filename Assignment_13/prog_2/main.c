#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "header.h"

int main()
{
  //1 3 5
  void* lib=NULL;// For accessing address of the shared lib

  int ret=0;
  int (*fptr)(int);

  lib=dlopen("./Load.so",RTLD_LAZY);
  if(lib == NULL)
  {
    printf("Libray cannot be Loaded\n");
    return -1;
  }
  printf("Libary loaded Succesfully\n");
  fptr=dlsym(lib,"SumFactor");
  if(fptr == NULL)
  {
    printf("Library Not included succesfully\n");
    return -1;
  }

  ret=fptr(15);

  printf("Summation of factors is: %d\n", ret);
  dlclose(lib);
  return 0;
}
