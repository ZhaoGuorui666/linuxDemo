#include "my.h"

void sigtoutine(int dunno){
	switch(){
		case 1:
			printf("Get a signal SIGHUP\n");
			break;
		case 2:
			printf("Get a signal SIGINT\n");
			break;
		case 3:
			printf("Get a signal SIGQUIT\n");
			break;
	
	}
}

int main(){
	printf("processc idis %d\n",getpid());
	signal(SIGHUP,sigtoutine);
	signal(SIGINT,sigtoutine);
	signal(SIGQUIT,sigtoutine);
	while(1);		
}
