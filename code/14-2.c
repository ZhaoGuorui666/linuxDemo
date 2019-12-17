#include "my.h"
#define NUM_THREADS 4
void hello(void *t){
	pthread_t my_tid;

	int sum=0;
	for(int i = 0 ;i<1000;i++){
		sum+=i;
		printf("\t Thread %d,sum=%d\n",t,sum);
	}
	printf("\t Thread %d,sum=%d\n",t,sum);
	
	my_tid=pthread_self();
	printf("\t Thread %d:my tid is %lx,Hello world\n",t,my_tid);
}

int main(){
	pthread_t tid;
	int rv,t;
	for(t=0;t<NUM_THREADS;t++){
		rv=pthread_create(&tid,NULL,(void*(*)())hello,(void*)t);
		if(rv!=0){
			printf("pthread_create is not created..\n");
			return -1;
		}
		printf("Create thread %lx\n",tid);
	}
	printf("Good_bye!\n");
	pthread_exit(NULL);
}
