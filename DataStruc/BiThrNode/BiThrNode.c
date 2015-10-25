#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define TRUE 1 
#define ERROR 0
#define FALSE 0

typedef int Status;

typedef char TElemType;

typedef enum{Link,Thread}PointerTag;

typedef struct BiThrNode{
  TElemType data;
  struct BiThrNode *lchild,*rchild;
  PointerTag LTag;
  PointerTag RTag;
}BiThrNode,*BiThrTree;

BiThrTree pre;

void InThreading(BiThrTree p){
  if(p){
    InThreading(p->lchild);
    if(!p->lchild){
      p->LTag=Thread;
      p->lchild=pre;
    }
    if(!pre->rchild){
      pre->RTag=Thread;
      pre->rchild=p;
    }
    pre=p;
    InThreading(p->rchild);
  }
}

Status InOrderTraverse_Thr(BiThrTree T){
  BiThrTree p;
  p=T->lchild;
  while(p!=T){
    while(p->LTag==Link)p=p->lchild;
    printf("%c",p->data);
    while(p->RTag==Thread&&p->rchild!=T){
      p=p->rchild;
      printf("%c",p->data);
    }
    p=p->rchild;
  }
  return OK;
}
