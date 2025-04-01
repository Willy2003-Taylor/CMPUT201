#include <stdio.h>
#include <stdlib.h>

struct List {
  int len, cap;
  int *arr;
};

void push(struct List *l, int elem) {
  // Adds to the back of the array, growing as necessary
  if (l->len == l->cap) {
    int *newArr = malloc(sizeof(int)*l->cap*2);
    for (int i = 0; i < l->len; ++i) newArr[i] = l->arr[i];
    l->cap = l->cap*2;
    free(l->arr);
    l->arr = newArr;
  }
  l->arr[l->len++] = elem;
}

int pop(struct List *l) {
  // Removes the item from the back of our growing
  // array and returns that integer
  return l->arr[--l->len];
}

int main() {
  struct List l = {.len=0, .cap = 4, .arr = malloc(sizeof(int)*4)};
  int x;
  while (scanf("%d", &x) == 1) {
    // This should all be a function, I should be able to easily
    // say
    push(&l, x); // Add to the back of my array, growing if necessary
  }
  for (int i = 0; i < l.len; ++i) {
    printf("%d ", l.arr[i]);
  }
  printf("\n");
  free(l.arr);

}
