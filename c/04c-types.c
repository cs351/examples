/*
 * Demonstrates:
 * - primitive integer types
 * - typecasts
 * - type conversion
 * - sizeof operator
 */

#include <stdio.h>
#include <sys/types.h>

int main() {
  int8_t c = 'a';
  int16_t s = 0x1234;
  int32_t i = 0x12345678;
  u_int32_t u = 0xffffffff;
  u_int64_t b = 0x12345678abcdef00;

  printf("%ld, %ld, %ld, %ld, %ld\n", 
         sizeof(int8_t), sizeof(int16_t), sizeof(int32_t), 
         sizeof(u_int32_t), sizeof(u_int64_t));
}
