#include "my.h"
int count = 0;
int main(){
	pid_t f1;
	pid_t f2;
	pid_t f3;


	printf("parent fork first time!\n");
	f1 = fork();
	int s1,s2,s3,r1,r2,r3;

	if(f1==0){
		printf("pid=%d , ppid = %d\n",getpid(),getppid());
		exit(11);
	}
	else{
		printf("parent fork second time!\n");
		f2 = fork();
		if(f2==0){
			printf("pid=%d , ppid = %d\n",getpid(),getppid());
			exit(22);
		}
		else{
			printf("parent fork third time!\n");
			f3 = fork();
			if(f3==0){
				printf("pid=%d , ppid = %d\n",getpid(),getppid());
				exit(33);
			}
			else{
				printf("parent waiting!\n");
				r1=wait(&s1);
				r2=wait(&s2);
				r3=wait(&s3);
									 printf("r1=%d,s1=%d,r2=%d,s2=%d,r3=%d,s3=%d\n",r1,WEXITSTATUS(s1),r2,WEXITSTATUS(s2),r3,WEXITSTATUS(s3));
				printf("pid=%d , ppid = %d\n",getpid(),getppid());
			}
		}
	}

}
