#define MAXSIZE 10

typedef struct  {
  int r[MAXSIZE+1];
  int length;
}SqList;

void (SqList *L,int i,int j){
  int temp=L->r[i];
  L->r[i]=L->r[j];
  L->r[j]=temp;
}

void BubbleSort(SqList *L){
  int i,j;
  for(i=1;i<L->length;i++){
    for(j=L->length-1;j>=i;j--){
      if(L->r[j]>L->r[j+1]){
        swap(L,j,j+1);
      }
    }
  }
}
