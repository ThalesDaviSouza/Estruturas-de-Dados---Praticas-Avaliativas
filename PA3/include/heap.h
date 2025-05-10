#ifndef HEAP_HPP
#define HEAP_HPP

#define TRUE (1 == 1)
#define FALSE (1 != 1)
#define ISBIGGER(x, y) (x > y ? TRUE : FALSE)
#define ISSMALLER(x, y) (x < y ? TRUE : FALSE)

typedef struct s_heap{
  int tamanho;
  int* dados;
} Heap;

Heap* NovoHeap(int maxsize);
void DeletaHeap(Heap* h);
void Inserir(Heap* h, int x);
int Remover(Heap* h);
int GetAncestralPos(int posicao);
int GetAncestral(Heap* h, int posicao);
int GetSucessorEsqPos(int posicao);
int GetSucessorEsq(Heap* h, int posicao);
int GetSucessorDirPos(int posicao);
int GetSucessorDir(Heap* h, int posicao);

//Retorna 1 caso h esteja vazio, 0 caso contrário.
int Vazio(Heap* h);

//Funções necessárias para implementar o Heapify recursivo
void HeapifyPorBaixo(Heap* h, int posicao);
void HeapifyPorCima(Heap* h, int posicao);

#endif