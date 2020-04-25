#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ITERS 10
#define DIM   128

int main(int argc, char *argv[]) {
  volatile int A[DIM][DIM], B[DIM][DIM], C[DIM][DIM], r;
  int i, j, k, n, imp;

  if (argc < 2) {
    printf("Specify algorithm {1=IJK, 2=KJI, 3=KIJ}\n");
    exit(1);
  } else {
    imp = atoi(argv[1]);
  }
  
  for (i=0; i<DIM*DIM; i++) {
    ((int *)A)[i] = (int)random();
    ((int *)B)[i] = (int)random();
  }

  for (n=0; n<ITERS; n++) {
    memset((void *)C, 0, DIM*DIM*sizeof(int));
    switch(imp) {
    case 1: /* IJK */
      for (i=0; i<DIM; i++) {
        for (j=0; j<DIM; j++) {
          for (k=0; k<DIM; k++) {
            C[i][j] += A[i][k] * B[k][j];
          }
        }
      }
      break;
    case 2: /* KJI */
      for (k=0; k<DIM; k++) {
        for (j=0; j<DIM; j++) {
          r = B[k][j];
          for (i=0; i<DIM; i++)
            C[i][j] += A[i][k]*r;
        }
      }
      break;
    case 3: /* KIJ */
      for (k=0; k<DIM; k++) {
        for (i=0; i<DIM; i++) {
          r = A[i][k];
          for (j=0; j<DIM; j++)
            C[i][j] += r*B[k][j];
        }
      }
    } /* end switch */
  }

  return 0;
}
