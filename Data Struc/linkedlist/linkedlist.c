#include <stdio.h>
#include <stdlib.h>
#include "status.h"

typedef int Elemtype;

typedef struct LNode{
	Elemtype data;
 	struct LNode *next;
	}LNode,*Linklist;

Status CreateList_L(Linklist *L,int n){
		int i;
		Linklist p;
		*L=(Linklist)malloc(sizeof(LNode));
		(*L)->next=NULL;
		for(i=n;i>0;--i){
			p=(Linklist)malloc(sizeof(LNode));
			scanf("%d",&p->data);
			p->next = (*L)->next;
			(*L)->next=p;
			}
			return 0;
	} 

Status GetElem_L(Linklist L,int i,Elemtype *e){
		Linklist p;
              p=L->next;
		int j=1;	
		while(p&&j<i){
			p=p->next;
			++j;
			}
		if(!p||j>i)return ERROR;
		*e=p->data;
		return OK;
		}
	
int main(int argc,char *argv[]){
	Elemtype a;
	int i;
	Linklist linklist;
	Linklist p;
	CreateList_L(&linklist,3);
	p=linklist->next;
	for(i=0;i<3;i++){
		printf("%d\n",p->data);
		p=p->next;
		}
	GetElem_L(linklist,2,&a);
	printf("%d\n",a);
	return 0;
}
