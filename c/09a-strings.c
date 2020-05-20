/*
 * Demonstrates:
 * - relationship between strings, arrays, and pointers
 */

#include <stdio.h>

int main() {
  char *str = "str points to an read-only (static) string";
  char arr[] = "arr is a copy of the read-only string (so can be changed)";

  char sarr1[][5] = {"max", "of", "four"};
  char *sarr2[]   = {"variable", "length", "strings"};

  str[0] = 'a';
  arr[0] = 'b';

  printf("%ld\n", sizeof(sarr1));
  printf("%ld\n", sizeof(sarr2));
}
