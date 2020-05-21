/*
 * Demonstrates:
 * - array declaration and initialization
 * - names as addresses (inspect with gdb)
 */

#include <stdio.h>

int main() {
  int  i_arr[10];       /* array of 10 ints */
  char c_arr[80];       /* array of 80 chars */
  char td_arr[24][80];  /* 2-D array, 24 rows x 80 cols */
  int  *ip_arr[10];     /* array of 10 pointers to ints */

  /* dimension can be inferred if initialized when declaring */
  short grades[] = { 75, 90, 85, 100 };

  /* a string is an array of characters terminated by a '\0' */
  char str1[] = {'h', 'e', 'l', 'l', 'o', '\0'};
  char str2[] = "hello";

  /* can only omit first dim, as partial initialization is ok */
  int sparse[][10] = { { 5, 3, 2 },
                       { 8, 10 },
                       { 2 } };

  /* if partially initialized, remaining components are 0 */
  int zeros[1000] = { 0 };

  /* can also use designated initializers for specific indices*/
  int nifty[100] = { [0]  = 0,
                     [99] = 1000,
                     [49] = 250 };
}
