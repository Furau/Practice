#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

int main(){
	node *head,*p,*q,*t;
	int i,n,a;
	scanf("%d",&n);
	head=NULL;
	for(i=1;i<=n;i++){
		scanf("%d".&a);
		p=(node *)malloc(sizeof(node));
		p->data=a;
		p->next=NULL;
		if(head=NULL)head=p;
		else q->next=p;
		q=p;
	}
	t=head;
	while(t!=NULL){
		printf("%d\n",t->data);
		t=t->next;
	}
	return 0;
}