#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0

typedef int Status;

typedef int SElemType;

typedef struct{
  SElemType data[MAXSIZE];
  int top;
}SqStack;

Status Push(SqStack *S,SElemType e){
  if(S->top==MAXSIZE-1)return ERROR;
  S->top++;
  S->data[S->top]=e;
  return OK;
}

Status Pop(SqStack *S,SElemType *e){
  if(S->top==-1)return ERROR;
  *e=S->data[S->top];
  S->top--;
  return OK;
}
