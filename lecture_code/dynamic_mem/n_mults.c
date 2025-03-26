#include <stdio.h>
int *multiples(int);
int fib(int);
int main() {
  int *fives = multiples(5);
  printf("%p\n", fives);
  for (int i = 0; i < 4; ++i) printf("%d ", fives[i]);
  printf("\n");
  int *sevens = multiples(7);
  for (int i = 0; i < 4; ++i) {
    printf("sevens[%d]: %d\n", i, sevens[i]);
  }

  for (int i = 0; i < 4; ++i) {
    printf("fives[%d]: %d\n", i, fives[i]);
  }
  int fibEight = fib(8);
  for (int i = 0; i < 4; ++i) {
    printf("fives[%d]: %d\n", i, fives[i]);
    printf("sevens[%d]: %d\n", i, sevens[i]);
  }
}

int *multiples(int n) {
  // We want to return an array of 4 ints, the first 4 multiples
  // of n
  // e.g. if n is 7, then we return the array {7,14,21,28}
  int arr[4];
  for (int i = 0; i < 4; ++i) {
    arr[i] = (i+1)*n;
  }
  return arr;
}
int fib(int n) {
  if (n == 0) return 1;
  if (n == 1) return 1;
  return fib(n-1) + fib(n-2);
}
