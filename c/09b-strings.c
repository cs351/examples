/*
 * Demonstrates:
 * - relationship between strings, arrays, and pointers
 */

#include <stdio.h>

void strcpy_v1(char dst[], char src[]) {
    int i=0;
    do {
        dst[i] = src[i];
    } while (src[i++] != '\0');
}

void strcpy_v2(char dst[], char src[]) {
    int i=0;
    while ((dst[i] = src[i]) != '\0')
        i++;
}

void strcpy_v3(char *dst, char *src) {
    while ((*dst = *src) != '\0') {
        dst++;
        src++;
    }
}

void strcpy_v4(char *dst, char *src) {
    while ((*dst++ = *src++) != '\0') ;
}

void strcpy_v5(char *dst, char *src) {
    while (*dst++ = *src++) ;
}

int main() {
  char buf1[] = "hello!";
  char buf2[sizeof(buf1)];

  strcpy_v1(buf2, buf1);
  printf("%s\n", buf2);
}
