#include <stdio.h>
#include <math.h>

struct point {
  int x;
  int y;
};

typedef struct point point_t;

double dist(point_t p1, point_t p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
  point_t a = { .x = 1, .y = 1 },
          b = { .x = 4, .y = 5 };
  printf("%0.5f\n", dist(a, b));
}
