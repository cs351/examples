/*
 * Demonstrates:
 * - pointer arithmetic
 */

#include <stdio.h>

int main() {
  unsigned int arr[] = 
    { 0x12345678, 0x23456789, 0x3456789a, 0x456789ab, 0x56789abc,
      0x6789abcd, 0x789abcde, 0x89abcdef, 0x9abcdef0, 0xabcdef01 };
      
  unsigned int    *p = &arr[0];
  unsigned short  *q = (short *)&arr[0];
  unsigned char   *r = (char *)&arr[0];

  for (int i=0; i<10; i++) {
    // access arr directly
    printf("%x ", arr[i]);

    // use p as an array (pointers behave like arrays)
    printf("%x ", p[i]);

    // access arr using pointer arithmetic via p
    printf("%x ", *(p + i));

    // use arr as a pointer
    printf("%x ", *(arr + i));

    // wrong pointer type!
    printf("%x ", *(q + i));

    // wrong pointer type!
    printf("%x ", *(r + i));

    printf("\n");
  }
  printf("\n");
}
