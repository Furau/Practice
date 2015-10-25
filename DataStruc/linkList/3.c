#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0

typedef int Status;

typedef int ElemType;

typedef struct Node{
  ElemType data;
  struct Node *next;
}Node;

typedef struct Node *LinkList;

Status GetElem(LinkList L,int i,ElemType *e){
  int j;
  LinkList p;
  p=L->next;
  j=1;
  while(p&&j<i){
    p=p->next;
    ++j;
  }
  if(!p||j>i)return ERROR;
  *e=p->data;
  return OK;
}

Status ListInsert(LinkList *L,int i,ElemType e){
  int j;
  LinkList p,q;
  p=*L;
  j=1;
  while(p&&j<i){
    p=p->next;
    ++j;
  }
  if(!p||j>i)return ERROR;
  q=(LinkList)malloc(sizeof(Node));
  q->data=e;
  q->next=p->next;
  p->next=q;
  return OK;
}

Status ListDelete(LinkList *L,int i,ElemType *e){
  int j;
  LinkList p,q;
  p=*L;
  j=1;
  while(p&&j<i){
    p=p->next;
    ++j;
  }
  if(!p||j>i)return ERROR;
  q=p->next;
  p->next=q->next;
  *e=q->data;
  free(q);
  return OK;
}
  
