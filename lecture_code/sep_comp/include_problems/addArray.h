#ifndef ADDARRAY_H_
#define ADDARRAY_H_

#include <stddef.h>

// This function takes two arrays of integers,
// that must be the same length
// and adds all the items in the src array to
// the items in the dest array (mutating the dest
// array)
// So at the end, if dest array is d_1, ... d_n
// and src array is s_1, ... s_n
// Then dest array becomes
// d_1+s_1, ..., d_n+s_n
int mutateAdd(int *dest, int *src, size_t len) {
  for (size_t i = 0; i < len; ++i) {
    dest[i] = dest[i] + src[i];
  }
}


#endif
