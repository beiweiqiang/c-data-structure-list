
#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <stdbool.h>

#define TSIZE 45

struct film {
  char title[TSIZE];
  int rating;
};

typedef struct film Item;

typedef struct node {
  Item item;
  struct node * next;
} Node;

typedef Node * List;

void InitializeList(List * plist);
bool ListIsEmpty(const List * plist);
bool ListIsFull(const List * plist);
unsigned int ListItemCount(const List * plist);
bool AddItem(Item item, List * plist);
void Traverse(const List * plist, void (*pfunc)(Item item));
void EmptyList(List * plist);

#endif //LIST_LIST_H
