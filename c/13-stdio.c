/*
 * Demonstrates:
 * - file I/O and error handling
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
 
int main(int argc, char *argv[]) {
  FILE* fp;
  char buf[MAXLINE];
  
  if (argc == 3) {
    fp = fopen(argv[1], "r");
  } else {
    printf("USAGE: %s FILENAME SEARCH_STRING\n", argv[0]);
    return 1;
  }

  if (!fp) {
    perror("Could not open file");
    return 1;
  }

  while (fgets(buf, MAXLINE, fp)) {
    if (strstr(buf, argv[2])) {
      fputs(buf, stdout);
    }
  }

  fclose(fp);
}
