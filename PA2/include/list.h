#ifndef LIST_H
#define LIST_H

typedef enum {
  TYPE_INT,
  TYPE_LIST
} VarType;

typedef struct s_list{
  VarType type;
  int intValue;
  struct s_list* listValue;
  struct s_list* next;
} List;

List* createList(VarType type, List* listValue, int intValue);
void addItem(List* head, List* listValue, int intValue);
void printList(List* head);
void deleteList(List* head);

#endif