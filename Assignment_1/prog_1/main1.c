///Question 1

#include<stdio.h>
#include<stdlib.h>// Implementation of atoi


// Accept two number from user and perform addition.
int main(int argc, char* argv[])
{
  int no1=atoi(argv[1]);
  int no2=atoi(argv[2]);
  int ires=0;

  ires = no1+no2;
  printf("Addition is: %d\n",ires);
  return 0;
}
