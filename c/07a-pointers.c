/*
 * Demonstrates:
 * - basic pointer operations
 */

#include <stdio.h>

int main() {
  int i, j, *p, *q;

  i = 10;
  p = &j;
  q = p;
  *q = i;
  *p = *q*2;

  printf("i=%d, j=%d, *p=%d, *q=%d\n", i, j, *p, *q);

  printf("&i=%p, &j=%p, p=%p, q=%p\n", &i, &j, p, q);

  return 0;
}
