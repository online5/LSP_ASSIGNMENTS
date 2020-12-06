/*
1. Write a program which writes structure in file. Structure should contains information of
Employee.*/
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

struct Emp
{
  char name[30];
  float salary;
  int age;
  int exp;
};
void AcceptEmpValuesAndPrintToFile()
{

  struct Emp eobj;
  int size=0, i=0;
  printf("Enter Number of records to store in file.\n");
  scanf("%d", &size);
  int fd=0;
  fd=open("Employee.txt", O_CREAT | O_WRONLY | O_APPEND,0774);
  if(fd == -1)
  {
    printf("Error: File cannot be opened.\n");
    return ;
  }

  for(i=0 ;i<size; i++)
  {
    printf("Enter Info of Employee %d\n",i+1 );
    printf("Enter Emp Name:\n");
    scanf(" %[^'\n']s",eobj.name);

    printf("Enter Emp Age.\n");
    scanf("%d", &eobj.age);

    printf("Enter Emp salary.\n");
    scanf("%f",&eobj.salary);

    printf("Enter Emp experience.\n");
    scanf("%d",&eobj.exp);

    if((write(fd,&eobj,sizeof(eobj)))<0)
    {
      printf("Error: Write Failure.\n");
      exit(EXIT_FAILURE);
    }
    printf("Successfully wrote info about emp %d in file.\n",i+1);
  }
  close(fd);
}
int main(int argc, char* argv[])
{

  if(argc != 1)
  {
    printf("Error: Printf invalid number of parameters.\n");
    return -1;
  }
  AcceptEmpValuesAndPrintToFile();
  printf("Data Successfully written in file.\n");
  return 0;
}
