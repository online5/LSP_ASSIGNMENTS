#include<stdio.h>

int main()
{
  int ret=0;
  char str1[]="demo.txt";
  char str2[]="new_demo.txt";
  ret=rename(str1, str2);
  if(ret != 0)
  {
    printf("Rename Failed\n");
  }
  else
  {
    printf("FileReanmaed Successfully\n");
  }
  return 0;
}
