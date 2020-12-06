/*
1. Write a program which is used to demonstrate concept of I/O redirection.
*/
#include<stdio.h>

int main(int argc, char* argv[])
{
  int No1, No2;
  printf("Enter No1, No2.\n");
  scanf("%d%d",&No1, &No2);

  printf("Addition of %d and %d is %d.\n",No1,No2, No1+No2);
  return 0;
}
