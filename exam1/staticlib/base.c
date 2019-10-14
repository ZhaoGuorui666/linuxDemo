#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>

void show(int *a,int n){
	for(int i = 0;i<n;i++){
		printf("%4d  =  %4d \n",i,a[i]);
	}
		
}
void init(int *p,int len){
	int i;
	srand((int)time(0));
	
	//creat random num from 1 to 100
	for(i = 0;i<len;i++)
	{
		p[i] = 1 + (int)(100.0*rand()/(RAND_MAX + 1.0));
	}
}
