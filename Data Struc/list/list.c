#include <stdio.h>
#include <stdlib.h>
#include "status.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int Elemtype;

typedef struct {
	Elemtype *elem;
	int length;
	int listsize;
}Sqlist;

Status Initlist_sq(Sqlist *L){
	L->elem = (Elemtype *)malloc(LIST_INIT_SIZE*sizeof(Elemtype));
	if(!L->elem)exit(OVERFLOW);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

Status ListInsert_sq(Sqlist *L,int i, Elemtype e){
	Elemtype *p,*q,*newbase;
	if(i<1||i>L->length+1)return ERROR;
		if(L->length>=L->listsize){
			newbase=(Elemtype *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(Elemtype));
			if(!newbase)exit(OVERFLOW);
			L->elem=newbase;
			L->listsize+=LISTINCREMENT;
		}
	       q=&(L->elem[i-1]);
		for(p=&(L->elem[L->length-1]);p>=q;--p)*(p+1)=*p;
		*q=e;
		++L->length;
              return OK;
}

Status ListDelete_sq(Sqlist *L,int i,Elemtype *e){
		Elemtype *p,*q;
		printf("The length is %d\n",L->length);
		printf("The arg is %d\n",i);
		if((i<1)||(i>L->length))return ERROR;
			p=&(L->elem[i-1]);
			*e=*p;
			q=L->elem+L->length-1;
			for(++p;p<=q;++p)*(p-1)=*p;
				--L->length;
				return OK;
}
			
int LocateELem_sq(Sqlist L,Elemtype e,Status (*compare)(Elemtype,Elemtype)){
	 int i;
        Elemtype *p;
	 i=1;
	 p=L.elem;
	 while(i<L.length&&!(compare(*p++,e)))++i;
		if(i<=L.length)return i;
		    else return 0;
}

void MergeList_sq(Sqlist La,Sqlist Lb,Sqlist *Lc){
              Elemtype *pa,*pb,*pc,*pa_last,*pb_last;
		pa=La.elem;
		pb=Lb.elem;
		Lc->listsize=Lc->length=La.length+Lb.length;
		pc=Lc->elem=(Elemtype *)malloc(Lc->listsize*sizeof(Elemtype));
		if(!Lc->elem)exit(OVERFLOW);
		pa_last=La.elem+La.length-1;
		pb_last=Lb.elem+Lb.length-1;
		while(pa<=pa_last&&pb<=pb_last){
			if(*pa<=*pb)*pc++=*pa++;
			else *pc++=*pb++;
		}
		while(pa<=pa_last)*pc++=*pa++;
		while(pb<=pb_last)*pc++=*pb++;
		}
		
			

Status comp(Elemtype i,Elemtype j){
	if(i==j)return OK;
	else return FALSE;
}
 
int main(int argc,char **argv)
{
	int i,j;
	Sqlist list,list1,list2;
 	Status s;
	Elemtype a=211;
	Elemtype b=0;
	s=Initlist_sq(&list);
	Initlist_sq(&list1);
	Initlist_sq(&list2);
	printf("The Status code is %d\n",s);
	for(i=0;i<10;i++){
		ListInsert_sq(&list,1,i);
		ListInsert_sq(&list1,1,i);
	}
	for(i=0;i<10;i++){
		printf("%d\n",list.elem[i]);
		}
	ListDelete_sq(&list,3,&b);
	printf("%d\n",b);
	j=LocateELem_sq(list,3,comp);
	printf("the location is %d\n",j);
	MergeList_sq(list,list1,&list2);
	for(i=0;i<list2.length;i++){
			printf("%d\n",list2.elem[i]);
			}
	return 0;
}
