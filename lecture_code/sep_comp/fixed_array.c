#include <stdio.h>
// One common use of preprocessor constants is as the length of an statically sized array (known at compile time).
int main() {
  int arr[SIZE];
  arr[0] = 2;
  for (int i = 1; i < SIZE; ++i) {
    arr[i] = arr[i-1] + 2;
  }
  for (int i = 0; i < SIZE ;++i) {
    printf("%d\n", arr[i]);
  }
}
