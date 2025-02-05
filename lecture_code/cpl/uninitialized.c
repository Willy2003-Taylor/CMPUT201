#include <stdio.h>

int foo(int x) {
  if (x <= 0) {
    return -32;
  }
  return foo(x - 2);
}

int blah() {
  int z;
  printf("z: %d\n", z);
}

int main() {
  // WARNING! x and y are uninitialized! To read their values
  // before setting them is UNDEFINED BEHAVIOUR, that is an ERROR!
  // You may get lucky and it works the way you want on some machines,
  // But there is no guarantee of that, and other changes to your program
  // could change that!

  // Look at the value printed by blah of z first and second!
  blah();
  int x;
  printf("%d\n", x);
  foo(24);
  int y;
  printf("%d\n", y);
  blah();
  /*
  This is a multi line comment
  Preferably, for beauty's sake, each line should start with
  an asterisk in line with the other ones. It just looks pretty.
  I haven't done here though so you don't think you /need/ to.
  */

  /*
   * This is a multi-line comment that looks pretty
   * It's much nicer when they all have asterisks
  */
}
