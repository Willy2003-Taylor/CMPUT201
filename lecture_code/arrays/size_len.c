#include <stdio.h>

int main() {
  int arr[7] = {1, 2, 3, 4, 5, 42, 33};
  unsigned int len = sizeof(arr)/sizeof(arr[0]);
  for (unsigned int i = 0; i < len; ++i) {
      printf("%d ", arr[i]);
  }
  printf("\n");
}
