/*
 * Demonstrates:
 * - pointer arithmetic
 * - array/pointer relationship
 * - row-major array ordering
 */

#include <stdio.h>

int main() {
  int arr2d[3][3] = { {1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9} };
  int *p = (int *)arr2d;
  for (int i=0; i<9; i++) {
    printf("%d ", *(p + i));
  }
  printf("\n");
}
