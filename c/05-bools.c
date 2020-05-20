/*
 * Demonstrates:
 * - "boolean" values
 */

#include <stdio.h>

int main() {
  printf( 0       ? "True\n":"False\n");
  printf( NULL    ? "True\n":"False\n");
  printf( (2+4-6) ? "True\n":"False\n");
  printf( '\0'    ? "True\n":"False\n");

  printf( 1       ? "True\n":"False\n");
  printf( -123    ? "True\n":"False\n");
  printf( 0xabcd  ? "True\n":"False\n");
  printf( 1+2+3   ? "True\n":"False\n");

  printf("%d\n", !0          );
  printf("%d\n", 0 || 2      );
  printf("%d\n", 3 && 0 && 6 );
  printf("%d\n", !(1234)     );
  printf("%d\n", !!(-1020)   );
}
