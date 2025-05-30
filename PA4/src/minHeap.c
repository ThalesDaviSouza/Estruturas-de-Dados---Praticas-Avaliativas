#include <stdio.h>
#include <stdlib.h>
#include "minHeap.h"

Heap* NovoHeap(int maxsize){
  Heap* newHeap = (Heap*)malloc(sizeof(Heap));

  newHeap->tamanho = 0;
  newHeap->dados = (Aresta*)malloc(sizeof(Aresta) * maxsize);

  return newHeap;
}

void DeletaHeap(Heap* h){
  free(h->dados);
  free(h);
}

void Inserir(Heap* h, int u, int v, int custo){
  h->dados[h->tamanho].custo = custo;
  h->dados[h->tamanho].u = u;
  h->dados[h->tamanho].v = v;
  h->tamanho++;

  HeapifyPorBaixo(h, h->tamanho-1);
}

void HeapifyPorBaixo(Heap* h, int posicao){
  int posAncestral = GetAncestralPos(posicao);
  
  if(posAncestral >= 0){
    Aresta ancestral = GetAncestral(h, posicao);
    
    if(h->tamanho > 1 && ISBIGGER(ancestral.custo, h->dados[posicao].custo)){
      Aresta aux = h->dados[posicao];
      int ancestralPos = GetAncestralPos(posicao);
      
      h->dados[posicao] = ancestral;
      h->dados[ancestralPos] = aux;
      
      if(ancestralPos >= 0){
        HeapifyPorBaixo(h, ancestralPos);
      }
    }
  }
  
}

void HeapifyPorCima(Heap* h, int posicao){
  int direitoPos = GetSucessorDirPos(posicao);
  int esquerdoPos = GetSucessorEsqPos(posicao);

  Aresta esquerdo = GetSucessorEsq(h, posicao);
  Aresta direito = GetSucessorDir(h, posicao);

  int prox = -1;
  
  if(direitoPos < h->tamanho && ISSMALLER(direito.custo, esquerdo.custo) && ISBIGGER(h->dados[posicao].custo, direito.custo)){

    Aresta aux = h->dados[posicao];

    h->dados[posicao] = direito;
    h->dados[direitoPos] = aux;

    prox = direitoPos;
  }
  else if(esquerdoPos < h->tamanho && ISBIGGER(h->dados[posicao].custo, esquerdo.custo)){

    Aresta aux = h->dados[posicao];
    
    h->dados[posicao] = esquerdo;
    h->dados[esquerdoPos] = aux;
    
    prox = esquerdoPos;
  }

  if(prox != -1 && prox < h->tamanho){
    HeapifyPorCima(h, prox);
  }
  
}

int GetAncestralPos(int posicao){
  return (posicao - 1) / 2;
}
Aresta GetAncestral(Heap* h, int posicao){
  return h->dados[GetAncestralPos(posicao)];
}

int GetSucessorEsqPos(int posicao){
  return posicao * 2 + 1;
}
Aresta GetSucessorEsq(Heap* h, int posicao){
  return h->dados[GetSucessorEsqPos(posicao)];
}
int GetSucessorDirPos(int posicao){
  return posicao * 2 + 2;
}
Aresta GetSucessorDir(Heap* h, int posicao){
  return h->dados[GetSucessorDirPos(posicao)];
}

Aresta Remover(Heap* h){
  Aresta retorno = h->dados[0];
  // Colocando o último que foi adicionado na primeira posição
  h->dados[0] = h->dados[h->tamanho-1];
  h->tamanho--;
  
  HeapifyPorCima(h, 0);

  return retorno;
}