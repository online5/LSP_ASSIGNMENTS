#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
// 3. Write a program which accept directory name from user and print name of such a file
//having largest size.
int main(int argc, char* argv[])
{
  DIR *ret;
  int val=0;
  struct stat buff;
  struct dirent *entry;
  int fd=0;
  ///home/deepak/Desktop/LSP/FileSubsystemPropertyPrograms
  if((ret=opendir("testDir")) == NULL)                               // Or Relative aPath to the opendir Directory.
  {
    printf("Error: Directory cannot be opened.\n");
    return -1;
  }

  printf("Contents of Directory are\n");

  while((entry=readdir(ret)) != NULL)
  {
    printf("%s\n", entry->d_name);
    fd=open(entry->d_name, O_RDONLY);
    if(fd == -1)
	  {
		    printf("Unable to open the file\n");
	  }else
    {
        printf("File Opened succesfully.\n");
    }

    printf("Name: %s\tInode %ld\tFileSize. %d\n", entry->d_name, entry->d_ino, (int)buff.st_size);
    memset(&buff, 0, sizeof(buff));
    close(fd);
  }

  closedir(ret);
  return 0;
}
