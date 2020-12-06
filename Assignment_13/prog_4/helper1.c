#include<stdio.h>
#include<limits.h>

int Max(int arr[], int size)
{
  if(size<=0)
  {
    return INT_MIN;
  }
  int i=0;
  int Max=arr[0];
  for(i=1; i<size; i++)
  {
    if(arr[i]>Max)
    {
      Max=arr[i];
    }
  }
  return Max;
}
