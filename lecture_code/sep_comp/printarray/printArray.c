#include <stdio.h>

void printArray(int *arr, size_t size, char end) {
  if (!size) return;
  printf("%d", arr[0]);
  for (size_t i = 1; i < size; ++i) {
    printf(" %d", arr[i]);
  }
  if (end) {
    printf("%c", end);
  }
}
