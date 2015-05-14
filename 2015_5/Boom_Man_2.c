#include <stdio.h>

typedef struct Node{
	int x;
	int y;
}Nods;

char a[20][20];

int GetNum(int i,int i){
	int sum,x,y;
	sum=0;
	x=i;
	y=j;
	while(a[x][y]!='#'){
		if(a[x][y]=='G')sum++;
		x--;
	}
	x=i;
	y=j;
	while(a[x][y]!='#'){
		if(a[x][y]=='G')sum++;
		x++;
	}
	x=i;
	y=j;
	while(a[x][y]!='#'){
		if(a[x][y]=='G')sum++;
		y--;
	}
	x=i;
	y=j;
	while(a[x][y]!='#'){
		if(a[x][y]=='G')sum++;
		y++;
	}
	return sum;
}

int main(){
	Node que[401];
	int head,tail;
	int book[20][20]={0};
	int i,j,k,sum,max=0,mx,my,n,m,startx,starty,tx,ty;
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	for(i=0;i<=n-1;i++)scanf("%s",a[i]);
	head=1;
	tail=1;
	que[tail].x=startx;
	que[tail].y=starty;
	tail++;
	book[startx][starty]=1;
	max=GetNum(startx,starty);
	mx=startx;
	my=starty;
	while(head<tail){
		for(k=0;k<=3;k++){
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			if(tx<0||tx>n||ty<0||ty>m)continue;
			if(a[x][ty]=='.'&&book[tx][ty]==0){
				book[tx][ty]=1;
				que[tail].x=tx;
				que[tail].y=ty;
				tail++;
				sum=GetNum(tx,ty);
				if(sum>max){
					max=sum;
					mx=tx;
					my=ty;
				}
			}
		}
		head++;
	}
	printf("Put boom on (%d,%d),could kill %d enemies\n"",mx,my,max);
	return 0;
}