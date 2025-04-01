#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};

struct List {
  struct Node *head;
  size_t len;
};


struct List *createList() {
  struct List *ret = malloc(sizeof(struct List));
  ret->head = NULL;
  ret->len = 0;
  return ret;
}

void addToFront(struct List *l, int elem) {
  struct Node *newHead = malloc(sizeof(struct Node));
  newHead->data = elem;
  newHead->next = l->head;
  l->head = newHead;
}

int main() {
  struct List *l = createList();
  int x;
  while (scanf("%d", &x) == 1) {
    addToFront(l, x);
  }
  // This loop to access the items of our list is very common
  // This is how one iterates over a linked list.
  // But... if is this a true ADT then? NO! The client programmer
  // needs to know about the existence of Nodes which they should
  // only about the ADT list, they also need to know that NULL marks
  // the end of our list. Those are implementation details!
  for (struct Node *cur = l->head; cur; cur = cur->next) {
    printf("%d\n", cur->data);
  }
  // Note whne reading through this program, it is incomplete, we have a
  // a memory leak of all of our nodes and our list because we never free them.
}

