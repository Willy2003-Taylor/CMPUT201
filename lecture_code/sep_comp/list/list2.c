#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct List {
  int len, cap;
  int *arr;
};


struct List *createList() {
  struct List *ret = malloc(sizeof(struct List));
  ret->len = 0;
  ret->cap = 4;
  ret->arr = malloc(sizeof(int)*4);
  return ret;
}

void addToFront(struct List *l, int elem) {
  if (l->len == l->cap) {
    int *newArray = malloc(sizeof(int)*l->cap*2);
    for (int i = 0; i < l->len; ++i) {
      newArray[i] = l->arr[i];
    }
    free(l->arr);
    l->arr = newArray;
    l->cap = l->cap*2;
  }
  l->arr[l->len++] = elem;
}

int pop(struct List *l, int i) {
  // The index in our array we want to remove
  // is actually len - 1 - i;
  int ind = l->len - 1 - i;
  int ret = l->arr[ind];
  for (int j = ind; j < l->len-1; ++j) {
    l->arr[j] = l->arr[j+1];
  }
  --l->len;
  return ret;
}

int len(struct List *l) {
  return l->len;
}

struct List *destroy(struct List *l) {
  free(l->arr);
  free(l);
  return NULL;
}

int ith(struct List *l, int i) {
  int ind = l->len - i - 1;
  return l->arr[ind];
}

void setIth(struct List *l, int i, int elem) {
  int ind = l->len - i - 1;
  l->arr[ind] = elem;
}

