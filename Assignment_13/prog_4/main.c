#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<dlfcn.h>


int main()
{
  int min=0, max=0;
  int arr[]={10, -1, 20, 3, -70, 2};
  int size=sizeof(arr)/sizeof(arr[0]);
  void* lib1=NULL; //For First Library
  void* lib2=NULL; //For Second Library

  int (*ptr1)(int arr[], int); // For calling MaxFunction
  int (*ptr2)(int arr[], int); // For calling MinFunction

  lib1=dlopen("./FirstObject.so", RTLD_LAZY);
  if(lib1 == NULL)
  {
    printf("FirstLibary(Containg Max) function cannot be opened\n");
    return -1;
  }
  lib2=dlopen("./SecondObject.so", RTLD_LAZY);
  if(lib2 == NULL)
  {
    printf("SecondLibary(Containing Min function) cannot be opened\n");
    return -1;
  }

  ptr1=dlsym(lib1, "Max");
  if(ptr1 == NULL)
  {
    printf("Invalid Function address\n");
    return -1;
  }
  max=ptr1(arr, size);
  if(max == INT_MIN)
  {
    printf("Invalid Size or address of the fucntion\n");
    return -1;
  }
  printf("Maximum element is %d\n", max);

  ptr2=dlsym(lib2, "Min");
  min=ptr2(arr,size);
  if(min == INT_MAX)
  {
    printf("Invalid Size or address of the fucntion\n");
    return -1;
  }
  printf("Minumum eleement is %d\n", min);

  return 0;
}
