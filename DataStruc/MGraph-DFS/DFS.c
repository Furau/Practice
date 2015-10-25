#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0

typedef int Status;

typedef char VertexType;
typedef int EdgeType;

#define MAXVEX 100
#define INFINITY 65535

typedef int Boolean;
Boolean visited[MAXVEX];

typedef struct VertexNode{
  VertexType vexs[MAXVEX];
  EdgeType arc[MAXVEX][MAXVEX];
  int numVertexes,numEdges;
}MGraph;

void CreateMGraph(MGraph *G){
  int i,j,k,w;
  printf("Please input the vertex number and edge number:\n");
  scanf("%d,%d",&G->numVertexes,&G->numEdges);
  for(i=0;i<G->numVertexes;i++)scanf("%c",&G->vexs[i]);
  for(i=0;i<G->numVertexes;i++)
    for(j=0;j<G->numVertexes;j++)
      G->arc[i][j]=INFINITY;
  for(k=0;k<G->numEdges;k++){
    printf("Please input (vi,vj),i,j,w:\n");
    scanf("%d,%d,%d",&i,&j,&w);
    G->arc[i][j]=w;
    G->arc[j][i]=G->arc[i][j];
  }
}


void DFS(MGraph G,int i){
  int j;
  visited[i]=TRUE;
  printf("%c",G.vexs[i]);
  for(j=0;j<G.numVertexes;j++)
    if(G.arc[i][j]==1&&!visited[j])DFS(G,j);
}

void DFSTraverse(MGraph G){
  int i;
  for(i=0;i<G.numVertexes;i++)visited[i]=FALSE;
  for(i=0;i<G.numVertexes;i++)
    if(!visited[i])DFS(G,i);
}
