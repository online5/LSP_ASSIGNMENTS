#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>

/*
4.Write a program which accept file name from user
and print all information about that file.
*/


// We can provide information of file as needed by
// refering to structure
/* Since Linux 2.6, the kernel supports nanosecond
   precision for the following timestamp fields.
   For the details before Linux 2.6, see NOTES. */
// struct stat {
//               dev_t     st_dev;         /* ID of device containing file */
//               ino_t     st_ino;         /* Inode number */
//               mode_t    st_mode;        /* File type and mode */
//               nlink_t   st_nlink;       /* Number of hard links */
//               uid_t     st_uid;         /* User ID of owner */
//               gid_t     st_gid;         /* Group ID of owner */
//               dev_t     st_rdev;        /* Device ID (if special file) */
//               off_t     st_size;        /* Total size, in bytes */
//               blksize_t st_blksize;     /* Block size for filesystem I/O */
//               blkcnt_t  st_blocks;      /* Number of 512B blocks allocated */
//               struct timespec st_atim;  /* Time of last access */
//               struct timespec st_mtim;  /* Time of last modification */
//               struct timespec st_ctim;  /* Time of last status change */
//
//           #define st_atime st_atim.tv_sec      /* Backward compatibility */
//           #define st_mtime st_mtim.tv_sec
//           #define st_ctime st_ctim.tv_sec
//           };


int main(int argc, char** argv)
{
  int ret;
  struct stat fstat;
  // ./myexe file_name
  if(argc != 2)
  {
    printf("Error: Invalid Number Parameter\n");
    printf("Expected: %s file_name", argv[0]);
    return -1;
  }

  if((ret=stat(argv[1], &fstat)) == -1)
  {
    printf("Error: FileInformation cannot be retrieved\n");
    return -1;
  }
  else
  {
    printf("InodeNumber:   %d\n",      fstat.st_ino);
    printf("Hardlinks:     %d\n",      fstat.st_nlink);
    printf("FileSize:      %d\n",      fstat.st_size);
    printf("BlockSize:     %d\n",      fstat. st_blksize);
    printf("BlocksAllocated:  %d\n",   fstat.st_blocks);
  }

  return 0;
}
