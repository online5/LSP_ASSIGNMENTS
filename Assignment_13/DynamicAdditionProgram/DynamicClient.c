#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dlfcn.h>

int main()
{
  void* lib = NULL;
  int (*fptr)(int, int);
  int value1=10, value2=20;
  int ret=0;
  printf("Loading The Library At Runtime\n");
  lib=dlopen("./Load.so", RTLD_LAZY);
  if(lib == NULL)
  {
    printf("Unable to link the Library");
    return -1;
  }
  printf("Library Loaded Succesfully\n");
  fptr=dlsym(lib, "add");
  if(fptr == NULL)
  {
    printf("Address of function cannot be retrieved\n");
    return -1;
  }
  ret=fptr(value1, value2);
  printf("Addition of the Two Programms %d\n", ret);
  dlclose(lib);
  printf("Dynamic Library Unlinked\n");

  return 0;
}
