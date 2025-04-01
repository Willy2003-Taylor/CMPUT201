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


void tailRecursiveDestroyNodes(struct Node *n) {
  if (!n) return;
  struct Node *next = n->next;
  free(n);
  tailRecursiveDestroyNodes(next);
  // This function is tail recursive, there is no work to be done by
  // the original call after the recursion completes, as such a good compiler
  // may optimize away the additional stackframes.
}

void destroyNodes(struct Node *n) {
  // We'll continue improving this function next class
  if (!n) return; // If n is the null pointer we're done
  destroyNodes(n->next);
  free(n);
  // I do not like this function because it's not tail recursive.
  // The recursive call must return here because we still have work to do
  // i.e. free the original node n.

}

struct List *destroyList3(struct List *l) {
  struct Node *cur = l->head;
  while (cur) {
    struct Node *next = cur->next;
    free(cur);
    cur = next;
  }
  free(l);
}

struct List *destroyList2(struct List *l) {
  tailRecursiveDestroyNodes(l->head);
  free(l);
  return NULL;
}

struct List *destroyList1(struct List *l) {
  // This function cleans up all memory associated with
  // a list that was created with our createList function
  // and manipulated through our provided interface
  // e.g. addToFront and all the other fns we'll write
  destroyNodes(l->head);
  free(l);
  return NULL;
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
  l = destroyList2(l);
}

