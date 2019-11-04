#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t result;
	result=fork();
	int newret;
	if(result==-1){
		perror("error");
		exit;
	}else if(result==0){
		printf("result = %d,pid=%d,ppid=%d",result,getpid(),getppid());
		newret+=system("ls -l");
	}else{
		sleep(10);
		printf("result = %d,pid=%d,ppid=%d",result,getpid(),getppid());
		newret+=system("ping www.baidu.com");
	}




}
