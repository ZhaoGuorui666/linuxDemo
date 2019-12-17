#include "my.h"
int count = 0;
int main(){
	pid_t f1;
	pid_t f2;
	pid_t f3;

	f1 = fork();
	f2 = fork();
	f3 = fork();

	if(f1==0){
		printf("pid=%d , ppid = %d\n",getpid(),getppid());
		exit(0);
	}
	else if(f2==0){
		printf("pid=%d , ppid = %d\n",getpid(),getppid());
		exit(0);
	}
	else if(f3==0){
		printf("pid=%d , ppid = %d\n",getpid(),getppid());
		exit(0);
	}
	else{
		printf("into parent!\n");
		sleep(10);
		printf("parent : pid=%d , ppid = %d\n",getpid(),getppid());
		exit(0);
	}

}
