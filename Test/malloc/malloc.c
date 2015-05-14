#include <stdio.h>

int main(void){
     char *p;
     int i;
     p=(char *)malloc(10*sizeof(char));
     for(i=0;i<10;i++){
	scanf("%c",p+i);
	}
	printf("%s\n",p);
	free(p);
}

