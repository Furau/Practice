int Interpolation_Search(int *a,int n,int key){
  int low,mid,high;
  low=1;
  high=n;
  while(low<=high){
    mid=low+((key-a[low])/(a[high]-a[low]))*(high-low);
    if(key<a[mid])high=mid-1;
    else if(key>a[mid])low=mid+1;
    else return mid;
  }
  return 0;
}
