#ifndef HEAP_HPP
#define HEAP_HPP

#include "unionFind.h"

#define TRUE (1 == 1)
#define FALSE (1 != 1)
#define ISBIGGER(x, y) (x > y ? TRUE : FALSE)
#define ISSMALLER(x, y) (x < y ? TRUE : FALSE)

typedef struct s_heap{
  int tamanho;
  Aresta* dados;
} Heap;

Heap* NovoHeap(int maxsize);
void DeletaHeap(Heap* h);
void Inserir(Heap* h, int u, int v, int custo);
Aresta Remover(Heap* h);
int GetAncestralPos(int posicao);
Aresta GetAncestral(Heap* h, int posicao);
int GetSucessorEsqPos(int posicao);
Aresta GetSucessorEsq(Heap* h, int posicao);
int GetSucessorDirPos(int posicao);
Aresta GetSucessorDir(Heap* h, int posicao);

//Retorna 1 caso h esteja vazio, 0 caso contrário.
int Vazio(Heap* h);

//Funções necessárias para implementar o Heapify recursivo
void HeapifyPorBaixo(Heap* h, int posicao);
void HeapifyPorCima(Heap* h, int posicao);

#endif