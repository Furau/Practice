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

typedef struct EdgeNode{
  int adjvex;
  EdgeType weight;
  struct EdgeNode *next;
}EdgeNode;

typedef struct vexNode{
  VertexType data;
  struct EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct AdjList{
  AdjList adjList;
  int numVertexes,numEdges;
}GraphAdjList;

void CreateALGraph(GraphAdjList *G){
  int i,j,k;
  EdgeNode *e;
  printf("Input the vertex number and edge number:\n");
  scanf("%d,%d",&G->numVertexes,&G->numEdges);
  for(i=0;i<G->numVertexes;i++){
    scanf("%c",&G->adjList[i].data);
    G->adjList[i].firstedge=NULL;
  }
  for(k=0;k<G->numEdges;k++){
    printf("Input edge(vi,vj) number:\n");
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

void BFSTraverse(GraphAdjList *GL){
  int i;
  EdgeNode *p;
  Queue Q;
  for(i=o;i<GL->numVertexes;i++)visited[i]=FALSE;
  InitQueue(&Q);
  for(i=0;i<GL->numVertexes;i++){
    if(!visited[i]){
      visited[i]=TRUE;
      printf("%c",GL->adjList[i].data);
      EnQueue(&Q,i);
      while(!QueueEmpty(Q)){
        DeQueue(&Q,&i);
        p=GL->adjList[i].firstedge;
        while(p){
          if(!visited[p->adjvex]){
            visited[p->adjvex]=TRUE;
            printf("%c",GL->adjList[p->adjvex].data);
            EnQueue(&Q,p->adjvex);
          }
          p=p->next;
        }
      }
    }
  }
}
