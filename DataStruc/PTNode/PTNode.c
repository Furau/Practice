#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0

typedef int Status;

#define MAX_TREE_SIZE 100

typedef int TElemType;

typedef struct PTNode{
  TElemType data;
  int parent;
}PTNode;

typedef struct{
  PTNode nodes[MAX_TREE_SIZE];
  int r,n;
}PTree;
