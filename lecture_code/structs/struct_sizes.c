#include <stdio.h>

struct Rect {
  int x, y, w, h;
};

struct Foo {
  char c;
  int x;
};

struct Bar {
  char a, b, c, d;
  int x;
};

struct Baz {
  char a;
  int x;
  char b;
};

struct with8ByteType {
  int *p;
  char c;
};

int main() {
  printf("%lu\n", sizeof(struct Rect));
  printf("%lu\n", sizeof(struct Foo));
  printf("%lu\n", sizeof(struct Bar));
  printf("%lu\n", sizeof(struct Baz));
  printf("%lu\n", sizeof(struct with8ByteType));
}
