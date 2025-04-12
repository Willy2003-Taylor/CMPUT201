#include <stddef.h>
void printArray(int *, size_t, char);

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6};
  for (int i = 0; i < 6; ++i) {
    printArray(arr+i, 6-i, '\n');
  }
}
