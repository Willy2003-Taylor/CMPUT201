#include <stddef.h>
void printArray(int *, size_t);

int main() {
  int arr[5] = {38, 28, 10, 38, -1};
  printArray(arr, sizeof(arr)/sizeof(arr[0]));
}
