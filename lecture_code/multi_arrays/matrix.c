#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  int **matrix = malloc(n*(sizeof(int *)));
  for (int i = 0; i < n; ++i) {
    int *row = malloc(m*sizeof(int));
    for (int j = 0; j < m; ++j) {
      /*
      if (i == j) row[j] = 1;
      else row[j] = 0;
      */
      // condExpr ? exprIfTrue : exprIfFalse
      // is the format of the ternary operator.
      // it is an operator that evaluates to exprIfTrue if
      // condExpr is true, evaluates to exprIfFalse otherwise
      row[j] = i == j ? 1 : 0;
      // Note: in this case, the ternary is overkill, since the evaluation
      // of a boolean operator will evaluate to 0 if false 1 if true we could
      // just say row[j] = i == j;
    }
    matrix[i] = row;
  }
  for (int i = 0; i < n; ++i) printArray(matrix[i], m);

  // Since the pointers in matrix are the only place we have stored
  // the address of these heap-allocated arrays of integers, we must make sure
  // to free them before freeing matrix, since if we free matrix it would be
  // undefined behaviour to access the pointers within (since matrix itself would
  // be a dangling pointer), and as such we would have lost ALL of our pointers
  // to our heap allocated memory, which is a memory leak.
  for (int i = 0; i < n; ++i) free(matrix[i]);
  free(matrix);
}
