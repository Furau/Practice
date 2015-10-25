#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0

typedef int Status;

#define MAXVEX 100

typedef int PathMatrix[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

void ShortestPath_Floyd(MGraph G,Pathmatrix *P;ShortPathTable *D){
  int v,w,k;
  for(v=0;v<G.numVertexes;++v){
    for(w=0;w<G.numVertexes;++w){
      (*D)[v][w]=G.matrix[v][w];
      (*P)[v][w]=w;
    }
  }
  for(k=0;k<G.numVertexes;++k){
    for(v=0;v<g.numVertexes;++v){
      for(w=0;w<G.numVertexes;++w){
        if((*D)[v][w]>(*D)[v][k]+(*D)[k][w]){
          (*D)[v][w]=(*D)[v][k]+(*D)[k][w];
          (*P)[v][w]=(*P)[v][k];
        }
      }
    }
  }
}
