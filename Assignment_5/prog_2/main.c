/*
2. Write a program which accept file name from user which contains information of employee
, we have to read all contents of that file.*/

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
void ReadDataFromFile()
{
  struct Emp eobj;
  int size=0, i=0;
  int fd=0;
  fd=open("Employee.txt",O_RDONLY);
  if(fd == -1)
  {
    printf("Error: File cannot be opened.\n");
    return ;
  }
  while((read(fd, &eobj, sizeof(eobj)))>0)
  {
    printf("Details about Employee %d\n",i+1);
    printf("Employee Name: %s\n",eobj.name);
    printf("Employee Age: %d\n", eobj.age);
    printf("Employee salary:%0.2f\n", eobj.salary);
    printf("Employee experience:%d\n\n", eobj.exp);
    i++;
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
  ReadDataFromFile();
  printf("Data Successfully read from file.\n");
  return 0;
}
