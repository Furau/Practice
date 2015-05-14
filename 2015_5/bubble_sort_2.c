#include <stdio.h>

typedef struct student{
	char name[21];
	int  score;
}student;

int main(){
	student a[100],t;
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
			scanf("%s",a[i].name);
			scanf("%d",&a[i].score);
			}
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++){
			if(a[j].score<a[j+1].score){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				}
			}
	for(i=0;i<n;i++)printf("%s\n",a[i].name);
	return 0;
}
