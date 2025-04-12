#include "printArray.h"
#include "doubleArray.h"
#include "addArray.h"

int main() {
  int a1[] = {1, 2, 3};
  int a2[] = {2, 2, 2,};
  doubleArray(a2, 3);
  mutateAdd(a1, a2, 3);
  printArray(a1, 3, '\n');
  printArray(a2, 3, '\n');
}
