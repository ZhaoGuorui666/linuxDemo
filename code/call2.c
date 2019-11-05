#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc,char * argv[]){
	char *arg[]={"./test1","123","abc","hello","ncu","edu",NULL};
	int ret;
	printf("the call1's pid is %d,ppid is %d\n",getpid(),getppid());
	ret=execvp("test1",arg);
	printf("after calling! ret=%d\n",ret);
	return 0;
}
