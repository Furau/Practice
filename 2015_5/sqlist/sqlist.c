#include <stdio.h>
#include <stdlib.h>


#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0

typedef int Status;

#define MAXSIZE 30

typedef  int ElemType;

typedef struct sqlist{
	ElemType data[MAXSIZE];
	int len;
}sqlist;

Status GetElem(sqlist l,int i,ElemType *e){
	if(l.len==0||i<1||i>l.len)return ERROR;
	*e=l.data[i-1];
	return OK;
}

Status ListInsert(sqlist *l,int i,ElemType e){
	int k;
	if(l->len==MAXSIZE)return ERROR;
	if(i<1||i>l->len+1)return ERROR;
	if(i<=l->len){
		for(k=l->len-1;k>=i-1;k--)l->data[k+1]=l->data[k];
	}
	l->data[i-1]=e;
	l->len++;
	return OK;
}

Status ListDelete(sqlist *l,int i,ElemType *e){
	int k;
	if(l->len==0)return ERROR;
	if(i<1||i>l-len)return ERROR;
	*e=l->data[i-1];
	if(i<l->len){
		for(k=i;k<=l->len;k++){
			l->data[k-1]=l->data[k];
		}
	}
	l->len--;
	return OK;
}

void main(void){
	int i,e;
	i=1;
	e=10;
	sqlist *L;
	L=(sqlist *)malloc(sizeof(sqlist));
	ListInsert(L,i,e);
	printf("%d\n",L->data[i-1]);
	printf("%d\n",L->len);
	return 0;	
}