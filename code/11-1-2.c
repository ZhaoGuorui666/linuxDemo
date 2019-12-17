#include "my.h"

int main(){
	pid_t r;
	int r_num;
	int pipefd[2];
	char buf[4096];
	memset(buf,0,sizeof(buf));
	if(pipe(pipefd)<0){
		perror("pipe failed.\n");
		return -1;
	}
	r = fork();
	if(r<0){
		perror("fork failed.\n");
		return -1;	
	}else if(r == 0){
		close(pipefd[1]);
		sleep(2000);
		while((r_num=read(pipefd[0],buf,100))>0){
			printf("child read from pipe: %s,total=%d\n",buf,r_num);
			sleep(2000);
		}
			
		close(pipefd[0]);
		exit(0);
	}
	else{
		close(pipefd[0]);	
		int count = 0;
		while(write(pipefd[1],"1",1)!=-1){
			count++;
			printf("parent write ok!  count = %d\n",count);
		}
		close(pipefd[1]);
		return 0;
	}
}
