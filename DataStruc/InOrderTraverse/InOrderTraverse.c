#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0

typedef int Status;

typedef char TElemType;

typedef struct BiTNode{
  TElemType data;
  struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void InOrderTraverse(BiTree T){
  if(T==NULL)return;
  InOrderTraverse(T->lchild);
  printf("%c",T->data);
  InOrderTraverse(T->rchild);
}
