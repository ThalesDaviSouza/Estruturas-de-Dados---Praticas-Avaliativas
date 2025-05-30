#include <stdio.h>
#include <stdlib.h>
#include "unionFind.h"

UnionFind* NovoUnionFind(int quantidade_subconjuntos){
  UnionFind* conjuntos = (UnionFind*)malloc(sizeof(UnionFind) * quantidade_subconjuntos);

  for(int i = 0; i < quantidade_subconjuntos; i++){
    Make(conjuntos, i);
  }

  return conjuntos;
}

void Make(UnionFind* dsu, int x){
  dsu[x].representante = x;
  dsu[x].rank = 0;
}

int Find(UnionFind* dsu, int x){
  while (dsu[x].representante != x)
  {
    x = dsu[x].representante;
  }
  
  return x;
}

void Union(UnionFind* dsu,int x, int y){
  int raizX = Find(dsu, x);
  int raizY = Find(dsu, y);

  if(raizX != raizY){
    if(dsu[raizX].rank < dsu[raizY].rank) 
    {
      dsu[raizX].representante = dsu[raizY].representante;
    }
    else if(dsu[raizX].rank > dsu[raizY].rank)
    {
      dsu[raizY].representante = dsu[raizX].representante;
    }
    else {
      dsu[raizX].representante = dsu[raizY].representante;
      dsu[raizX].rank++;
    }
  }
}
