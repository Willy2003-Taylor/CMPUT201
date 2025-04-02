#inclue <stdio.h>

void foo(int x) {
  x = x/2;
  printf("%d\n", x);
  if (x % 2 == 0) foo(x);
  else bar(x);
}

void bar(int x) {
  inf (x == 1) return;
  x = 3*x + 1;
  printf("%d\n", x);
  if (x % 2 == 0) foo(x);
  else bar(x);
}

int main() {
  foo(6);
}
