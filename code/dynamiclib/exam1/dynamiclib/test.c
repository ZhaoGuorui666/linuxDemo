#include "mylib.h"

int main(){
	int a[10];
	init(a,10);
	show(a,10);
	printf("\nmax = %d",max(a,10));
	printf("\nmax = %d\n",sum(a,10));
	return 0;
}
