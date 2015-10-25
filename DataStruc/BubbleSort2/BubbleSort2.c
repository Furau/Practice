#define MAXSIZE 1

typedef struct{
  int r[MAXSIZE+1];
  int length;
}SqList;

void swap(SqList *L,int i,int j){
  int temp=L->r[i];
  L->[i]=L->[j];
  L->[j]=temp;
}

void BubbleSort2(SqList *L){
  int i,j;
  Status flag=TRUE;
  for(i=1;i<L->length&&flag;i++){
    flag=FALSE;
    for(j=L->length-1;j>=i;j--){
      if(L->r[j]>L->r[j+1]){
      swap(L,j,j+1);
      flag=TRUE;
       }
    }
  }
}   
