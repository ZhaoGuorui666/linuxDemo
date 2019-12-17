#include "my.h"
int count = 0;
int main(){
	pid_t f1;
	pid_t f2;
	pid_t f3;

	int r_num;
	int pipefd[2];
	char buf[4096];
	memset(buf,0,sizeof(buf));

	if(pipe(pipefd)<0){
		perror("pipe failed.\n");
		return -1;
	}

	printf("parent fork first time!\n");
	f1 = fork();
	int s1,s2,s3,r1,r2,r3;

	if(f1==0){
		//first thread
		printf("first:pid=%d , ppid = %d\n",getpid(),getppid());

				close(pipefd[0]);	
		int count = 0;
		while(write(pipefd[1],"0",1)!=-1){
			printf("first write ok!  count = %d\n",count);
			count++;
			sleep(1);
		}
		close(pipefd[1]);
	}
	else{
		printf("parent fork second time!\n");
		f2 = fork();
		if(f2==0){
			//second thread
			sleep(3);
			//printf("second:pid=%d , ppid = %d\n",getpid(),getppid());
			close(pipefd[1]);
			
			while((r_num=read(pipefd[0],buf,100))>0){
				printf("second read from pipe: %s,total=%d\n",buf,r_num);
				sleep(2);
			}
			
			close(pipefd[0]);
			exit(0);
		}
		else{
			printf("parent fork third time!\n");
			f3 = fork();
			if(f3==0){
				//third thread
				printf("third:pid=%d , ppid = %d\n",getpid(),getppid());
				exit(33);
			}

			else{
				// parent thread
				printf("parent waiting!\n");
				r1=wait(&s1);
				r2=wait(&s2);
				r3=wait(&s3);
									
				printf("parent:pid=%d , ppid = %d\n",getpid(),getppid());

				
			}
		}

		
		return 0;
	}

}
