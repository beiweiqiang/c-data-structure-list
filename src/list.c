#include <stdlib.h>
#include "../include/list.h"

static void cp_to_node(Item item, Node * pnode);

void InitializeList(List * plist) {
  *plist = NULL;
}

bool ListIsEmpty(const List * plist) {
  if (*plist == NULL) {
    return true;
  } else {
    return false;
  }
}

bool ListIsFull(const List * plist) {
  // 新建一个 Node 指针, 看能否给他分配空间
  Node *pt;
  bool full;
  pt = (Node *) malloc(sizeof(Node));
  if (pt == NULL) {
    full = true;
  } else {
    full = false;
  }
  free(pt);
  return full;
}

unsigned int ListItemCount(const List * plist) {
  unsigned int count = 0;

  // plist 是一个指向 list 的指针
  // *plist 取到 List 类型
  // 因为 typedef Node * list
  // 所以 list 的类型为 Node *
  Node * pnode = *plist;

  while (pnode != NULL) {
    count++;
    pnode = pnode->next;
  }
  return count;
}

bool AddItem(Item item, List * plist) {
  Node * pnew;
  Node *scan = *plist;
  pnew = (Node *) malloc(sizeof(Node));
  if (pnew == NULL) {
    return false;
  }
  cp_to_node(item, pnew);
  pnew->next = NULL;
  // scan 是一个指针, 指向 List
  // scan 的类型是 Node *
  if (scan == NULL) {
    *plist = pnew;
  } else {
    while (scan->next != NULL) {
      scan = scan->next;
    }
    scan->next = pnew;
  }
  return true;
}
void Traverse(const List * plist, void (*pfunc)(Item item)) {
  Node * pnode = *plist;
  while (pnode != NULL) {
    (*pfunc)(pnode->item);
    pnode = pnode->next;
  }
}

void EmptyList(List * plist) {
  Node * psave;
  while (*plist != NULL) {
    psave = (*plist)->next;
    free(*plist);
    *plist = psave;
  }
}

static void cp_to_node(Item item, Node * pnode) {
  pnode->item = item;
}