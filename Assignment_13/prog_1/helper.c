#include<stdio.h>
#include "header.h"

void BubbleSort(int arr[], int n)
{
  int i, j, temp;
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n-i-1; j++)
    {
      if( arr[j] > arr[j+1])
      {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}
BOOL Search(int arr[], int size, int no)
{
  if(arr == NULL || size<=0)
  {
    return FALSE;
  }
  int i=0;
  for(i=0; i<size; i++)
  {
    if(arr[i] == no)
    {
      break;
    }
  }
  if(arr[i] == no)
  {
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}
