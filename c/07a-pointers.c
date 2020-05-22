/*
 * Demonstrates:
 * - pointer declarations
 * - basic pointer-related operations: & (address-of), * (dereference)
 */

#include <stdio.h>

int main() {
  int i;
  int j;
  int *p; 
  int *q;

  printf("%ld, %ld\n", sizeof(i), sizeof(p));

  i = 10;
  p = &j;
  q = p;
  *q = i;
  *p = *q*2;

  printf("i=%d, j=%d, *p=%d, *q=%d\n", i, j, *p, *q);

  printf("&i=%p, &j=%p, p=%p, q=%p\n", &i, &j, p, q);

  return 0;
}
