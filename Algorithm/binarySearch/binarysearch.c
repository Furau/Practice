#include <stdio.h>
#include <stdlib.h>

int binarysearch(int *a,int x,int n);

int main(int argc,char **argv){
  int b[]={1,2,3,4,5,6,7,8,9,10};
  int pos=binarysearch(b,1,10);
  printf("The position is in %d\n",pos+1);
  return 0;
}

int binarysearch(int *a,int x,int n){
  int left=0;
  int right=n-1;
  while(left<=right){
    int middle=(left+right)/2;
    if(x==a[middle])return middle;
    if(x>a[middle])left=middle+1;
    else right=middle-1;
  }
  return -1;
}
