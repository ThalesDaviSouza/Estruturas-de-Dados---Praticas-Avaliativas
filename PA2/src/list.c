#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List* createList(VarType type, List* listValue, int intValue){
  List* node = (List*)malloc(sizeof(List));

  node->intValue = intValue;
  node->listValue = listValue;
  node->type = type;
  node->next = NULL;
  
  return node;
}

void addItem(List* head, List* listValue, int intValue){
  List* newNode = createList(head->type, listValue, intValue);
  List* aux = head;

  while(aux->next != NULL){
    aux = aux->next;
  }

  aux->next = newNode;
}

void printList(List* head){
  List* aux = head;

  while (aux != NULL)
  {
    if(aux->type == TYPE_LIST){
      printList(aux->listValue);
    }
    else if(aux->type == TYPE_INT){
      printf("%d ", aux->intValue);
    }
    aux = aux->next;
  }
  printf("\n");
}

void deleteList(List* head){
  if(head->next != NULL){
    deleteList(head->next);  
  }
  
  if(head->type == TYPE_LIST && head->listValue != NULL){
    deleteList(head->listValue);
  }
  free(head);
}

