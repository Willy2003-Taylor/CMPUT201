#ifndef DOUBLEARRAY_H_
#define DOUBLEARRAY_H_

#include <stddef.h>
#include "addArray.h"
void doubleArray(int *arr, size_t len) {
  // This takes an array and the len of that array
  // and doubles all the items in that array (mutating it)
  mutateAdd(arr, arr, len);
}

#endif
