#include <stdio.h>

typedef struct queue{
	int data[1000];
	int head;
	int tail;
}queue;

typedef struct stack{
	int data[10];
	int top;
}stack;

int main(){
	queue q1,q2;
	stack s;
	int book[10];
	int i,j;
	q1.head=1;
	q1.tail=1;
	q2.head=1;
	q2.tail=1;
	s.top=0;
	for(i=1;i<=9;i++)book[i]=0;
	for(i=1;i<=6;i++)scanf("%d",&q1.data[q1.tail++]);
	for(i=1;i<=6;i++)scanf("%d",&q2.data[q2.tail++]);
	while(q1.head<q1.tail&&q2.head<q2.tail){
		t=q1.data[q1.head];
		if(book[t]==0){
			q1.head++;
			s.top++;
			s.data[s.top]=t;
			book[t]=1;
		}
		else {
			q1.head++;
			q1.data[q1.tail++]=t;
			while(s.data[s.top]!=t){
				book[s.data[s.top]]=0;
				q1.data[q1.tail++]=s.data[s.top--];
			}
		}
		t=q2.data[q.head];
		if(book[t]==0){
			q2.head++;
			s.top++;
			s.data[s.top]=t;
			book[t]=1;
		}
		else {
			q2.head++;
			q2.data[q2.tail]=t;
			q2.tail++;
			while(s.data[s.top]!=t){
				book[s.data[s.top]]=0;
				q2.data[q2.tail++]=s.data[s.top--];
			}
		}
	}
	if(q2.head==q2.tail){
		printf("Player 1 WIN!\n");
		printf("Card in hand:\n");
		for(i=q1.head;i<=q1.tail-1;i++)printf(" %d",q1.data[i]);
		if(s.top>0){
			printf("Card in table:\n");
			for(i=1;i<=s.top;i++)printf(" %d",s.data[i]);
		}
		else printf("No card in table!\n");
	}
	else {
		printf("Player 2 WIN!\n");
		printf("Card in hand:\n");
		for(i=q2.head;i<=q2.tail-1;i++)printf(" %d",q2.data[i]);
		if(s.top>0){
			printf("Card in table:\n");
			for(i=1;i<=s.top;i++)printf(" %d",s.data[i]);
		}
		else printf("No card in table!\n");
	}
	return 0;
}