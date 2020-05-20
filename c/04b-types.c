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

  c = (char)s;
  s = (short)j;
  u = (unsigned int)l;
  l = k;

  printf("%x, %x, %x, %lx\n", c, s, u, l);
  
}
