/*
 * Demonstrates:
 * - global and static vars
 */

#include <stdio.h>

int glob = 0;

void f1() {
  printf("In f1, glob=%d\n", glob);
  glob++;
}

void f2() {
  printf("In f2, glob=%d\n", glob);
  glob++;
}

void f3() {
  int x = 0;
  printf("In f3, x=%d\n", x);
  x++;
}

void f4() {
  static int x = 0;
  printf("In f4, x=%d\n", x);
  x++;
}

int main() {
  f1();
  f2();
  f1();
  f2();
  f1();
  f2();

  f3();
  f4();
  f3();
  f4();
  f3();
  f4();
  return 0;
}
