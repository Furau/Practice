#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0

typedef int ElemType;

typedef int Status;

#define MAXSIZE 30

typedef struct sqlist{
	ElemType data[MAXSIZE];
	int len;
}sqlist;


Status GetElem(sqlist l,int i,ElemType *e){
	
}