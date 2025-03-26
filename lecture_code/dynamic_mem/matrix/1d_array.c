#include <stdio.h>
#include <stdlib.h>
int *simpleMatrix(int n, int m) {
  int *matrix = malloc(n*m*sizeof(int));
  // If malloc fails this function returns a null pointer
  if (!matrix) return NULL;
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      matrix[r*m+c] = r == c;
    }
  }
  return matrix;
}

int idx(int *matrix, int r, int c, int rowLength) {
  // Assumes that r and c are within the bounds
  // of the matrix! That is the caller's responsibility!
  return matrix[r*rowLength+c];
}

int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  int *id = simpleMatrix(n, m);
  for (int r = 0; r < n; ++r) {
    printf("| ");
    for (int c = 0; c < m; ++c) {
      printf("%d ", idx(id, r, c, m));
    }
    printf("|\n");
  }

  free(id);
}
