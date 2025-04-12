#include <stdio.h>
#include "list.h"


int main() {
  struct List *l = createList();
  int x;
  while (scanf("%d", &x) == 1) {
    addToFront(l, x);
  }
  for (int i = 0; i < len(l); ++i) {
    printf("%d ", ith(l, i));
    setIth(l, i, ith(l, i)+1);
  }
  printf("\nSecond print of list\n");
  for (int i = 0; i < len(l); ++i) {
    printf("%d ", ith(l, i));
  }
  printf("\n");
  l = destroy(l);
}
