/*
 * Demonstrates:
 * - pass-by-value
 * - swap for structs
 * - arrow (->) notation
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct point {
  int x;
  int y;
};

typedef struct point point_t;

void swap(point_t p1, point_t p2) {
  int tmp_x = p1.x,
      tmp_y = p1.y;
  p1.x = p2.x;
  p1.y = p2.y;
  p2.x = tmp_x;
  p2.y = tmp_y;
}

int main() {
  point_t parr[100];

  for (int i=0; i<100; i++) {
    parr[i].x = parr[i].y = i;
  }

  srand(time(NULL));
  for (int i=0; i<10000; i++) {
    int j = rand() % 100,
        k = rand() % 100;
    swap(parr[j], parr[k]);
  }

  for (int i=0; i<100; i++) {
    printf("(%d,%d) ", parr[i].x, parr[i].y);
  }
  printf("\n");
}
