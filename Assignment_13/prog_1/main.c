
/*
1.Write a program which creates one shared object library which contains two funcntions
named as search() and sort(). Search function will accept one array and innteger and
check whether that innteger is available in that array or not. Sort function will accept the
array and sort the contents of that array using any technique.
*/
#include<stdio.h>
#include<stdlib.h>
#include "header.h"
#include<dlfcn.h>

int main()
{
  BOOL ret=FALSE;
  BOOL iret=FALSE;
  void* fptr=NULL;
  int* arr=NULL;
  //Function Prototype
  //BOOL Seachfptr(int arr[],int, int);
  BOOL (*Searchptr)(int arr[], int, int);
  void (*Sortptr)(int arr[], int);
  int size, ino, i, j;

  printf("Enter Number of elements in array\n");
  scanf("%d", &size);
  arr=(int*)malloc(4*size);
  printf("Loading Libray\n");
  fptr=dlopen("./Load.so",RTLD_LAZY);
  if(fptr == NULL)
  {
    printf("Unable to load the library\n");
    return -1;
  }

  printf("\nLibrary loaded Succesfully\n");
  printf("Enter Elements of the array\n");

  for(i=0; i<size; i++)
  {
    scanf("%d",&arr[i]);
  }
  if(arr == NULL)
  {
    return -1;
  }
  printf("Enter Number to be searched\n");
  scanf("%d",&ino);
  //ret=Search(arr, size, ino);
  Searchptr=dlsym(fptr,"Search");
  if(Searchptr == NULL)
  {
    printf("Library Funtion cannot be linked\n");
    return -1;
  }

  iret=Searchptr(arr, size, ino);
  if(iret == TRUE)
  {
    printf("Element is present.\n");
  }
  else
  {
    printf("Element is not present");
  }
  printf("Calling Sorted Function from the shared object \n");
  Sortptr=dlsym(fptr, "BubbleSort");

  if(Sortptr == NULL)
  {
    printf("Libary function cannot be linked\n");
    return -1;
  }

  Sortptr(arr, size);

  printf("Sorted Elements are: ");
  for(i=0; i<size; i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
  dlclose(fptr);
  return 0;
}
