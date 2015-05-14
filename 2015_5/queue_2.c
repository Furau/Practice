#include <stdio.h>

typedef struct queue{
	int data[100];
	int head;
	int tail;
}queue;

int main(){
	queue q;
	q.head=1;
	q.tail=1;
	for(i=1;i<=9;++){
		scanf("%d",&q.data[q.tail++]);
	}
	while(q.head<q.tail){
		printf("%d",q.data[q.head++]);
		q.data[q.tail++]=q.data[q.head];
		head++;
	}
	return 0;
}