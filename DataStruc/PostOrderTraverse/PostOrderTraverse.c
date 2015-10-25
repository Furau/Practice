#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0
#define OVERFLOW -1

typedef int Status;

typedef char TElemType;

typedef struct BiTNode{
  TElemType data;
  struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void PostOrderTraverse(BiTree T){
  if(T==NULL)return;
  PostOrderTraverse(T->lchild);
  PostOrderTraverse(T->rchild);
  printf("%c",T->data);
}

void CreateBiTree(BiTree *T){
  TElemType ch;
  scanf("%c",&ch);
  if(ch=='#')*T=NULL;
  else{
    *T=(BiTree)malloc(sizeof(BiTNode));
    if(!*T)exit(OVERFLOW);
    CreateBiTree(&(*T)->lchild);
    CreateBiTree(&(*T)->rchild);
    (*T)->data=ch;
  }
}
