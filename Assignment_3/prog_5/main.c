#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;
//5. Write a program which accept directory name and file name from user and check whether
//that file is present in that directory or not.
int main(int argc, char* argv[])
{
  BOOL bret=FALSE;
  DIR *ret;
  struct dirent *entry;
  char FileName[50]="";
  char directoryname[50]="";
  char path[30];
  char temp[30];

  int directorylength;
  int return_value=0;
  if(argc != 3)
  {
    printf("Error: Invalid Parameters.\nEnter %s your-Directory-name FileNameTocheck.\n", argv[0]);
    return -1;
  }
  strcpy(directoryname, argv[1]);
  strcpy(FileName, argv[2]);

  if((ret=opendir(directoryname)) == NULL)// We can Either Give Absoulte like /home/deepak/Desktop/LSP                                    // Or Relative aPath to the opendir Directory.
  {
    printf("Error: Directory cannot be opened.\n");
    return -1;
  }
  strcpy(path, directoryname);
  directorylength=strlen(directoryname);
  path[directorylength]='/';
  path[directorylength+1]='\0';

  strcpy(temp,path);


  return_value = chdir(directoryname);
	if(return_value == -1)
	{
		printf("Unable to change current working directory\n");
		return -1;
	}
  while((entry=readdir(ret)) != NULL)
  {
              //directoryname/entryname
    if((strcmp(FileName, entry->d_name)) == 0)
    {
      bret=TRUE;
      break;
    }
  }
  if(bret == TRUE)
  {
    printf("File %s is Present in the given directory.\n", FileName);
  }
  else
  {
    printf("File Not Present.\n");
  }


  closedir(ret);
  return 0;
}
