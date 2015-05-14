#include <stdio.h>
int main(){
	char a[20][21];
	int i,j,sum,map=0,p,q,x,y,n,m;
	scanf("%d %d",&n,&m);
	for(i=0;i<=n-1;i++){
		for(j=0;i<=m-1;j++){
			if(a[i][j]=='.'){
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
					if(a[x][y]=='G')sum++
					y++;
				}
				if(sum>map){
					map=sum;
					p=i;
					q=j;
				}
			}
		}
	}
	printf("Put Boom on (%d,%d),at most kill %d enemies\n",p,q,map);
	return 0;
}