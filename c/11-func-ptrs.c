/*
 * Demonstrates:
 * - function pointers
 */

#include <stdio.h>

int square(int x) {
  return x * x;
}

void map(int (*f)(int), int *arr, int n) {
  int i;
  for (i=0; i<n; i++) {
    arr[i] = (*f)(arr[i]);
  }
}

int main() {
  int i, arr[] = {1, 2, 3, 4, 5};

  map(square, arr, 5);
  
  for (i=0; i<5; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
