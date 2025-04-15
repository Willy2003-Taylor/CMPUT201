#include <stdio.h>

int main() {
  FILE *f = fopen("myFile.txt", "a");
  fprintf(f, "This is a line appended\n");
  fseek(f, 0, SEEK_SET);
  fprintf(f, "Another line\n");
  fclose(f);
}
