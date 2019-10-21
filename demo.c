#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<syslog.h>
#include<string.h>
#include<stdlib.h>
#define MAX 128
int chmd();
int chmd ()
{
	int c;
	printf(" 0. 0700\n 1. 0400\n 2. 0200 \n 3. 0100\n ");
	printf("Please input your choice(0-3):");
	scanf("%d",&c);
	switch(c)
	{
		case 0: chmod("file1",S_IRWXU);break;
		case 1: chmod("file1",S_IRUSR);break;
		case 2: chmod("file1",S_IWUSR);break;
		case 3: chmod("file1",S_IXUSR);break;
		default:printf("You have a wrong choice!\n");
	}
	return(0);
}
main()
{
	int fd;
	int num;
	int choice;
	char buffer[MAX];
	struct stat buf;
	char* path="/bin/ls";
	char* argv[4]={"ls","-l","file1",NULL};
	while(1)
	{
		printf("********************************\n");
		printf("0. 退出\n");
		printf("1. 创建新文件\n");
		printf("2. 写文件\n");
		printf("3. 读文件\n");
		printf("4. 修改文件权限\n");
		printf("5. 查看当前文件的权限修改文件权限\n");
		printf("********************************\n");
		printf("Please input your choice(0-6):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				close(fd);
				exit(0);
			case 1:
				fd=open("file1",O_RDWR|O_TRUNC|O_CREAT,0750);
				if(fd==-1)
					printf("File Create Failed!\n");
				else
					printf("fd = %d\n",fd);
				break;
			case 2:
				num=read(0,buffer,MAX);
				write(fd,buffer,num);
				break;
			case 3:
				read(fd,buffer,MAX);
				write(1,buffer,num);
				break;
			case 4:
				chmd ();
				printf("Change mode success!\n");
				break;
			case 5:
				execv(path,argv);
				break;
			default:
				printf("You have a wrong choice!\n");
		}
	}
}
