#include<stdio.h>
#include<dlfcn.h>
#include "header.h"

int main()
{
  void* lib=NULL;
  int sum=0, ino=0;
  BOOL iret= FALSE;
  BOOL (*PerfectPtr)(int);

  lib=dlopen("./CheckPerfect.so", RTLD_LAZY);
  if(lib == NULL)
  {
    printf("Library CheckPerfect cannot be opened\n");
    return -1;
  }

  printf("CheckPerfect Library Loaded Successfully\n");
  printf("Enter Number to CheckPerfect\n");
  scanf("%d", &ino);
  PerfectPtr = dlsym(lib, "CheckPerfect");

  if(PerfectPtr == NULL)
  {
    printf("Address of Required Function Not Found\n");
    return -1;
  }

  iret = PerfectPtr(ino);
  if(iret == TRUE)
  {
    printf("Number is Perfect\n");
  }
  else
  {
    printf("Number is not Perfect\n");
  }
  return 0;
}
