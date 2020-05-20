/*
 * Demonstrates:
 * - primitive integer types
 * - typecasts
 * - type conversion
 * - sizeof operator
 */

#include <stdio.h>

int main() {
  char  c  = 65;
  short s = 0x1234;
  int   i  = 'A',
        j  = 0x12345678,
        k  = 0xffffffff;
  unsigned int u = 0xffffffff;
  long int l = 0x12345678abcdef00;

  printf("%c, %d, %d, %d, %d, %u, %ld\n", c, s, i, j, k, u, l);

  printf("%ld, %ld, %ld, %ld\n", 
         sizeof(char), sizeof(short), sizeof(int), sizeof(long int));
}
