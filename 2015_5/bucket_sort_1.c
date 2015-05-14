#include <stdio.h>

int main(){
	int book[11],i,j,t;
	for(i=0;i<=10;i++)book[i]=0;
	for(i=1;i<=5;i++){
		scanf("%d",&t);
		book[t]++;
		}
	for(i=0;i<=10;i++)
		for(j=1;j<=book[i];j++)printf("%d\n",i);
	return 0;
}
