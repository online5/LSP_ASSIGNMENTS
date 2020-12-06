#include<stdio.h>
//SumFactor() method

int SumFactor(int n)
{
  if(n<=0)
  {
    return -1;
  }
  int i=0;
  int isum=0;
  for(i=1; i<=(n/2); i++)
  {
    if(n%i == 0)
    {
      isum+=i;
    }
  }
  return isum;
}
