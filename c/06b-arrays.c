/*
 * Demonstrates:
 * - arrays as arguments
 */

#include <stdio.h>

void foo(int argarr[]) {
  printf("%ld\n", sizeof(argarr));
}

int main() {
  int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  printf("%ld %ld %ld\n", sizeof(arr), sizeof(int), 
                          sizeof(arr) / sizeof(int));

  foo(arr);
}
