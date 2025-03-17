#include <stdio.h>
#include <string.h>

char *zipStrings(const char *s1, const char *s2) {
  // Takes two string parameters s1 and s2 of the same length
  // and returns a new heap allocated string that is the result of
  // "zipping" the two strings together.
  // e.g. zipStrings("abc", "xyz") -> "axbycz"
}


int main() {
  char s1[256];
  char s2[256];
  scanf("%s", &s1);
  scanf("%s", &s2);
  char *p = zipStrings(s1, s2);
  printf("%s\n", p);
  free(p);
}
