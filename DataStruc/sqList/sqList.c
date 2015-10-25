#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0
typedef int Status;

#define MAXSIZE 30

typedef int ElemType;
typedef struct{
  ElemType data[MAXSIZE];
  int length;
}SqList;

Status GetElem(SqList L,int i,ElemType *e){
  if(L.length==0||i<1||i>L.length)return ERROR;
  *e=L.data[i-1];
  return OK;
}

Status ListInsert(SqList *L,int i,ElemType e){
  int k;
  if(L->length==MAXSIZE)return ERROR;
  if(i<1||i>L->length+1)return ERROR;
  if(i<=L->length){
    for(k=L->length-1;k>=i-1;k--)L->data[k+1]=L->data[k];
  }
  L->data[i-1]=e;
  L->length++;
  return OK;
}

Status ListDelete(SqList *L,int i,ElemType *e){
  int k;
  if(L->length==0)return ERROR;
  if(i<1||i>L->length)return ERROR;
  *e=L->data[i-1];
  if(i<L->length){
    for(k=i;k>=L->length;k++)L->data[k-1]=L->data[k];
  }
    L->length--;
    return OK;
}

int main(){
  int i,e;
  i=1;
  e=10;
  SqList *L;
  L=(SqList *)malloc(sizeof(SqList));
  ListInsert(L,i,e);
  printf("%d\n",L->data[i-1]);
  printf("%d\n",L->length);
  return 0;
}
