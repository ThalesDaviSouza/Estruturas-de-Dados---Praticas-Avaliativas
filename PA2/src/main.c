#include <stdio.h>
#include <string.h>
#include "graph.h"


int main(int argc, char ** argv){
  char* c = argv[1];
  Grafo* g = NovoGrafo();
  int vertices;

  scanf("%d%*c", &vertices);

  for(int i = 0; i < vertices; i++){
    int qtdArestas;
    scanf("%d%*c", &qtdArestas);
    
    InsereVertice(g);
    for(int j = 0; j < qtdArestas; j++){
      int w;
      scanf("%d%*c", &w);
      InsereAresta(g, i, w);
    }
  }
  
  // Verificar se um grafo é completo
  if(strcmp(c, "-k") == 0){
    int qtdVertices = QuantidadeVertices(g);
    int qtdArestas = QuantidadeArestas(g);
    int isCompleto = (qtdArestas*2 == (qtdVertices * (qtdVertices-1))) ? 1 : 0;

    printf("%d", isCompleto);
  }
  else if(strcmp(c, "-d") == 0){
    printf("%d\n", QuantidadeVertices(g));
    printf("%d\n", QuantidadeArestas(g));
    printf("%d\n", GrauMinimo(g));
    printf("%d\n", GrauMaximo(g));
  }
  else if(strcmp(c, "-n") == 0){
    int qtdVertices = QuantidadeVertices(g);

    for(int i = 0; i < qtdVertices; i++){
      ImprimeVizinhos(g, i);
    }
  }

  DeletaGrafo(g);

  return 0;
}