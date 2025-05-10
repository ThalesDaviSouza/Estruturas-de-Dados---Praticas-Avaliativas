#include <stdio.h>
#include <string.h>
#include "heap.h"


int main(int argc, char ** argv){
  int n, aux;
  Heap* h = NovoHeap(10);
  
  scanf("%d%*c", &n);
  
  for(int i = 0; i < n; i++){
    scanf("%d%*c", &aux);
    Inserir(h, aux);
  }

  for(int i = 0; i < n; i++){
    printf("%d ", Remover(h));
  }

  DeletaHeap(h);
  
  return 0;
}