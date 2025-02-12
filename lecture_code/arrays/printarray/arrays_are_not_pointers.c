#include <stdio.h>

int main() {
  int arr[4] = {1, 2, 3, 4};
  int *p = arr;
  printf("sizeof(arr): %lu\n", sizeof(arr));
  printf("sizeof(p): %lu\n", sizeof(p));
  printf("p: %p\n", p);
  printf("arr: %p\n", arr);
  printf("&p: %p\n", &p);
  printf("&arr: %p\n", arr);
}
