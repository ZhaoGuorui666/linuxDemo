#include "main.h"


void quickSort(int* arr,int len,int size){
	qsort(arr,len,size,compar);
	writeArray(arr,len,"data.dat");
}


void bubbleSort(int arr[],int len){

	int i,j;

	bool flag;

	for(i = 0 ; i < len ; i++)
	{
		flag = true;
		for(j = len-1; j > i ; j--)
			if(arr[j] < arr[j-1])
			{
				swap(&arr[j],&arr[j-1]);
				flag = false;
			}		
		if(flag)	
			break;	
	}	

	writeArray(arr,len,"data.dat");
}


void swap(int *a,int *b){

	int temp = *a;
	*a = *b;
	*b = temp;

}


int compar(const void *a,const void *b){

	int *aa = (int*) a,*bb = (int*) b;
	if(*aa > *bb)	return 1;
	else if(*aa == *bb)	return 0;
	else return -1;

}
