#include <stdio.h>

// This is a forward declaration of function Foo
// Note that parameter names are not necessary in
// forward declarations, since they only have meaning
// in the function definition, since that is where they
// will be referenced.
void foo(int);
void bar(int);

void bar(int x) {
  if (x == 1) return;
  x = 3*x + 1;
  printf("%d\n", x);
  if (x % 2 == 0) foo(x);
  else bar(x);
}


void foo(int x) {
  x = x/2;
  printf("%d\n", x);
  if (x % 2 == 0) foo(x);
  else bar(x);
}


int main() {
  foo(6);
}
