#include<stdio.h> // For standard input output functions
#include<string.h>// For using string functions
#include<dirent.h>// For accesing each directory entry
#include<fcntl.h>// For dealing with file operations like open read
#include<stdlib.h>// To deal with macro constants
#include<sys/types.h>//To determine type for the files
#include<sys/stat.h>// For accesing the  information about file
#include<unistd.h> // For file operations like close

#define MAX_NAME 50

/*
7. Write program which accept directory name from user and delete all empty files from that
directory.
*/

int main(int argc, char* argv[])
{
  DIR *ret;// Pointer to the structure
  struct dirent *entry;
  struct stat buff;
  char directory[50];
  long int directorylength=0;
  int size=0, val=0;

  char dynamicpath[50];
  char* path;
  char* sourceadress;
  char temp[40];
  if(argc != 1)
  {
    printf("Error: Invalid Parameters.\nEnter ./myexe your-Directory-name.\n");
    return -1;
  }

  if((ret=opendir("test")) == NULL)// We can Either Give Absoulte like /home/deepak/Desktop/LSP                              // Or Relative aPath to the opendir Directory.
  {
    printf("Error: Directory cannot be opened.\n");
    return -1;
  }
  strcpy(dynamicpath, "test");
  directorylength=strlen(dynamicpath);
  dynamicpath[directorylength]='/';
  dynamicpath[directorylength+1]='\0';

  directorylength=strlen(dynamicpath);
  path=malloc(directorylength+1+50);
  strcpy(path,dynamicpath);
  strcpy(temp, path);


  while((entry=readdir(ret)) != NULL)
  {
    strcpy(path, temp);// First copy the value of temp that is directoryname into path
    strcat(path, entry->d_name); // Second concat the path with the entryname
    val=stat(path, &buff);

    if(val == -1)
    {
      printf("Error: File Cannot be opened.\n");
      continue;
    }
    if(!S_ISDIR(buff.st_mode) && (buff.st_size == 0))
    {
      printf("File Deleted-> %s\n",entry->d_name);
      unlink(path);
    }
  }


  closedir(ret);
  return 0;
}
