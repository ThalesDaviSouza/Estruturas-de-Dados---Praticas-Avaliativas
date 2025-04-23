#include "graph.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct s_grafo{
  List* nodes;
} Grafo;

Grafo* NovoGrafo(){
  Grafo* g = (Grafo*)malloc(sizeof(Grafo));
  g->nodes = NULL;
  return g;
}

void DeletaGrafo(Grafo* g){
  if(g->nodes != NULL){
    deleteList(g->nodes);
  }

  free(g);
}

int QuantidadeVertices(Grafo* g){
  int c = 0;
  List* aux = g->nodes;

  while (aux != NULL)
  {
    c++;
    aux = aux->next;
  }
  
  return c;
}

int QuantidadeArestas(Grafo* g){
  int numArestas = 0;
  int count = 0;

  List* aux = g->nodes;

  while(aux != NULL){
    List* node = aux->listValue; 
    
    while (node != NULL)
    {
      numArestas++;
      node = node->next;
    }
    
    aux = aux->next;
    
    count++;
  }

  // É um grafo com arestas bidirecionais,
  // ou seja, cada aresta está presente na lista
  // dos dois nós conectados. 
  // Assim, ao contar todos as arestas, chegamos no
  // dobro do número de arestas
  return numArestas/2;
}


int GrauMinimo(Grafo* g){
  int grauMin = 0;
  int count = 0;

  List* aux = g->nodes;

  while(aux != NULL){
    List* node = aux->listValue; 
    int numArestas = 0;
    
    while (node != NULL)
    {
      numArestas++;
      if(count != 0 && numArestas > grauMin){
        break;
      }
      node = node->next;
    }

    if(count == 0 || grauMin > numArestas){
      count++;
      grauMin = numArestas;
    }
    
    aux = aux->next;
  }

  return grauMin;
}

int GrauMaximo(Grafo* g){
  int grauMax = 0;
  int count = 0;

  List* aux = g->nodes;

  while(aux != NULL){
    List* node = aux->listValue; 
    int numArestas = 0;
    
    while (node != NULL)
    {
      numArestas++;
      node = node->next;
    }

    if(count == 0 || grauMax < numArestas){
      count++;
      grauMax = numArestas;
    }
    
    aux = aux->next;
  }

  return grauMax;
}

void InsereVertice(Grafo* g){
  int v = QuantidadeVertices(g);
  
  if(g->nodes == NULL){
    g->nodes = createList(TYPE_LIST, NULL, v);
  }
  else{
    addItem(g->nodes, NULL, v);
  }
}

// v = origem
// w = destino
void InsereAresta(Grafo* g, int v, int w){
  List* aux = g->nodes;
  int c = 0;

  while(c < v){
    c++;
    aux = aux->next;
  } 

  
  if(aux->listValue == NULL){
    aux->listValue = createList(TYPE_INT, NULL, w);
  }
  else{
    addItem(aux->listValue, NULL, w);
  }

}

void ImprimeVizinhos(Grafo* g, int v){
  List* aux = g->nodes;
  int c = 0;

  while(c < v){
    c++;
    aux = aux->next;
  } 

  printList(aux->listValue);
}
