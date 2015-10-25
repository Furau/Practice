#define MAXSIZE 1

typedef struct{
  int r[MAXSIZE+1];
  int length;
}SqList;

void swap(SqList *L,int i,int j){
  int temp=L->r[i];
  L->r[i]=L->r[j];
  L->r[j]=temp;
}

void MergeSort(SqList *L){
  MSort(L->r,L->r,1,L->length);
}

void MSort(int SR[],int TR1[],int s,int t){
  int m;
  int TR2[MAXSIZE+1];
  if(s==t)TR1[s]=SR[s];
  else {
    m=(s+t)/2;
    MSort(SR,TR2,s,m);
    MSort(SR,TR2,m+1,t);
    Merge(TR2,TR1,s,m,t);
  }
}

void Merge(int SR[],int TR[],int i,int m,int n){
  int j,k,l;
  for(j=m+1,k=i;i<=m&&j<=n;k++){
    if(SR[i]<SR[j])TR[k]=SR[i++];
    else TR[k]=SR[j++];
  }
  if(i<=m){
    for(l=0;l<=m-i;l++)TR[k+l]=SR[i+l];
  }
  if(j<=n){
    for(l=0;l<=n-j;l++)TR[k+l]=SR[j+l];
  }
}
