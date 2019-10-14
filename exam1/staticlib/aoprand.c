int max(int *a,int n){
	int m;
	m = a[0];
	for(int i =0;i<n;i++){
		if(a[i]>m){
			m=a[i];		
		}
	}
	return m;
}
int sum(int *a,int n){
	int sum;
	for(int i =0;i<n;i++){
		sum+=a[i];	
	}
	return sum;
}

