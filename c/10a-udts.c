/*
 * Demonstrates:
 * - struct definition and usage
 */

#include <stdio.h>
#include <math.h>

struct point {
  int x;
  int y;
};

double dist(struct point p1, struct point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
  struct point a = { .x = 1, .y = 1 },
               b = { .x = 4, .y = 5 };
  printf("%0.5f\n", dist(a, b));
}
