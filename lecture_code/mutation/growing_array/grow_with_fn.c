#include <stdio.h>
#include <stdlib.h>

void push(int **arr, int *len, int *cap, int elem) {
  // Adds to the back of the array, growing as necessary
  if (*len == *cap) {
    int *newArr = malloc(sizeof(int)**cap*2);
    for (int i = 0; i < *len; ++i) newArr[i] = (*arr)[i];
    *cap = *cap*2;
    free(*arr);
    *arr = newArr;
  }
  (*arr)[(*len)++] = elem;
}

int main() {
  int len = 0;
  int cap = 4;
  int *arr = malloc(sizeof(int)*cap);
  int x;
  while (scanf("%d", &x) == 1) {
    // This should all be a function, I should be able to easily
    // say
    push(&arr, &len, &cap, x); // Add to the back of my array, growing if necessary
  }
  for (int i = 0; i < len; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  free(arr);

}
