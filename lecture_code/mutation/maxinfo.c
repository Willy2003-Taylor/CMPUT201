#include <stdio.h>
#include <assert.h>

float maxInfo(float *arr, int len, int *indLocation) {
  assert(len > 0);
  // This function takes an array of floats and returns both
  // the maximal item as well as the index of the maximal item
  float maxSoFar = arr[0];
  int ind = 0;
  for (int i = 0; i < len; ++i) {
    if (arr[i] > maxSoFar) {
      maxSoFar = arr[i];
      ind = i;
    }
  }
  *indLocation = ind;
  return maxSoFar;
}


int main() {
  float arr[] = {1.0, -1.0, 43284.234, -2.0};
  int ind;
  float max = maxInfo(arr,  4, &ind);
  printf("%f\n", max);
  printf("%d\n", ind);
}
