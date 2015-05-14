#include <stdio.h>
#include <stdlib.h>
#include "status.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int SElemtype;
typedef struct Sqstack{
  SElemtype *base;
  SElemtype *top;
  int stacksize;
}Sqstack;

Status InitStack(Sqstack *S){
  S->base = (SElemtype *)malloc(STACK_INIT_SIZE*sizeof(SElemtype));
  if(!S->base)exit(OVERFLOW);
  S->top = S->base;
  S->stacksize =STACK_INIT_SIZE;
  return OK;
}

Status Gettop(Sqstack S,SElemtype *e){
  if(S.top==S.base)return ERROR;
  *e = *(S.top-1);
  return OK;
    }

Status Push(Sqstack *S,SElemtype e){
  if(S->top-S->base>=S->stacksize){
    S->base = (SElemtype *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemtype));
    if(!S->base)exit(OVERFLOW);
    S->top=S->base+S->stacksize;
    S->stacksize+=STACKINCREMENT;
  }
  *S->top++=e;
  return OK;
}

Status Pop(Sqstack *S,SElemtype *e){
  if(S->top == S->base)return ERROR;
  *e=*--S->top;
  return OK;
}

int main(int argc,char **argv){
  SElemtype e,a;
  Sqstack sq;
  a=1;
  InitStack(&sq);
  Push(&sq,a);
  Pop(&sq,&e);
  printf("%d\n",e);
  return 0;
}
