#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readString() {

}

int main() {
  char *p;
  while (p=readString()) {
    printf("%s\n", p);
    free(p);
  }
}
