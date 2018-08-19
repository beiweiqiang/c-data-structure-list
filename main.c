#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/list.h"

void link_test();
void show(Item item);

int main() {
  link_test();
  return 0;
}

void link_test() {
  List list;
  Item tmp;

  InitializeList(&list);
  strcpy(tmp.title, "he an qi");
  tmp.rating = 1;

  AddItem(tmp, &list);
  AddItem(tmp, &list);
  AddItem(tmp, &list);

  printf("%d \n", ListItemCount(&list));
  EmptyList(&list);

  Traverse(&list, show);
}

void show(Item item) {
  printf("%s %d \n", item.title, item.rating);
}