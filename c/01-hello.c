/*
 * Demonstrates:
 * - main function (first point of entry)
 * - include directive
 * - simple functions (declaration & definition)
 * - formatted output (printf)
 */

#include <stdio.h>

void say_hello(char *);

int main() {
  say_hello("world");
  return 0;
}

void say_hello(char *name) {
  printf("Hello %s!\n", name);
}
