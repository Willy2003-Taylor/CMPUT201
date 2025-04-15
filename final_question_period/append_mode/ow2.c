#include <stdio.h>

int main() {
  FILE *f = fopen("overwriteMe.txt", "w");
  fprintf(f, "This is this water\n");
  fprintf(f, "this is the well\n");
  fseek(f, 0, SEEK_SET); // Reset to the beginning of the file
  fprintf(f, "Drink deep, and descend");
  fclose(f);
}
