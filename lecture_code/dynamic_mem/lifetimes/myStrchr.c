#include <stdio.h>
#include <stdlib.h>
char globalArr[] = "wowee";

char *my_strchr(const char *s, const char c) {
  // What section is the data s points at on?
  // Whatever section it was on when the client
  // programmer passed it to us...
  for (; *s; ++s) if (*s == c) return s;
  return NULL;
}



int main() {
  char arr[] = {'a', 'b', 'c', '\0'};
  // In this function call strchr will return
  // a pointer to a stack-allocated array. That's fine.
  // Because that array still exists when the function
  // returns to us, the caller.
  my_strchr(arr, 'b');
  char *p = malloc(sizeof(char)*6);
  p[0] = 'h';
  p[1] = 'e';
  p[2] = 'l';
  p[3] = 'l';
  p[4] = 'o';
  p[5] = '\0';
  // Here, the pointer strchr will return will be a pointer to
  // heap allocated data, because it's returning a pointer into the
  // array we gave it, and that array is allocated on the heap.
  my_strchr(p, 'l');
  free(p);
  // "blah" is a string literal, this means its somewhere in the text
  // or data section of our program depending on the implementation
  // So the pointer returned by it will be on either the text or data
  // section.

  // TECHNICALLY however, we shouldn't call my_strchr this way because
  // a string literal is a const char *, and when my_strchr returns
  // a pointer into that array it returns only a char * which discards the
  // const qualifier which if the caller decides then to mutate that data
  // through the pointer they will have an error.
  my_strchr("blah", 'l');

  // And in this case my_strchr is going to return a pointer to the
  // data section (since we gave it a pointer to the data section as that
  // is where our global data is stored)
  my_strchr(globalArr, 'e');
}
