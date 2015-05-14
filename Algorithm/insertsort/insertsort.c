#include <stdio.h>
#include <stdlib.h>

#define ARRAYSIZE 5

void insertionsort(int a[],int len)
{
	int i,j,key;
	for(j=2;j<=len;j++)
		{
                    key=a[j];
		    i=j-1;
		    while(i>0&&a[i]>key)
			{
			   a[i+1]=a[i];
			   i=i-1;
			   }
			 a[i+1]=key;
			 }
}

void getint(int *a,int len){
     int i;
     for(i=0;i<len;i++){
	scanf("%d",a++);
	}
	}

void main(){
     int a[ARRAYSIZE];
     int i;
     int len=sizeof(a)/sizeof(int);
     printf("The siez of this array is %d\n",len);
     getint(a,len);
     for(i=0;i<len;i++){
       printf("Array %d is %d\n",i,a[i]);
       }
     insertionsort(a,len);
     for(i=0;i<len;i++){
       printf("The sorted Array %d is %d\n",i,a[i]);
     }
     }
			
