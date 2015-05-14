#include <stdio.h>

int isdn[1000];

void quicksort(int *a,int left,int right){
	int i,j,t,temp;
	if(left>right)return;
	t=a[left];
	i=left;
	j=right;
	while(i!=j){
		while(t>=a[j]&&i<j)j--;
		while(t<=a[i]&&i<j)i++;
		if(i<j){
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
		}
	}
	a[left]=a[i];
	a[i]=t;
	quicksort(a,left,i-1);
	quicksort(a,i+1,right);
}

int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&isdn[i]);
	quicksort(isdn,0,n-1);
	for(i=0;i<n;i++){
		if(isdn[i]!=isdn[i+1])printf("%d\n",isdn[i]);
	}
	return 0;
}
