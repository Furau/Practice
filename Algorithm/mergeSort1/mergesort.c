#include <stdio.h>
#include <stdlib.h>

void merge(int *c,int *d,int l,int m,int r){
  int i=l;
  int j=m+1;
  int k=l;
  while((i<=m)&&(j<=r))
    if(c[i]<=c[j])d[k++]=c[i++];
    else d[k++]=c[j++];
  if(i>m)for(int q=j;q<=r;q++)d[k++]=c[q];
  else for(int p=i;p<=m;p++)d[k++]=c[p];
}

void mergePass(int *x,int *y,int s){
  int i=0;
  int x_len=10;
  while(i<=x_len-2*s){
    merge(x,y,i,i+s-1,i+2*s-1);
    i=i+2*s;
  }
  if(i+s<x_len)merge(x,y,i,i+s-1,x_len-1);
  else for(int j=i;j<x_len;j++)y[j]=x[j];
}

void mergesort(int *a){
  int a_len=10;
  int b[a_len];
  int s=1;
  while(s<a_len){
    mergePass(a,b,s);
    s+=s;
    mergePass(b,a,s);
    s+=s;
  }
}
int main(int argc,char **argv){
  int a[]={4,3,8,6,5,1,2,9,7,10};
  mergesort(a);
  for(int i=0;i<10;i++)printf("%d\n",*(a+i));
  return 0;
}
    
