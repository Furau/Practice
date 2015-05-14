#include <stdio.h>
#include <stdlib.h>
#define true 1

void mymathswap(int *a,int i,int j){
  int x;
  x=a[i];
  a[i]=a[j];
  a[j]=x;
}

int partition(int *a,int p,int r){
  int i=p;
  int j=r+1;
  int x=a[p];
  while(true){
    while(a[++i]<x);
    while(a[--j]>x);
    if(i>=j)break;
    mymathswap(a,i,j);
  }
  a[p]=a[j];
  a[j]=x;
  return j;
}

void qSort(int *a,int p,int r){
  if(p<r){
    int q=partition(a,p,r);
    qSort(a,p,q-1);
    qSort(a,q+1,r);
  }
}

int main(){
  int  a[]={1,5,7,2,3,6,4,8,9,0};
  qSort(a,0,9);
  for(int i=0;i<10;i++)printf("%d\n",*(a+i));
  return 0;
}
