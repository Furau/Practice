#define MAXSIZE 10

typedef struct{
  int r[MAXSIZE+1];
  int length;
}SqList;

void swap(SqList *L,int i,int j){
  int temp=L->r[i];
  L->r[i]=L->r[j];
  L->r[j]=temp;
}

void QuickSort(SqList *L){
  QSort(L,1,L->length);
}

void QSort(SqList *L,int low,int high){
  int pivot;
  if(low<high){
    pivot=Partition(L,low,high);
    QSort(L,low,pivot-1);
    QSort(L,pivot+1,high);
  }
}

int Partition(SqList *L,int low,int high){
  int pivotkey;
  pivotkey=L->r[low];
  while(low<high){
    while(low<high&&L->r[high]>=pivotkey)high--;
    swap(L,low,high);
    while(low<high&&L->r[low]<=pivotkey)low++;
    swap(L,low,high);
  }
  return low;
}
