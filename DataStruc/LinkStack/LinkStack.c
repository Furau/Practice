#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0

typedef int Status;

typedef int SElemType;

typedef struct StackNode{
  SElemType data;
  struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack{
  LinkStackPtr top;
  int count;
}LinkStack;

Status Push(LinkStack *S,SElemType e){
  LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));
  s->data=e;
  s->next=S->top;
  S->top=s;
  S->count++;
  return OK;
}

Status Pop(LinkStack *S,SElemType *e){
  LinkStackPtr p;
  if(StackEmpty(*s))return ERROR;
  *e=S->top->data;
  p=S->top;
  S->top=S->top->next;
  free(p);
  S->count--;
  return OK;
}
