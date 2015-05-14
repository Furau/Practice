#include <stdio.h>
#include <stdlib.h>

int factor(int n)
{
  if(n==1)return 1;
  else 
    return n*factor(n-1);
}

int main(int argc,char **argv){
  printf("The factor is %d\n",factor(10));
  return 0;
}
