#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0

typedef int Status;

#define MAXVEX 100

typedef int Boolean;
Boolean visited[MAXVEX];

typedef char VertexType;
typedef int EdgeType;

typedef struct MGraph{
  VertexType vexs[MAXVEX];
  EdgeType arc[MAXVEX][MAXVEX];
  int numVertexes,numEdges;
}MGraph;

void CreateMGraph(MGraph *G){
  int i,j,k,w;
  printf("Please input the vex number and edge number:\n");
  scanf("%d,%d",&G->numVertexes,&G->numEdges);
  for(i=0;i<G->numVertexes;i++)scanf("%c",&G->vexs[i]);
  for(k=0;k<G->numEdges;k++){
    printf("Please input the (vi,vj) and weight:\n");
    scanf("%d,%d,%d",&i,&j,&w);
    G->arc[i][j]=w;
    G->arc[j][i]=G->arc[i][j];
  }
}

void BFSTraverse(MGraph G){
  int i,j;
  Queue Q;
  for(i=0;i<G.numVertexes;i++)visited[i]=FALSE;
  InitQueue(&Q);
  for(i=0;i<G.numVertexes;i++){
    if(!visited[i]){
      visited[i]=TRUE;
      printf("%c",G.vexs[i]);
      EnQueue(&Q,i):
      while(!QueueEmpty(Q)){
        DeQueue(&Q,&i);
        for(j=0;j<G.numVertexes;j++){
          if(G.arc[i][j]==1&&!visited[j]){
            visited[j]=TRUE;
            printf("%c",G.vexs[j]);
            EnQueue(&Q,j);
          }
        }
      }
    }
  }
}
