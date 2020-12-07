#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

//Write a program which accept file name from user and read whole file.
int main(int argc, char* argv[])
{
	int i=0;
	int fd=0;
	int ret=0;
	char buff[256];
	if(argc != 2)
	{
		return -1;
	}

	fd=open(argv[1],O_RDONLY);
	if(fd == -1)
	{
		printf("Error: FileDescriptor cannot be opened.\n");
		return -1;
	}

	while((ret=read(fd,buff,256)) != 0)
	{
		write(1, buff, ret);
	}

	close(fd);
	return 0;
}
