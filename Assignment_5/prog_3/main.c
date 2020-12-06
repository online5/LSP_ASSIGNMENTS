#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#define MAX_BUFFER 1024
/*
3. Write a program which accept directory name from user and write information of all
regular file in and then read the contents from that file.
*/

//
//stat structure blueprint
// struct stat {
//     dev_t     st_dev;     /* ID of device containing file */
//     ino_t     st_ino;     /* inode number */
//     mode_t    st_mode;    /* protection */
//     nlink_t   st_nlink;   /* number of hard links */
//     uid_t     st_uid;     /* user ID of owner */
//     gid_t     st_gid;     /* group ID of owner */
//     dev_t     st_rdev;    /* device ID (if special file) */
//     off_t     st_size;    /* total size, in bytes */
//     blksize_t st_blksize; /* blocksize for file system I/O */
//     blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
//     time_t    st_atime;   /* time of last access */
//     time_t    st_mtime;   /* time of last modification */
//     time_t    st_ctime;   /* time of last status change */
// };
struct file_info
{
  char name[256];
  int size;
  int n_links;
  int inode_number;
};

int main(int argc, char* argv[])
{
  DIR *dir;
  struct stat fstat;
  struct dirent* entry;
  struct file_info fobj;

  int count=1;
  char name[500], buff[MAX_BUFFER]={'\0'};
  int fd=0,fd_combine_file=0,ret=0;

  if(argc != 2)
  {
    printf("Error: Invalid syntax\n");
    printf("Expected Syntax ./File_Name Dir_Name\n");
    return -1;
  }

  if((dir=opendir(argv[1])) == NULL)
  {
    printf("Error: Unable to open specified directory.\n");
    return -1;
  }

  fd_combine_file=open("combine.txt",O_WRONLY | O_CREAT,0777);
  if(fd_combine_file  == -1)
  {
    printf("Error: Combine file cannot be opened.\n");
    exit(EXIT_FAILURE);
  }

  while((entry = readdir(dir)) != NULL)
  {
    memset(&fobj, 0, sizeof(fobj));
    memset(&fstat, 0, sizeof(fstat));
    memset(name, 0, sizeof(name));
    sprintf(name,"%s/%s",argv[1],entry->d_name);

    ret=stat(name, &fstat);
    if(ret == -1)
    {
      printf("Error in stat function\n");
      exit(EXIT_FAILURE);
    }


    if(S_ISREG(fstat.st_mode))
    {
      strcpy(fobj.name, entry->d_name);
      fobj.n_links=fstat.st_nlink;
      fobj.size=fstat.st_size;
      fobj.inode_number=fstat.st_ino;

      if((write(fd_combine_file, &fobj, sizeof(fobj)))== -1)
      {
        printf("Error: \"File stat cannot be wrriten in the file\"");
        exit(EXIT_FAILURE);
      }
    }
  }

  printf("Information about Files in directory successfully written\n");
  close(fd_combine_file);

  /// Reading from the file
  fd_combine_file=open("combine.txt", O_RDONLY);
  if(fd_combine_file == -1)
  {
    printf("Error: File cannot be opened successfully\n");
    return -1;
  }
  struct file_info read_fobj;
  printf("______________________________________________________________\n");
  while((read(fd_combine_file, &fobj, sizeof(fobj)))>0)
  {
    printf("______________________________________________________________\n");
    printf("FileName:        %s\n", fobj.name);
    printf("FileSize:        %d\n", fobj.size);
    printf("Inode Number     %d\n", fobj.inode_number);
    printf("Hardlinks:       %d\n", fobj.n_links);
  }

  printf("Data Read from the file successfully\n");
  close(fd_combine_file);
  return 0;
}
