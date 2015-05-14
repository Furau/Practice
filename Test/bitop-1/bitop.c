#include <stdio.h>
#include <stdlib.h>

int isOddnumber(int n){
  return n&1;
}

void changenumber(int *a,int *b){
  (*a)^=(*b);
  (*b)^=(*a);
  (*a)^=(*b);
}

int getminint(void){
  return 1<<31;
}

int getmaxint(void){
  return ((unsigned int) -1)>>1;
}

int multwo(int n){
  return n<<1;
}

int divtwo(int n){
  return n>>1;
}

int main(int argc,char **argv){
  int a,b;
  switch(isOddnumber(5)){
  case 1:{
          printf("The number is Odd\n");
	  break;
  }
  default:{
            printf("The number is not Odd\n");
	    break;
 }
  }
  a=1;
  b=2;
  changenumber(&a,&b);
  printf("a is %d,b is %d\n",a,b);
  printf("The min int num is %d\n",getminint());
  printf("The max int num is %d\n",getmaxint());
  printf("n mul 2 is %d\n",multwo(a));
  printf("n div 2 is %d\n",divtwo(a));
  return 0;
}
