#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unionFind.h"
#include "minHeap.h"

int main(int argc, char ** argv){
  int numVertices, numArestas;
  int u, v, custoAux;
  int custo = 0;
  int count = 0;
  Heap* arestas = NULL;
 
  scanf("%d %d%*c", &numVertices, &numArestas);
  
  UnionFind* conjuntos = NovoUnionFind(numVertices);
  arestas = NovoHeap(numArestas);
  
  for(int i = 0; i < numArestas; i++){
    scanf("%d %d %d%*c", &u, &v, &custoAux);
    Inserir(arestas, u, v, custoAux);
  }

  for(int i = 0; i < numArestas; i++){
    Aresta aresta = Remover(arestas);
    int u, v;
    u = Find(conjuntos, aresta.u);
    v = Find(conjuntos, aresta.v);

    if(u != v){
      Union(conjuntos, u, v);
      custo += aresta.custo;
      count++;
    }

    if(count == numVertices-1){
      break;
    }
  }

  printf("%d", custo);
  
  free(conjuntos);
  DeletaHeap(arestas);

  return 0;
}