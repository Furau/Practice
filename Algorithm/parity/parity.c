#include <stdio.h>
#include <stdlib.h>

unsigned int parity(unsigned int arg){
  unsigned int a;
  a=arg;
  a^=a>>16;
  a^=a>>8;
  a^=a>>4;
  a^=a>>2;
  a^=a>>1;
  return a&1;
}

int main(int argc,char **argv){
  unsigned int a=3;
  unsigned int c=14;
  unsigned int b;
  b=parity(a);
  printf("Parity is %u\n",b);
  b=parity(c);
  printf("Parity is %u\n",b);
  return 0;
}
