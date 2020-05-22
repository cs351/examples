/*
 * Demonstrates:
 * - preprocessor directives
 */

#include <stdio.h> // what does this really do?

#define GREETING "Hello world!\n"

#define PRINT_THE_GREETING printf(GREETING);

#define NTH_ODD(n) (n*2 + 1) // is this correct?

#define DEBUG // can also introduce with -D DEBUG 

#define VERSION 2 // can be set with -D VERSION=N

int main() {
  printf(GREETING);

  PRINT_THE_GREETING

  for (int i=0; i<10; i++) {
    #ifdef DEBUG
      printf("NTH_ODD(%d)=", i);
    #endif
    printf("%d ", NTH_ODD(i));
  }
  printf("\n");

  #if VERSION == 1
    printf("Thanks for playing!\n");
  #elif VERSION == 2
    printf("Toodaloo!\n");
  #else
    printf("Byeeeee\n");
  #endif

  return 0;
}
