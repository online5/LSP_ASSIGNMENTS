#include<stdio.h>
#include<dlfcn.h>
#include "header.h"

BOOL CheckPerfect(int n)
{
  void* lib=NULL;
  int (*Fact)(int);
  int sum=0;
  lib=dlopen("./Load.so", RTLD_LAZY);
  if(lib == NULL)
  {
    printf("Library cannot be linked\n");
    return -1;
  }

  printf("Library Loaded Successfully\n");

  Fact=dlsym(lib,"SumFactor");
  if(Fact == NULL)
  {
    printf("Function Cannot Be Loaded\n");
    return -1;
  }
  sum=Fact(n);
  dlclose(lib);
  if(sum == n)
  {
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}
