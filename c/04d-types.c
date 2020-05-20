/*
 * Demonstrates:
 * - primitive integer types
 * - typedefs
 * - typecasts
 * - type conversion
 * - sizeof operator
 */

#include <stdio.h>

typedef char little_t;
typedef unsigned long size_t;

int main() {
  little_t a = 0x1a;
  size_t s = 0x12345678abcdef00;

  char c = a;
  unsigned long l = s;

  printf("%ld, %ld\n", sizeof(little_t), sizeof(size_t));
}
