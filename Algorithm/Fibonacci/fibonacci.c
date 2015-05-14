#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){
  if(n<=1)return 1;
  else
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(int *argv,char **argc){
  printf("The fibonacci sequence is %d\n",fibonacci(6));
  return 0;
}
