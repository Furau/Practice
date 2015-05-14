#include <stdio.h>

int main(int argc,char **argv){
           
  char a;
  a=0x2f;
  int b;
  b=2;
  b=b<<1;
  printf("%d\n",b);
  b=b>>2;
  printf("%d\n",b);
  b|=0x01;
  printf("%d\n",b);
  b&=0x00;
  printf("%d\n",b);
  b=b^0x01;
  printf("%d\n",b);
  b=~b;
  printf("%d\n",b);
  b=~b+1;
  printf("%d\n",b);
  b=~b+1;
  printf("%d\n",b);
  printf("%c\n",a);
  printf("%x\n",a);
  return 0;
}
