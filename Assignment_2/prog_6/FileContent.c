#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

//Write a program which accept file name from user and read whole file.
int main(int argc, char* argv[])
{
	int i=0, fd=0, ret=0;
	char buff[50];
	if(argc != 2)
	{
		printf("Error: Invalid number of parameters\n");
		return -1;
	}
	fd=open(argv[1],O_RDONLY);
	if(fd == -1)
	{
		printf("Error: FileDescriptor cannot be opened.\n");
		return -1;
	}

	while((ret=read(fd,buff,sizeof(buff))) != 0)
	{
		write(1, buff, ret);
	}

	close(fd);
	return 0;
}
