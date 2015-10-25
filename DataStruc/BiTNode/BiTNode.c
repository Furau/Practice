#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0

typedef int Status;

typedef int TElemType;

typedef struct BitNode{
  TElemType data;
  struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
