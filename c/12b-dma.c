/*
 * Demonstrates:
 * - higher order function "filter"
 * - need for dynamic memory allocation
 * - malloc API
 * - void/generic pointers
 * - memory leaks
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int filter(int (*pred)(char *), char *arr[], int n, char ***rarr) {
  char *filtered[n];
  int count = 0;
  for (int i=0; i<n; i++) {
    if (pred(arr[i])) {
      filtered[count++] = arr[i];
    }
  }

  if (count > 0) {
    char **ret = malloc(count * sizeof(char *));
    for (int i=0; i<count; i++) {
      ret[i] = filtered[i];
    }
    *rarr = ret;
  }
  return count;
}

int palindromic(char *str) {
  int lo = 0,
      hi = strlen(str)-1;
  while (lo < hi) {
    if (str[lo++] != str[hi--]) {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char *argv[]) {
  char **palindromes;

  int n = filter(palindromic, argv, argc, &palindromes);
  
  printf("Palindromes: ");
  for (int i=0; i<n; i++) {
    printf("%s ", palindromes[i]);
  }
  printf("\n");

  if (n>0) {
    free(palindromes);
  }

  return 0;
}
