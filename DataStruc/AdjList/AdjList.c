#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0

typedef int Status;

#define MAXVEX 100

typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode{
  int adjvex;
  EdgeType weight;
  struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode{
  VertexType data;
  EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct{
  AdjList adjList;
  int numVertexes,numEdges;
}GraphAdjList;

void CreateALGraph(GraphAdjList *G){
  int i,j,k;
  EdgeNode *e;
  printf("Please input the vertex number and edge number:\n");
  scanf("%d,%d",&G->numVertexes,&G->numEdges);
  for(i=0;i<G->numVertexes;i++){
    scanf("%c",&G->adjList[i].data);
    G->adjList[i].firstedge=NULL;
  }
  for(k=0;k<G->numEdges;k++){
    printf("Please input the edge(vi,vj)\n");
    scanf("%d,%d",&i,&j);
    e=(EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex=j;
    e->next=G->adjList[i].firstedge;
    G->adjList[i].firstedge=e;
    e=(EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex=i;
    e->next=G->adjList[j].firstedge;
    G->adjList[j].firstedge=e;
  }
}
