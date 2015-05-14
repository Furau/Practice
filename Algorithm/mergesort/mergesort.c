#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ARRAY_SIZE_ONE 10
#define ARRAY_SIZE_TWO 20

void merge(int *a,int start,int mid,int end){
  int n1=mid-start+1;
  int n2=end-mid;
  
  int la[n1+1];
  int rb[n2+1];
  
  for(int i=0;i<n1;++i)la[i]=a[start+i];
  la[n1]=INT_MAX;
  for(int i=0;i<n2;++i)rb[i]=a[mid+i+1];
  rb[n2]=INT_MAX;
  
  int la_cnt=0;
  int rb_cnt=0;

  for(int i=start;i<=end;++i)
    if(la[la_cnt]<rb[rb_cnt])
      {
	a[i]=la[la_cnt];
	la_cnt++;
      }
    else
      {
	a[i]=rb[rb_cnt];
	rb_cnt++;
      }
}

void merge_sort(int *a,int start,int end){
  if(start<end){
    int mid = start+(end-start)/2;
    merge_sort(a,start,mid);
    merge_sort(a,mid+1,end);
    merge(a,start,mid,end);
  }
}

void main(){
  int a[]={1,3,5,7,9,0,8,6,4,2};
  merge_sort(a,0,ARRAY_SIZE_ONE-1);
  printf("Print Sorted Array:\n");
  for(int i=0;i<ARRAY_SIZE_ONE;++i)printf("%d ",a[i]);
  printf("\n");
  int b[]={1,3,5,7,9,0,8,6,4,2,11,13,16,18,20,19,17,15,12,10};
  merge_sort(b,0,ARRAY_SIZE_TWO-1);
  printf("Print Sorted Array:\n");
  for(int i=0;i<ARRAY_SIZE_TWO;++i)printf("%d ",b[i]);
  printf("\n");
}
