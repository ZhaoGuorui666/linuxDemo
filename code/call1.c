#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc,char * argv[]){
	int ret =0;
	printf("the call1's pid is %d,ppid is %d\n",getpid(),getppid());
	ret=system("./test1 123 abc hello ncu edu");
	printf("after calling! ret=%d\n",ret);
	return 0;
}
