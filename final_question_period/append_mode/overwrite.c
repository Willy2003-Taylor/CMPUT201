#include <stdio.h>

int main() {
  FILE *f = fopen("overwriteMe.txt", "w");
  fprintf(f, "This is this water\n");
  fprintf(f, "this is the well\n");
  fprintf(f, "Drink deep, and descend\n");
  fclose(f);
}
