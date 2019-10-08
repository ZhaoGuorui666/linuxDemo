#include "main.h"



void createRandomArray(int *p,int len){
	
	int i;
	srand((int)time(0));
	
	//creat random num from 1 to 100
	for(i = 0;i<len;i++)
	{
		p[i] = 1 + (int)(100.0*rand()/(RAND_MAX + 1.0));
	}
	
}


