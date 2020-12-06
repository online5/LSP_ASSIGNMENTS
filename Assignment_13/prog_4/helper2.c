#include<stdio.h>
#include<limits.h>

int Min(int arr[], int size)
{
  if(size<=0)
  {
    return INT_MAX;
  }
  int i=0, Min=arr[0];
  for(i=1; i<size; i++)
  {
    if(arr[i]<Min)
    {
      Min=arr[i];
    }
  }
  return Min;
}
