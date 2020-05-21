/*
 * Demonstrates:
 * - pass by value and passing addresses for "action at a distance"
 */

#include <stdio.h>

void swap(int x, int y) {
  int tmp = x;
  x = y;
  y = tmp;
}

int main() {
    int a=10, b=20;
    swap(a, b); // how to get this swap to work?
    printf("a=%d, b=%d\n", a, b);
    return 0;
}
