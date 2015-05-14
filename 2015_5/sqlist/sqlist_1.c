#include <stdio.h>
#include <stdlib.h>


#define ERROR 0
#define FALSE 0
#define OK 1
#define TRUE 1

typedef int Status;

typedef int ElemType;

#define MAXSIZE 30

typedef struct sqlist{
	ElemType data[MAXSIZE];
	int len;
}sqlist;


Status GetElem(sqlist l,int i,ElemType *e){
	if(l->len==0||i<1||i>l-len)return ERROR;
	*e=l->data[i-1];
	return OK;
}

Status ListInsert(sqlist *l,int i,ElemType e){
	int k;
	if(l->len==MAXSIZE)return ERROR;
	if(i<1||i>l->len+1)return ERROR;
	if(i<l->len){
		for(k=l->len-1;k>=i-1;k--)l->data[k+1]=l->data[k];
	}
	l->data[i-1]=e;
	l->len++;
	return OK;
}

Stauts ListDelete(sqlist *l,int i,ElemType *e){
	int k;
	if(l->len==0)return ERROR;
	if(i<1||i>l->len)return ERROR;
	*e=l->data[i-1];
	if(i<l->len){
		for(k=i;k<l->len;k++)l->data[k-1]=l->data[k];
	}
	l->len--;
	return OK;
}