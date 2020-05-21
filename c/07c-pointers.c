/*
 * Demonstrates:
 * - pointers to pointers (to pointers to ...)
 */

#include <stdio.h>

void swap(int *p, int *q) {
  int tmp = *p;
  *p = *q;
  *q = tmp;
}

int main() {
    int a=10, b=20, *pa=&a, *pb=&b;
    swap(pa, pb); // how to get this swap to work?
    printf("a=%d, b=%d, *pa=%d, *pb=%d\n", a, b, *pa, *pb);
    return 0;
}
