#include <stdio.h>


int main() {
  int x = 100, y=2;
  while (x > y) {
    #ifdef DEBUG
    printf("x: %d, y: %d\n", x, y);
    #endif
    printf("%d\n", x*y);
    x = x + 10;
    y = y * 2;
  }
  #ifdef DEBUG
  printf("End\n");
  #endif

}
